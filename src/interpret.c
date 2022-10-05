#include "interpret.h"

static jmp_buf endingJmpBuf;

interpret_state_t interpret_statements_(void *stmt, PROVIDE_CONTEXT_ARGS(), argsList_t *args,
                                        hashtable_t *argVals) {
  locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  class_t *classCtx = PROVIDE_CONTEXT()->classCtx;
  int *interactive = PROVIDE_CONTEXT()->interactive;
  int32_t *ax = PROVIDE_CONTEXT()->ax;
  entity_eval_t *eval;
  void *next = NULL;
  ctx_table_t *ctx = ast_emalloc(sizeof(ctx_table_t));

  /* Initialize the context */
  memset(ctx, 0, sizeof(ctx_table_t));

  while (stmt != NULL) {
    eval = (entity_eval_t *)stmt;

    switch (eval->entity) {
      case LANG_ENTITY_DECL:
      case LANG_ENTITY_FUNCDECL:
      case LANG_ENTITY_FUNCCALL:
      case LANG_ENTITY_CONDITIONAL:
      case LANG_ENTITY_SYSTEM:
      case LANG_ENTITY_EXPR:
      case LANG_ENTITY_CLASSDECL:
      case LANG_ENTITY_FOREACH:
        next = ((statement_t *)stmt)->next;
        break;
      case LANG_ENTITY_RETURN:
        next = NULL;
        break;
      case LANG_ENTITY_BODY: {
        next = ((body_t *)stmt)->content;
        ctx->sp[ctx->depth] = varLocals->sp;
        ctx->sb[ctx->depth] = varLocals->sb;
        ctx->depth++;
        ctx->start[ctx->depth] = ctx->start[ctx->depth - 1];
        ctx->end[ctx->depth] = ctx->end[ctx->depth - 1];
        ctx->ctxDepth[ctx->depth] = ctx->ctxDepth[ctx->depth - 1];
        stmt = next;
        continue;
      } break;
      case LANG_ENTITY_BODY_END: {
        ctx->depth--;
        next = ctx->bodyEnd[ctx->depth];
        varLocals->sp = ctx->sp[ctx->depth];
        varLocals->sb = ctx->sb[ctx->depth];
        stmt = next;
        continue;
      } break;
      case LANG_ENTITY_FIN: {
        /* Free context */
        free(ctx);
        /* Jump to VM shutdown */
        longjmp(endingJmpBuf, 1);
      } break;
      default:
        break;
    }

    switch (eval->entity) {
      case LANG_ENTITY_DECL: {
        stackval_t sv;
        expr_t *id;
        heapval_t *hvp = NULL;
        declaration_t *decl = ((statement_t *)stmt)->content;
        id = decl->id;

        switch (id->type) {
          case EXPR_TYPE_ID: {
            int heapUpdated;
            heapval_t *globalCheck = NULL;
            heapval_t *classCheck = NULL;
            char *idStr = id->id.id;
            int stop = 0;

            /* Evaluating the expression among global variables */
            evaluate_expression(decl->val, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            /* Placing value on the heap */
            if (sv.type == TEXT) {
              /* Special case */
              char *c = sv.t;
              size_t len = strlen(c) + 1;
              char *newText = ast_emalloc(len);
              snprintf(newText, len, "%s", c);
              sv.t = newText;
            } else if (sv.type == VECTORTYPE) {
              expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
              sv.vec = e->vec;
              free(e);
            } else if (sv.type == DICTTYPE) {
              dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
              sv.dict = dict;
            } else if (sv.type == RAWDATATYPE) {
              expr_t *e = newExpr_RawData(sv.rawdata->size);
              memcpy(e->rawdata->data, sv.rawdata->data, sv.rawdata->size);
              sv.rawdata = e->rawdata;
              free(e);
            } else if (sv.type == BIGINT) {
              expr_t *e = newExpr_BigInt(sv.bigInt);
              sv.bigInt = e->bigInt;
              free(e);
            }

            ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

            /* Check if the variable is to be put in the class namespace */
            if (classCtx != NULL) {
              classCheck = hashtable_get(classCtx->varMembers, PROVIDE_CONTEXT()->syncCtx, idStr);
              if (classCheck != NULL) {
                /* Placing variable declaration in class member namespace */
                hashtable_put(classCtx->varMembers, PROVIDE_CONTEXT()->syncCtx, idStr, hvp);
                stop = 1;
              }
            }

            if (!stop) {
              /* Check if the variable is in the global namespace */
              globalCheck =
                  hashtable_get(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, idStr);

              if (globalCheck != NULL || ctx->depth == 0) {
                /* Placing variable declaration in global variable namespace */
                hashtable_put(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, idStr, hvp);
              } else {
                /* Placing variable declaration in local variable namespace */
                locals_push(varLocals, idStr, hvp);
              }
            }
          } break;
          case EXPR_TYPE_VECTOR_IDX: {
            vector_t *vec = NULL;
            dictionary_t *dict = NULL;
            int32_t arrayIndex;
            argsList_t *walk;
            expr_t **expToSet = NULL;
            expr_t *vecid = id->vecIdx->expr;
            expr_t *index = id->vecIdx->index;

            stackval_t sv;

            evaluate_expression(vecid, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            switch (sv.type) {
              case DICTTYPE: {
                dict = sv.dict;
                /* Assigning a dictionary */
                char *key = NULL;
                heapval_t *hvp = NULL;
                int dummy;

                evaluate_expression(index, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                if (sv.type != TEXT) {
                  fprintf(stderr, "index error: Must provide a string as key\n");
                  exit(1);
                }

                key = ast_emalloc(strlen(sv.t) + 2);
                snprintf(key, strlen(sv.t) + 1, "%s", sv.t);

                /* Evaluating the expression among global variables */
                evaluate_expression(decl->val, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                /* Placing value on the heap */
                if (sv.type == TEXT) {
                  /* Special case */
                  char *c = sv.t;
                  size_t len = strlen(c) + 1;
                  char *newText = ast_emalloc(len);
                  snprintf(newText, len, "%s", c);
                  sv.t = newText;
                } else if (sv.type == VECTORTYPE) {
                  expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
                  sv.vec = e->vec;
                  free(e);
                } else if (sv.type == DICTTYPE) {
                  dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
                  sv.dict = dict;
                }

                ALLOC_HEAP(&sv, hp, &hvp, &dummy);

                // Check if collision, if so, free key
                hashtable_put(dict->hash, PROVIDE_CONTEXT()->syncCtx, key, hvp);
              } break;
              case VECTORTYPE: {
                /* Assigning a vector */
                expr_t *newExp = NULL;
                vec = sv.vec;
                evaluate_expression(index, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                if (sv.type != INT32TYPE) {
                  fprintf(stderr, "index error: Must provide an integer as index\n");
                  exit(1);
                }

                arrayIndex = sv.i;

                /* check the limits */
                if (arrayIndex >= vec->length) {
                  fprintf(stderr,
                          "index error: index: '%" PRIi32 "' is too large, length: '%" PRIi32
                          "'\n",
                          arrayIndex, vec->length);
                  exit(1);
                }

                walk = vec->content;
                while (walk != NULL && arrayIndex >= 0) {
                  expToSet = &walk->arg;
                  walk = walk->next;
                  --arrayIndex;
                }

                if (*expToSet == NULL) {
                  fprintf(stderr, "Unexpected index error!\n");
                  GENERAL_REPORT_ISSUE_MSG();
                  exit(1);
                }

                evaluate_expression(decl->val, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                /* Placing this expression into the array */
                free_expression(*expToSet);
                free(*expToSet);

                newExp = stackval_to_expression(&sv, EXPRESSION_ARGS());
                *expToSet = newExp;
              } break;
              case TEXT: {
                char *text = sv.t;
                size_t origLen = strlen(text);
                size_t additionLen;
                size_t diff;
                size_t q = 0;
                char *newAddition = NULL;

                evaluate_expression(index, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                if (sv.type != INT32TYPE) {
                  fprintf(stderr, "index error: Must provide an integer as index\n");
                  exit(1);
                }

                arrayIndex = sv.i;

                if (arrayIndex >= strlen(text)) {
                  fprintf(stderr, "index error: index out of bounds\n");
                  exit(1);
                }

                /* Evaluating the expression among global variables */
                evaluate_expression(decl->val, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                if (sv.type != TEXT) {
                  fprintf(stderr, "string index error: Can only assign text to text.\n");
                  exit(1);
                }

                newAddition = sv.t;
                additionLen = strlen(newAddition);

                diff = origLen - arrayIndex;

                additionLen = (diff < additionLen ? diff : additionLen);
                q = 0;
                while (q < additionLen) {
                  text[arrayIndex + q] = newAddition[q];
                  q++;
                }
              } break;
              default: {
                fprintf(stderr, "index error: '%s' is not an indexable object.\n", id->id.id);
                GENERAL_REPORT_ISSUE_MSG();
                exit(1);
                break;
              }
            }
          } break;
          default:
            GENERAL_REPORT_ISSUE_MSG();
            break;
        }

        if (*interactive & INTERACTIVE_STACK) {
          break;
        }

        // Mark and sweep the heap
        mark_and_sweep(PROVIDE_CONTEXT()->varDecs, EXPRESSION_ARGS());
      } break;
      case LANG_ENTITY_SYSTEM: {
        expr_t *sys_var = (expr_t *)((statement_t *)stmt)->content;
        stackval_t sv;

        evaluate_expression(sys_var, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);
        switch (sv.type) {
          case TEXT:
            /* Making the system call */
            system(sv.t);
            break;
          default:
            printf("%s.error: unknown type of system call on the stack (%d)\n", __func__, sv.type);
            break;
        }
      } break;
      case LANG_ENTITY_RETURN: {
        expr_t *retVal = (expr_t *)((statement_t *)stmt)->content;
        stackval_t sv;

        evaluate_expression(retVal, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);
        switch (sv.type) {
          case TEXT:
            /* Pushing the return value as a string */
            PUSH_STRING(sv.t, sp, sc);
            break;
          case INT32TYPE:
            /* Pushing the return value as an int */
            PUSH_INT(sv.i, sp, sc);
            break;
          case BIGINT:
            /* Pushing the return value as an int */
            PUSH_BIGINT(sv.bigInt, sp, sc);
            break;
          case TIMETYPE:
            /* Pushing the return value as an int */
            PUSH_TIME(sv.time, sp, sc);
            break;
          case RAWDATATYPE:
            /* Pushing the return value as an int */
            PUSH_RAWDATA(sv.rawdata, sp, sc);
            break;
          case VECTORTYPE: {
            /* Pushing the return value as a vector */
            /* Placing value on the heap */
            int dummy;
            heapval_t *hvp = NULL;
            expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
            sv.vec = e->vec;
            free(e);
            ALLOC_HEAP(&sv, hp, &hvp, &dummy);
            PUSH_VECTOR(sv.vec, sp, sc);
            break;
          }
          case DICTTYPE: {
            /* Pushing the return value as a vector */
            /* Placing value on the heap */
            int dummy;
            heapval_t *hvp = NULL;
            dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
            sv.dict = dict;
            ALLOC_HEAP(&sv, hp, &hvp, &dummy);
            PUSH_DICTIONARY(sv.dict, sp, sc);
            break;
          }
          case DOUBLETYPE:
            /* Pushing the return value as a double */
            PUSH_DOUBLE(sv.d, sp, sc);
            break;
          default:
            printf("%s.error: unknown type of system call on the stack (%d)\n", __func__, sv.type);
            break;
        }
        /* Returning now from this function */
        free(ctx);
        return INTEPRET_RETURN;
      } break;
      case LANG_ENTITY_CLASSDECL: {
        class_t *newClass = ((statement_t *)stmt)->content;

        /* Placing funciton declaration in global function namespace */
        hashtable_put(PROVIDE_CONTEXT()->classDecs, PROVIDE_CONTEXT()->syncCtx, newClass->id,
                      newClass);
      } break;
      case LANG_ENTITY_FUNCDECL: {
        functionDef_t *funcDef = ((statement_t *)stmt)->content;

        /* Placing funciton declaration in global function namespace */
        hashtable_put(PROVIDE_CONTEXT()->funcDecs, PROVIDE_CONTEXT()->syncCtx, funcDef->id.id,
                      funcDef);
      } break;
      case LANG_ENTITY_FOREACH: {
        forEachStmt_t *festmt = ((statement_t *)stmt)->content;
        expr_t *root = festmt->root;
        expr_t *entry = festmt->entry;
        int localsStackSp = varLocals->sp;
        int localsStackSb = varLocals->sb;
        size_t stackCount = *sc;
        size_t *sc = PROVIDE_CONTEXT()->sc;
        void *sp = PROVIDE_CONTEXT()->sp;
        argsList_t *vecContent = NULL;
        class_t *tmp = NULL;
        class_t *classObj = NULL;
        int *depth = PROVIDE_CONTEXT()->depth;
        expr_t *rootExp = NULL;
        vector_t *rootVec = NULL;
        char *rootChars = NULL;
        int32_t rootInt = -1;
        mpz_t *rootBigInt = NULL;
        dictionary_t *rootDict = NULL;
        argsList_t *walk = NULL;
        expr_t *expToSet = NULL;
        heapval_t *hvp = NULL;
        int dummy;
        int32_t arrayIndex = 0;
        int32_t festmtIndex = 0;
        int festmtBigIntInitialized = 0;
        mpz_t festmtBigIndex;
        int32_t endIteration = 0;
        mpz_t endIterationBigInt;
        char *entryId = NULL;
        stackval_t sv;
        expr_t *newVec = NULL;
        int *interactive = PROVIDE_CONTEXT()->interactive;
        int continueLoop = 1;
        interpret_state_t interpret_state = INTEPRET_CONTINUE;

        evaluate_expression(root, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);
        rootExp = stackval_to_expression(&sv, EXPRESSION_ARGS());
        switch (rootExp->type) {
          case EXPR_TYPE_VECTOR:
            rootVec = rootExp->vec;
            break;
          case EXPR_TYPE_DICT:
            rootDict = rootExp->dict;
            break;
          case EXPR_TYPE_TEXT:
            rootChars = rootExp->text;
            break;
          case EXPR_TYPE_IVAL:
            rootInt = rootExp->ival;
            break;
          case EXPR_TYPE_BIGINT:
            rootBigInt = rootExp->bigInt;
            break;
          default:
            printf("%s.%d error: expression isn't an indexable\n", ((statement_t *)stmt)->file,
                   ((statement_t *)stmt)->line);
            break;
        }

        if (rootVec != NULL) {
          endIteration = rootVec->length;
        } else if (rootDict != NULL) {
          /* traverse the dictionary keys */
          hashtable_t *hash = rootDict->hash;
          int hashSize = hash->size;
          struct key_val_pair *ptr;
          int i = 0;
          int keyCount = 0;
          /* Check limits */
          while (i < hashSize) {
            ptr = hash->table[i];
            while (ptr != NULL) {
              /* Here is a key.. */
              ptr = ptr->next;
              keyCount++;
            }
            i++;
          }
          endIteration = keyCount;
        } else if (rootChars != NULL) {
          endIteration = strlen(rootChars);
        } else if (rootInt >= 0) {
          endIteration = rootInt;
        } else if (rootBigInt != NULL) {
          if (!festmtBigIntInitialized) {
            mpz_init(endIterationBigInt);
            mpz_init(festmtBigIndex);
            mpz_add(endIterationBigInt, *rootBigInt, festmtBigIndex);

            festmtBigIntInitialized = 1;
          }
        } else {
          /* This is really not supposed to happen */
          printf(
              "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
              ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, GENERAL_ERROR_ISSUE_URL);
          exit(1);
        }

        while (continueLoop) {
          if (entry->type != EXPR_TYPE_ID) {
            printf("%s.%d error: '%s' isn't a correct variable\n", ((statement_t *)stmt)->file,
                   ((statement_t *)stmt)->line, entry->id.id);
          } else {
            entryId = entry->id.id;
          }

          /* Get or set for-each unfold variable value */
          hvp = locals_lookup(varLocals, festmt->uniqueUnfoldIncID);
          if (hvp == NULL) {
            /* Create the variable with the value to be used for indexing, start with 0 */
            if (rootBigInt != NULL) {
              stackval_t sv;
              expr_t *e = newExpr_BigIntFromInt(0);
              heapval_t *hvp = NULL;

              sv.type = BIGINT;
              sv.bigInt = e->bigInt;
              free(e);

              mpz_add_ui(*sv.bigInt, festmtBigIndex, 0);

              ALLOC_HEAP(&sv, hp, &hvp, &dummy);
              locals_push(varLocals, festmt->uniqueUnfoldIncID, hvp);
            } else {
              sv.type = INT32TYPE;
              sv.i = 0;
              ALLOC_HEAP(&sv, hp, &hvp, &dummy);
              locals_push(varLocals, festmt->uniqueUnfoldIncID, hvp);
            }
          }
          /* Get the index value */
          hvp = locals_lookup(varLocals, festmt->uniqueUnfoldIncID);
          if (hvp == NULL || (hvp->sv.type != INT32TYPE && hvp->sv.type != BIGINT)) {
            /* This is really not supposed to happen */
            printf(
                "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, GENERAL_ERROR_ISSUE_URL);
            exit(1);
          }

          if (!festmtBigIntInitialized && endIteration == 0) {
            continueLoop = 0;
            continue;
          }

          if (hvp->sv.type == INT32TYPE) {
            festmtIndex = hvp->sv.i;
            arrayIndex = festmtIndex;
          } else if (hvp->sv.type == BIGINT) {
            mpz_add_ui(festmtBigIndex, *hvp->sv.bigInt, 0);
          }

          if (rootVec != NULL) {
            int arrayIndexWalk = arrayIndex;
            /* Increase the value of the unfolded variable */
            festmtIndex++;
            hvp = locals_lookup(varLocals, festmt->uniqueUnfoldIncID);

            if (hvp == NULL || hvp->sv.type != INT32TYPE) {
              /* This is really not supposed to happen */
              printf(
                  "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line,
                  GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            hvp->sv.i = festmtIndex;
            locals_push(varLocals, festmt->uniqueUnfoldIncID, hvp);

            walk = rootVec->content;
            while (walk != NULL && arrayIndexWalk >= 0) {
              expToSet = walk->arg;
              walk = walk->next;
              --arrayIndexWalk;
            }

            if (expToSet == NULL) {
              fprintf(stderr, "%s.%d error: Unexpected index error!\n",
                      ((statement_t *)stmt)->file, ((statement_t *)stmt)->line);
              GENERAL_REPORT_ISSUE_MSG();
              exit(1);
            }

            evaluate_expression(expToSet, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            /* Placing value on the heap */
            if (sv.type == TEXT) {
              /* Special case */
              char *c = sv.t;
              size_t len = strlen(c) + 2;
              char *newText = ast_ecalloc(len);
              snprintf(newText, len, "%s", c);
              sv.t = newText;
            } else if (sv.type == VECTORTYPE) {
              expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
              sv.vec = e->vec;
              free(e);
            } else if (sv.type == DICTTYPE) {
              dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
              sv.dict = dict;
            }
            ALLOC_HEAP(&sv, hp, &hvp, &dummy);
            locals_push(varLocals, entryId, hvp);

          } else if (rootDict != NULL) {
            /* traverse the dictionary keys */
            hashtable_t *hash = rootDict->hash;
            int hashSize = hash->size;
            struct key_val_pair *ptr;
            int i = 0;
            int keyCount = 0;
            i = 0;
            while (i < hashSize) {
              ptr = hash->table[i];
              while (ptr != NULL) {
                /* Add this key to the list */
                char *c = (char *)ptr->key;
                if (keyCount == arrayIndex) {
                  size_t len = strlen(c) + 1;
                  char *newText = ast_emalloc(len);
                  snprintf(newText, len, "%s", c);
                  sv.type = TEXT;
                  sv.t = newText;
                  ALLOC_HEAP(&sv, hp, &hvp, &dummy);
                  locals_push(varLocals, entryId, hvp);
                  /* Increase the value of the unfolded variable */
                  festmtIndex++;
                  hvp = locals_lookup(varLocals, festmt->uniqueUnfoldIncID);

                  if (hvp == NULL || hvp->sv.type != INT32TYPE) {
                    /* This is really not supposed to happen */
                    printf(
                        "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                        ((statement_t *)stmt)->file, ((statement_t *)stmt)->line,
                        GENERAL_ERROR_ISSUE_URL);
                    exit(1);
                  }

                  hvp->sv.i = festmtIndex;
                  locals_push(varLocals, festmt->uniqueUnfoldIncID, hvp);
                }

                ptr = ptr->next;
                keyCount++;
              }
              i++;
            }
          } else if (rootChars != NULL) {
            /* traverse the string chars */
            stackval_t sv;
            size_t len;
            char *newText;

            hvp = locals_lookup(varLocals, entryId);
            if (hvp == NULL) {
              len = 2;
              newText = ast_emalloc(len);
              snprintf(newText, 2, "%c", rootChars[arrayIndex]);

              sv.type = TEXT;
              sv.t = newText;

              ALLOC_HEAP(&sv, hp, &hvp, &dummy);
              locals_push(varLocals, entryId, hvp);
            } else {
              /* Update with new text */
              snprintf(hvp->sv.t, 2, "%c", rootChars[arrayIndex]);
            }
            /* Increase the value of the unfolded variable */
            festmtIndex++;
            hvp = locals_lookup(varLocals, festmt->uniqueUnfoldIncID);

            if (hvp == NULL || hvp->sv.type != INT32TYPE) {
              /* This is really not supposed to happen */
              printf(
                  "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line,
                  GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            hvp->sv.i = festmtIndex;
            locals_push(varLocals, festmt->uniqueUnfoldIncID, hvp);
          } else if (rootInt >= 0) {
            /* traverse the integer, start from zero */
            hvp = locals_lookup(varLocals, entryId);
            if (hvp == NULL) {
              stackval_t sv;

              sv.type = INT32TYPE;
              sv.i = festmtIndex;
              ALLOC_HEAP(&sv, hp, &hvp, &dummy);
              locals_push(varLocals, entryId, hvp);
            } else {
              /* Update value on the heap */
              hvp->sv.i = festmtIndex;
            }
            /* Increase the value of the unfolded variable */
            festmtIndex++;
            hvp = locals_lookup(varLocals, festmt->uniqueUnfoldIncID);

            if (hvp == NULL || hvp->sv.type != INT32TYPE) {
              /* This is really not supposed to happen */
              printf(
                  "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line,
                  GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            hvp->sv.i = festmtIndex;
            locals_push(varLocals, festmt->uniqueUnfoldIncID, hvp);
          } else if (rootBigInt != NULL) {
            /* traverse the big integer, start from zero */
            stackval_t sv;
            expr_t *e = NULL;
            heapval_t *hvp = NULL;

            hvp = locals_lookup(varLocals, entryId);
            if (hvp == NULL) {
              e = newExpr_BigIntFromInt(0);

              sv.type = BIGINT;
              sv.bigInt = e->bigInt;
              free(e);

              mpz_add_ui(*sv.bigInt, festmtBigIndex, 0);

              ALLOC_HEAP(&sv, hp, &hvp, &dummy);
              locals_push(varLocals, entryId, hvp);
            } else {
              mpz_add_ui(*hvp->sv.bigInt, festmtBigIndex, 0);
            }

            /* Increase the value of the unfolded variable */
            mpz_add_ui(festmtBigIndex, festmtBigIndex, 1);
            hvp = locals_lookup(varLocals, festmt->uniqueUnfoldIncID);

            if (hvp == NULL || hvp->sv.type != BIGINT) {
              /* This is really not supposed to happen */
              printf(
                  "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line,
                  GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            mpz_add_ui(*hvp->sv.bigInt, festmtBigIndex, 0);
            locals_push(varLocals, festmt->uniqueUnfoldIncID, hvp);
          } else {
            /* This is really not supposed to happen */
            printf(
                "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, GENERAL_ERROR_ISSUE_URL);
            exit(1);
          }

          continueLoop = endIteration != 0;
          if (rootBigInt != NULL) {
            // Special case, big looping
            continueLoop = (mpz_cmp_ui(endIterationBigInt, 0) != 0);
          }

          if (continueLoop) {
            /* Moving along, interpreting body */
            localsStackSp = varLocals->sp;
            localsStackSb = varLocals->sb;
            (void)depth;
            (void)tmp;
            (void)classObj;
            (void)localsStackSp;
            (void)localsStackSb;
            interpret_state =
                interpret_statements_(festmt->body, PROVIDE_CONTEXT(), args, argVals);
            varLocals->sb = localsStackSb;
            varLocals->sp = localsStackSp;
          }

          /* Get the index value */
          hvp = locals_lookup(varLocals, festmt->uniqueUnfoldIncID);
          if (hvp == NULL || (hvp->sv.type != INT32TYPE && hvp->sv.type != BIGINT)) {
            /* This is really not supposed to happen */
            fprintf(
                stderr,
                "%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, GENERAL_ERROR_ISSUE_URL);
            exit(1);
          }
          if (hvp->sv.type == INT32TYPE) {
            festmtIndex = hvp->sv.i;
            arrayIndex = festmtIndex;
          } else if (hvp->sv.type == BIGINT) {
            mpz_add_ui(festmtBigIndex, *hvp->sv.bigInt, 0);
          }

          if (*interactive == INTERACTIVE_STACK) {
            if (newVec == NULL) {
              newVec = newExpr_Vector(NULL);
            }
            /* Empty stack and append to array */
            while (*sc > stackCount) {
              expr_t *newExp;
              POP_VAL(&sv, sp, sc);

              newExp = stackval_to_expression(&sv, EXPRESSION_ARGS());

              vecContent = newArgument(newExp, vecContent);
              newVec->vec->length++;
              newVec->vec->content = vecContent;
            }
          }
          continueLoop = arrayIndex < endIteration;
          if (rootBigInt != NULL) {
            // Special case, big looping
            continueLoop = (mpz_cmp(endIterationBigInt, festmtBigIndex) != 0);
          }
          if (interpret_state == INTEPRET_RETURN) {
            /* A return was made, stop iterations */
            continueLoop = false;
          }
        }

        /* We are out of here */
        stmt = next;
        /* Remove unique unfold from locals */
        locals_remove(varLocals, festmt->uniqueUnfoldIncID);
        /* remove entry from locals */
        locals_remove(varLocals, entryId);

        if (rootBigInt != NULL) {
          mpz_clear(endIterationBigInt);
          mpz_clear(festmtBigIndex);
        }

        if (*interactive == INTERACTIVE_STACK) {
          argsList_t *prevArg;
          argsList_t *nextArg;
          argsList_t *currentArg;
          argsList_t *walk;
          /* Reverse the args list order */
          walk = newVec->vec->content;
          prevArg = NULL;
          currentArg = walk;
          while (currentArg != NULL) {
            nextArg = currentArg->next;
            currentArg->next = prevArg;
            prevArg = currentArg;
            currentArg = nextArg;
          }
          newVec->vec->content = prevArg;
          PUSH_VECTOR(newVec->vec, sp, sc);
          free(newVec);
        }

        if (rootDict == NULL) {
          /*
           * root expressions are heap allocated
           * all others will be manually cleaned up here
           */
          free_expression(rootExp);
        } else {
          free_hashtable_table(rootDict->hash);
          free(rootDict->hash);
          free(rootDict);
        }
        free(rootExp);
        if (interpret_state == INTEPRET_RETURN) {
          /* Returning now from this function */
          free(ctx);
          return INTEPRET_RETURN;
        }
      } break;
      case LANG_ENTITY_CONTINUE: {
        /* Set PC to continue 'start' */
        ctx->depth--;
        next = ctx->start[ctx->depth];
        ctx->depth = ctx->ctxDepth[ctx->depth];
        varLocals->sp = ctx->sp[ctx->depth];
        varLocals->sb = ctx->sb[ctx->depth];
        stmt = next;
        continue;
      } break;
      case LANG_ENTITY_BREAK: {
        /* Set PC to break 'end' */
        ctx->depth = ctx->ctxDepth[ctx->depth];
        next = ctx->end[ctx->depth];
        varLocals->sp = ctx->sp[ctx->depth];
        varLocals->sb = ctx->sb[ctx->depth];
        stmt = next;
        continue;
      } break;
      case LANG_ENTITY_EXPR: {
        stackval_t sv;
        size_t stackCount = *sc;
        expr_t *e = ((statement_t *)stmt)->content;

        switch (e->type) {
          case EXPR_TYPE_FUNCCALL: {
            functionCallContainer_t func;

            func.type = FUNC_CALL_TYPE_GLOBAL;
            func.globalCall = e->func;

            call_func(&func, EXPRESSION_ARGS());

            if (*interactive | INTERACTIVE_STACK) {
              break;
            }

            /* Printing result of function call, if string or vector */
            while (*sc > stackCount) {
              POP_VAL(&sv, sp, sc);
              switch (sv.type) {
                case TEXT:
                  printf("%s\n", sv.t);
                  break;
                case TIMETYPE: {
                  struct tm *timeInfo;
                  if (sv.time < 0) {
                    /* Relative time to now */
                    time_t nowTime;
                    time_t result;
                    time(&nowTime);
                    result = nowTime + sv.time;
                    timeInfo = localtime(&result);
                  } else {
                    timeInfo = localtime(&sv.time);
                  }
                  printf("%s", asctime(timeInfo));
                  break;
                }
                case VECTORTYPE:
                  print_vector(sv.vec, EXPRESSION_ARGS());
                  printf("\n");
                  break;
                case INT32TYPE:
                  if (*interactive) {
                    printf("%" PRIi32 "\n", sv.i);
                  }
                  break;
                case DOUBLETYPE:
                  if (*interactive) {
                    printf("%lf\n", sv.d);
                  }
                  break;
                default:
                  break;
              }
            }

            break;
          }
          case EXPR_TYPE_CLASSFUNCCALL: {
            functionCallContainer_t func;

            func.type = FUNC_CALL_TYPE_CLASS;
            func.classCall = e->func;

            call_func(&func, EXPRESSION_ARGS());

            if (*interactive | INTERACTIVE_STACK) {
              break;
            }

            /* Printing result of function call, if string or vector */
            while (*sc > stackCount) {
              POP_VAL(&sv, sp, sc);
              switch (sv.type) {
                case TEXT:
                  printf("%s\n", sv.t);
                  break;
                case TIMETYPE: {
                  struct tm *timeInfo;
                  if (sv.time < 0) {
                    /* Relative time to now */
                    time_t nowTime;
                    time_t result;
                    time(&nowTime);
                    result = nowTime + sv.time;
                    timeInfo = localtime(&result);
                  } else {
                    timeInfo = localtime(&sv.time);
                  }
                  printf("%s", asctime(timeInfo));
                  break;
                }
                case VECTORTYPE:
                  print_vector(sv.vec, EXPRESSION_ARGS());
                  printf("\n");
                  break;
                case INT32TYPE:
                  if (*interactive) {
                    printf("%" PRIi32 "\n", sv.i);
                  }
                  break;
                case DOUBLETYPE:
                  if (*interactive) {
                    printf("%lf\n", sv.d);
                  }
                  break;
                case BIGINT: {
                  char buf[128];
                  char *c = NULL;

                  c = mpz_get_str(buf, 10, *sv.bigInt);
                  printf("%s\n", c);
                } break;
                default:
                  break;
              }
            }

            break;
          }
          default: {

            if (*interactive) {
              /* Compute */
              evaluate_expression(e, EXPRESSION_ARGS());

              if (*interactive | INTERACTIVE_STACK) {
                break;
              }

              /* Printing result of computation */
              while (*sc > stackCount) {
                POP_VAL(&sv, sp, sc);
                switch (sv.type) {
                  case TEXT:
                    printf("%s\n", sv.t);
                    break;
                  case TIMETYPE: {
                    struct tm *timeInfo;
                    if (sv.time < 0) {
                      /* Relative time to now */
                      time_t nowTime;
                      time_t result;
                      time(&nowTime);
                      result = nowTime + sv.time;
                      timeInfo = localtime(&result);
                    } else {
                      timeInfo = localtime(&sv.time);
                    }
                    printf("%s", asctime(timeInfo));
                    break;
                  }
                  case VECTORTYPE:
                    print_vector(sv.vec, EXPRESSION_ARGS());
                    printf("\n");
                    break;
                  case INT32TYPE:
                    printf("%" PRIi32 "\n", sv.i);
                    break;
                  case DOUBLETYPE:
                    printf("%lf\n", sv.d);
                    break;
                  case BIGINT: {
                    char buf[128];
                    char *c = NULL;

                    c = mpz_get_str(buf, 10, *sv.bigInt);
                    printf("%s\n", c);
                  } break;
                  default:
                    break;
                }
              }
            }
          } break;
        }
      } break;
      case LANG_ENTITY_CONDITIONAL: {
        ifStmt_t *ifstmt = ((statement_t *)stmt)->content;
        ifStmt_t *ifstmtWalk;
        stackval_t sv;

        if (ifstmt->ifType & LANG_CONDITIONAL_CTX) {
          /* Handle the continue '@' and break '!@' points' */
          ctx->start[ctx->depth] = stmt;
          ctx->end[ctx->depth] = next;
          ctx->ctxDepth[ctx->depth] = ctx->depth;
        }

        ctx->bodyEnd[ctx->depth] = next;

        evaluate_expression(ifstmt->cond, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);

        switch (sv.type) {
          case INT32TYPE:
            *ax = (sv.i != 0);
            break;
          case BIGINT: {
            *ax = (mpz_cmp_si(*sv.bigInt, 0) != 0);
            break;
          }
          default:
            fprintf(stderr, "Invalid conditional expression (%d)\n", sv.type);
            exit(1);
            break;
        }

        /* Read ax for conditional */
        if (*ax) {
          next = ifstmt->body;
        } else {
          // Walk through the elifs.
          int stop = 0;
          ifstmtWalk = ifstmt->elif;

          while (ifstmtWalk != NULL) {

            evaluate_expression(ifstmtWalk->cond, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            switch (sv.type) {
              case INT32TYPE:
                *ax = (sv.i != 0);
                break;
              default:
                fprintf(stderr, "Invalid conditional expression.\n");
                exit(1);
                break;
            }

            if (*ax) {
              ifStmt_t *elif = ifstmtWalk;
              next = elif->body;
              stop = 1;
              break;
            }
            ifstmtWalk = ifstmtWalk->elif;
          }

          if (!stop) {
            if (ifstmt->endif != NULL) {
              ifStmt_t *endif = ifstmt->endif;
              next = endif->body;
            }
          }
        }
      } break;
      default:
        break;
    }

    stmt = next;
  }

  free(ctx);
  return INTEPRET_CONTINUE;
}

void interpret_statements(int argc, char *argv[], statement_t *stmt, int stacksize, int heapsize) {
  // "CPU" registers definitions
  DEF_NEW_CONTEXT();

  // Setup stack
  SETUP_STACK(&sp, &sb, stacksize, &sc);

  // Setup heap
  SETUP_HEAP(&hp, &hb, heapsize);

  // Setup locals
  varLocals = ast_emalloc(sizeof(locals_stack_t));
  varLocals->sp = 0;
  varLocals->sb = 0;

  // Set up ric library
  initialize_ric_lib();

  /* Set starting point and end point */
  st = stmt;
  ed = NULL;

  /* Set interactive state to NON_INTERACTIVE */
  interactive = NON_INTERACTIVE;

  /* Set class context to NULL */
  classCtx = NULL;

  /* Set thread synchronization context */
  syncCtx = createContext();

  /* Set starting depth */
  depth = 0;

  /* Assigning the execution context super structure */
  ASSIGN_CONTEXT(exeCtx);

  /* Setup namespaces */
  setup_namespaces(PROVIDE_CONTEXT_INIT());

  /* arguments to environment variables */
  arguments_to_variables(PROVIDE_CONTEXT_INIT(), argc, argv, hp);

  if (setjmp(endingJmpBuf) == JMP_CODE_INITIAL) {
    /* Start descending and evaluating the AST */
    interpret_statements_(stmt, PROVIDE_CONTEXT_INIT(), NULL, NULL);
  } else {
    // Free thread context
    freeContext(syncCtx);

    // Close namespaces
    close_namespaces(PROVIDE_CONTEXT_INIT());

    // free locals
    free(varLocals);

    // free heap
    free_heap(hp, hb);

    // Free stack
    FREE_STACK(sp, sb);

    // Free memory associated with the AST
    free_ast(stmt);
  }
}

void interpret_statements_interactive(int argc, char *argv[], statement_t *stmt, int teardown,
                                      int stacksize, int heapsize) {
  static int firstCall = 1;
  // "CPU" registers definitions
  DEF_NEW_CONTEXT_STATIC();

  if (firstCall) {
    // Setup stack
    SETUP_STACK(&sp, &sb, stacksize, &sc);

    // Setup heap
    SETUP_HEAP(&hp, &hb, heapsize);

    // Setup locals
    varLocals = ast_emalloc(sizeof(locals_stack_t));
    varLocals->sp = 0;
    varLocals->sb = 0;

    // Set up ric library
    initialize_ric_lib();

    /* Set starting point and end point */
    st = stmt;
    ed = NULL;

    /* Set class context to NULL */
    classCtx = NULL;

    /* Set starting depth */
    depth = 0;

    /* Set interactive state to 1 */
    interactive = INTERACTIVE_PRINT;

    /* Flag that setup has been done already */
    firstCall = 0;

    /* Set thread synchronization context */
    syncCtx = createContext();

    /* Assigning the execution context super structure */
    ASSIGN_CONTEXT(exeCtx);

    /* Setup namespaces */
    setup_namespaces(PROVIDE_CONTEXT_INIT());

    /* arguments to environment variables */
    arguments_to_variables(PROVIDE_CONTEXT_INIT(), argc, argv, hp);
  }

  if (stmt != NULL) {

    /* Check if load */
    if (stmt->entity == LANG_ENTITY_EXPR) {
      stackval_t stv;
      libFunction_t *libFunc;

      expr_t *e = (expr_t *)stmt->content;

      if (e->type == EXPR_TYPE_FUNCCALL) {
        functionCall_t *call = e->func;
        evaluate_expression(call->id, NULL, NULL, PROVIDE_CONTEXT_INIT(), NULL, NULL);

        POP_VAL(&stv, &sp, &sc);
        if (stv.type == LIBFUNCPTRTYPE) {
          libFunc = stv.libfunc;

          /* Check if this is a load call */
          if (strcmp(libFunc->libFuncName, "load") == 0) {
            printf("Sorry, load in interactive mode is not implemented yet\n");
            return;
          }
        }
      }
    }

    switch (setjmp(endingJmpBuf)) {
      case JMP_CODE_INITIAL:
        /* Start descending and evaluating the AST */
        interpret_statements_(stmt, PROVIDE_CONTEXT_INIT(), NULL, NULL);
        break;
      case JMP_CODE_TEARDOWN:
        // free thread context
        freeContext(syncCtx);

        // Close namespaces
        close_namespaces(PROVIDE_CONTEXT_INIT());

        // free locals
        free(varLocals);

        // free heap
        free_heap(hp, hb);

        // Free stack
        FREE_STACK(sp, sb);

        // Free memory associated with the AST
        free_ast(stmt);
        break;
      default:
        break;
    }
  }

  if (teardown != 0) {
    // free thread context
    freeContext(syncCtx);

    // Close namespaces
    close_namespaces(PROVIDE_CONTEXT_INIT());

    // free locals
    free(varLocals);

    // free heap
    free_heap(hp, hb);

    // Free stack
    FREE_STACK(sp, sb);

    // Free memory associated with the AST
    free_ast(stmt);
  }
}

void setup_namespaces(PROVIDE_CONTEXT_ARGS()) {
  static int globalNamespaceSetup = 0;

  if (globalNamespaceSetup == 0) {
    PROVIDE_CONTEXT()->funcDecs = hashtable_new(100, 0.8);
    assert(PROVIDE_CONTEXT()->funcDecs != NULL);
    PROVIDE_CONTEXT()->varDecs = hashtable_new(200, 0.8);
    assert(PROVIDE_CONTEXT()->varDecs != NULL);
    PROVIDE_CONTEXT()->classDecs = hashtable_new(200, 0.8);
    assert(PROVIDE_CONTEXT()->classDecs != NULL);

    globalNamespaceSetup = 1;
  }
}

void close_namespaces(PROVIDE_CONTEXT_ARGS()) {
  hashtable_free(PROVIDE_CONTEXT()->funcDecs);
  hashtable_free(PROVIDE_CONTEXT()->varDecs);
  hashtable_free(PROVIDE_CONTEXT()->classDecs);
}

static void flush_arg(void *key, void *val) {
  expr_t *e = (expr_t *)val;
  (void)key;
  if (e->type == EXPR_TYPE_TEXT) {
    free(e->text);
  } else if (e->type == EXPR_TYPE_DICT) {
    hashtable_free(e->dict->hash);
    free(e->dict);
  } else if (e->type == EXPR_TYPE_RAWDATA) {
    free(e->rawdata->data);
    free(e->rawdata);
  } else if (e->type == EXPR_TYPE_CLASSPTR) {
    class_t *class = e->classObj;
    hashtable_free(class->funcDefsABI);
    hashtable_free(class->funcDefsScript);
    hashtable_free(class->varMembers);
    free(class);
  } else if (e->type == EXPR_TYPE_BIGINT) {
    mpz_clear(*e->bigInt);
    free(e->bigInt);
  }
}

void flush_arguments(hashtable_t *table) {
  for_each_pair(table, flush_arg);
  if (table != NULL) {
    hashtable_free(table);
  }
}

static int isAnInt(char *arg) {
  char *c = arg;
  while (*c) {
    if (!isdigit(*c)) {
      return 0;
    }
    ++c;
  }
  return 1;
}

static int isAFloat(char *arg) {
  char *c = arg;
  int nbrDots = 0;
  while (*c) {
    if (!isdigit(*c)) {
      // It might be a dot
      if (*c != '.') {
        return 0;
      } else {
        if (nbrDots == 1) {
          return 0;
        }
        nbrDots++;
      }
    }
    ++c;
  }

  if (nbrDots == 1) {
    return 1;
  }

  return 0;
}

static int typeOfArgument(char *arg) {
  if (strlen(arg) == 1 && arg[0] == '.') {
    return TEXT;
  }

  if (isAFloat(arg)) {
    return DOUBLETYPE;
  }

  if (isAnInt(arg)) {
    return INT32TYPE;
  }

  return TEXT;
}

static char *reservedArgs[] = {"-pi", "-p", "-i", "-h", "--help"};

static char *argumentListName = "args";

void arguments_to_variables(PROVIDE_CONTEXT_ARGS(), int argc, char *argv[], void *hp) {
  /*
   * Invoking the program with command arguments:
   * --args value1 value2 ... valueN
   * will populate the global variable
   * args, which is a vector with max 10 arguments.
   */

  int heapUpdated;
  stackval_t sv;
  heapval_t *hvp = NULL;
  int argWalk = 0;
  int argCount = 0;
  int nbrReserved = sizeof(reservedArgs) / sizeof(*reservedArgs);
  int maxNbrArgs = MAX_NBR_ARGUMENTS;
  expr_t *args;
  argsList_t *argContent = NULL;

  if (argc < 2) {
    /* Not OK :/ */
    return;
  }

  while (argWalk < argc && argCount < maxNbrArgs) {
    char *arg = argv[argWalk];
    int argWalkReserved = 0;
    int ignore = 0;
    int argType;
    expr_t *newArgExp;
    argsList_t *newArgContent;

    // Some arguments are not to be passed to the environment
    while (argWalkReserved < nbrReserved) {
      if (strcmp(reservedArgs[argWalkReserved], arg) == 0) {
        // ignore this argument
        ignore = 1;
        break;
      }
      argWalkReserved++;
    }

    if (ignore) {
      argWalk++;
      continue;
    }

    newArgContent = ast_emalloc(sizeof(argsList_t));

    argType = typeOfArgument(arg);
    sv.type = argType;
    switch (argType) {
      case INT32TYPE: {
        newArgExp = newExpr_Ival(atoi(arg));
        break;
      }
      case DOUBLETYPE: {
        newArgExp = newExpr_Float(atof(arg));
        break;
      }
      case TEXT: {
        newArgExp = newExpr_Text(arg);
        break;
      }
      default:
        fprintf(stderr, "There was something strange with the provided argument..\r\n");
        GENERAL_REPORT_ISSUE_MSG();
        break;
    }

    newArgContent->arg = newArgExp;
    if (argContent == NULL) {
      argContent = newArgContent;
      argContent->length = 1;
      argContent->next = NULL;
    } else {
      newArgContent->next = argContent;
      newArgContent->length = argContent->length + 1;
      argContent = newArgContent;
    }

    argWalk++;
  }

  args = newExpr_Vector(argContent);

  /* Add space for argN */
  sv.type = VECTORTYPE;
  sv.vec = args->vec;
  free(args);

  ALLOC_HEAP_UNSAFE(&sv, hp, &hvp, &heapUpdated);

  /* Placing variable declaration in global variable namespace */
  hashtable_put(PROVIDE_CONTEXT()->varDecs, NULL, argumentListName, hvp);
}
