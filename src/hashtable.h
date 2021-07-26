#ifdef __cplusplus
extern "C" {
#endif 

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>

#define START_SPACE		5

typedef struct key_val_pair {
	char * key;
	void * data;
	struct key_val_pair * next;
} entry_t;

typedef struct hash {
	int size;
	int ocupied;
	int data_also;
  int key_also;
	float load;
	entry_t ** table;
	void (*put)(struct hash*,void*,char*,void *);
} hashtable_t;

// Make sure it outputs its name on recieving the "NAME" command
typedef void *(*callback_func_t)(int,hashtable_t*, char*); 

/*
* Function declarations
*/

hashtable_t* hashtable_new(int,float);
void hashtable_rehash(hashtable_t*);
void hashtable_free(hashtable_t*);
void* hashtable_get(hashtable_t*,void *,const char*);
int hashtable_hash(hashtable_t*,const char*);
void hashtable_put(hashtable_t*,void*,char*,void*);
void print_table_as_chars(hashtable_t*);
void for_each_pair(hashtable_t * hash, void (*callback)(void*,void*) );
void hashtable_print_table_keys(hashtable_t * hashtable);
hashtable_t* hashtable_copy(hashtable_t *hashtable);

#endif

#ifdef __cplusplus
}
#endif


