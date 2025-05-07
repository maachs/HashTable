#include "InitDtor.h"
#include "HashFunction.h"
#include "List.h"

ErrorCode HashTableInit(HashTable_t* hash_table)
{
    assert(hash_table);

    if(!(hash_table->buckets = (List_t*) calloc(HASH_TABLE_SIZE, sizeof(List_t))))
    {
        fprintf(stderr, "ctor calloc error\n");
        return CALLOC_ERROR;
    }
    hash_table->size = HASH_TABLE_SIZE;
    CRC32Init();

    return OK;
}

ErrorCode HashTableDtor(HashTable_t* hash_table)
{
    assert(hash_table);

    for(int hash_table_elem = 0; hash_table_elem < HASH_TABLE_SIZE; hash_table_elem++)
    {
        if(hash_table->buckets[hash_table_elem].head != NULL)
        {
            ListDtor(&hash_table->buckets[hash_table_elem]);
        }
    }

    free(hash_table->buckets);
    hash_table->buckets = NULL;

    return OK;
}
