/*
* A Hashtable implementation
*/ 
#include "hashtable.h"

extern void getContext(void *);
extern void releaseContext(void *);

hashtable_t * hashtable_new(int size, float load)
{
	hashtable_t * hashtable = malloc(sizeof(hashtable_t));
	if ( hashtable == NULL )
		return NULL;

	hashtable->size = size;
	hashtable->ocupied = 0;
	hashtable->data_also = 0;  // to be modified by user
  hashtable->key_also = 0;  // to be modified by user
	hashtable->load = load;
	hashtable->table = (entry_t**) calloc(size,sizeof(entry_t*));
	hashtable->put = hashtable_put;
	return hashtable;
}

static void free_hashtable_table(hashtable_t * hash)
{
	int size = hash->size;
	int i = 0;
	struct key_val_pair * ptr1;
	struct key_val_pair * ptr2;
	while (i<size) {
		ptr1 = hash->table[i];
		while (ptr1!=NULL) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
			if ( hash->data_also ) {
				free(ptr2->data);
			}
      if ( hash->key_also ) {
        free(ptr2->key);
      }
			free(ptr2);
		}
		i++;
	}
	free(hash->table);
}

void hashtable_rehash(hashtable_t * hashtable)
{
	int size_old = hashtable->size;
	int newsize = size_old * 2;
	hashtable_t * newhash = hashtable_new(newsize,hashtable->load);
	newhash->data_also = hashtable->data_also;
	int i = 0;
	while (i<size_old) {
		struct key_val_pair * ptr = hashtable->table[i];
		while (ptr!=NULL) {
			newhash->put(newhash,NULL,ptr->key,ptr->data);
			ptr = ptr->next;
		}
		i++;
	}
	free_hashtable_table(hashtable);
	hashtable->table = newhash->table;
	hashtable->size = newsize;
}


void hashtable_free(hashtable_t * hash)
{
	free_hashtable_table(hash);
	free(hash);
}

void for_each_pair(hashtable_t *hash, void (*callback)(void*,void*) )
{
	int size;
	int i = 0;
	struct key_val_pair * ptr1;
	struct key_val_pair * ptr2;

  if ( hash == NULL )
    return;

  size = hash->size;
	while (i<size) {
		ptr1 = hash->table[i];
		while (ptr1!=NULL) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;

			callback(ptr2->key, ptr2->data);
		}
		i++;
	}

}

int hashtable_hash(hashtable_t * hashtable,const char * str)
{	
	int size = hashtable->size;
	int hash = 0;
	while (*str) {
		hash+=*str * *str;
		str++;
	}
	if(size == 0) return 0;
	return hash % size;
}

void hashtable_put(hashtable_t * hashtable, void *ctx, char * key, void * val)
{
	float load_level;
	float max_load_level;

	if ( hashtable == NULL )
		return;
	
	getContext(ctx);
	load_level = (float) hashtable->ocupied * hashtable->load;
	max_load_level = (float) hashtable->size * hashtable->load;
	if(load_level > max_load_level) {
		hashtable_rehash(hashtable);
		hashtable->put(hashtable,NULL,key,val);
		releaseContext(ctx);
		return;
	} 
	int index = hashtable_hash(hashtable,key);
	if(hashtable->table[index] == NULL) {
		hashtable->table[index] = malloc(sizeof(entry_t));
		hashtable->table[index]->key = key;
		hashtable->table[index]->data = val;
		hashtable->table[index]->next = NULL;
		hashtable->ocupied++;
		releaseContext(ctx);
		return;
	} else {
		struct key_val_pair * ptr1 = hashtable->table[index];
		struct key_val_pair * ptr2;
		while (ptr1 != NULL) {
			if (strcmp(ptr1->key,key) == 0) {
        if ( hashtable->data_also ) {
          free(ptr1->data);
        }
        if ( hashtable->key_also ) {
          free(ptr1->key);
          ptr1->key = key;
        }
				ptr1->data = val;
				releaseContext(ctx);
				return;
			}
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		ptr2->next = malloc(sizeof(entry_t));
		ptr2 = ptr2->next;
		ptr2->key = key;
		ptr2->data = val;
		ptr2->next = NULL;
		hashtable->ocupied++;
	}
	releaseContext(ctx);
}

void * hashtable_get(hashtable_t * hashtable, void *ctx, const char * key)
{
	if ( hashtable == NULL )
		return NULL;

	int index = hashtable_hash(hashtable,key);
	if (hashtable->table[index] == NULL) {
		return NULL;
	}

	getContext(ctx);
	struct key_val_pair * p = hashtable->table[index];
	while (p!=NULL) {	
		if (strcmp(p->key,key) == 0) {
			releaseContext(ctx);
			return p->data;
		}
		p = p->next;
	}
	releaseContext(ctx);
	return NULL;
}

void print_table_as_chars(hashtable_t * hashtable)
{
	int i = 0;
	int size = hashtable->size;
	struct key_val_pair * ptr;

	while (i<size) {
		if (hashtable->table[i] != NULL) {
			ptr = hashtable->table[i];
			while (ptr!=NULL) {
				printf("key: %s - > data: %s\n",ptr->key,(char*)ptr->data);
				ptr=ptr->next;
			}
		}
		i++;
	}
}

void hashtable_print_table_keys(hashtable_t * hashtable)
{
	int i = 0;
	int size = hashtable->size;
	struct key_val_pair * ptr;

	while (i<size) {
		if (hashtable->table[i] != NULL) {
			ptr = hashtable->table[i];
			while (ptr!=NULL) {
				printf("key: %s\n",ptr->key);
				ptr=ptr->next;
			}
		}
		i++;
	}
}
