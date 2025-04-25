#include "InitDtor.h"
#include "FillHashTable.h"

int main()
{
    HashTable_t hash_table = {};

    //HashTableInit(&hash_table);
    FillHashTable(&hash_table);
    //HashTableDtor(&hash_table);
}

