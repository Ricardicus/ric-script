#ifdef __cplusplus
extern "C" {
#endif 

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define START_SPACE		5

typedef struct key_val_pair{
	char * key;
	void * data;
	struct key_val_pair * next;
} entry_t;

typedef struct hash{
	int size;
	int ocupied;
	int data_also;
	float load;
	entry_t ** table;
	void (*put)(struct hash*,char*,void *);
	void (*print_table_callbacks)(struct hash*);
} hashtable_t;

// Make sure it outputs its name on recieving the "NAME" command
typedef void *(*callback_func_t)(int,hashtable_t*, char*); 

/*
* Function declarations
*/

hashtable_t * hashtable_new(int,float);
void hashtable_rehash(hashtable_t*);
void hashtable_free(hashtable_t*);
void* hashtable_get(hashtable_t*,const char*);
int hashtable_hash(hashtable_t*,const char*);
void hashtable_put(hashtable_t*,char*,void*);
void print_table_callbacks(hashtable_t*);
void print_table_as_chars(hashtable_t*);
void for_each_pair(hashtable_t * hash, void (*callback)(void*,void*) );

#endif

#ifdef __cplusplus
}
#endif