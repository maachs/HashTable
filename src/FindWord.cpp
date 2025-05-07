#include "FindWord.h"
#include "FillHashTable.h"
#include "HashFunction.h"

ErrorCode FindWord(HashTable_t* hash_table)
{
    assert(hash_table);

    char word_to_find[MAX_WORD_SIZE] = {};
    fprintf(stdout, "Enter word\n");
    scanf("%s", word_to_find);

    int word_count = CheckWordInTable(hash_table, word_to_find, CRC32((const uint8_t*)word_to_find, strlen(word_to_find)));

    if(word_count == NOT_IN_TABLE)
    {
        fprintf(stdout, "don't find %s in text\n", word_to_find);
    }
    else
    {
        fprintf(stdout, "%s find in text %d times\n", word_to_find, word_count);
    }

    return OK;
}
