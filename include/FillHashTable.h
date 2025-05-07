#ifndef FILL_HASH_TABLE_
#define FILL_HASH_TABLE_

#include "HashTable.h"

const int MAX_WORD_SIZE = 20;

ErrorCode FillHashTable   (HashTable_t* hash_table);
char*     ReadFile        (size_t* file_size);
bool      CheckWordInTable(HashTable_t* hash_table, const char* word, uint32_t hash);
int       AddNewWord      (HashTable_t* hash_table, const char* word, uint32_t hash);

#endif
