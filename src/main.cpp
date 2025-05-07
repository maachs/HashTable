#include "InitDtor.h"
#include "FillHashTable.h"

int main()
{
    HashTable_t hash_table = {};

    if(HashTableInit(&hash_table) != OK)
    {
        HashTableDtor(&hash_table);
        fprintf(stderr, "ERROR: init error\n");
        return -1;
    }
    if(FillHashTable(&hash_table) != OK)
    {
        HashTableDtor(&hash_table);
        fprintf(stderr, "ERROR: fill table\n");
    }
    HashTableDtor(&hash_table);

    return 0;
}

