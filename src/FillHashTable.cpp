#include "FillHashTable.h"
#include "HashFunction.h"
#include "List.h"

const char* file_name = "CrimeAndPunishment.txt";

ErrorCode FillHashTable(HashTable_t* hash_table)
{
    assert(hash_table);

    size_t file_size = 0;

    char* buffer = ReadFile(&file_size);
    if(!buffer)
    {
        fprintf(stderr, "ERROR: buffer ptr = NULL\n");
        free(buffer);
        return BUFFER_ERROR;
    }
    char word_buff[MAX_WORD_SIZE] = {};
    size_t buff_elem = 0, word_elem = 0;
    int uniq_words = 0;
    while(buffer[buff_elem] != '\0' && buff_elem < file_size - 1)
    {
        if(!isalpha(buffer[buff_elem]))
        {
            buff_elem++;
        }
        else
        {
            while(isalpha(buffer[buff_elem]))
            {
                strncpy(&word_buff[word_elem], &buffer[buff_elem], 1);
                word_elem++;
                buff_elem++;
            }

            char* hash_word = (char*) calloc(word_elem + 1, sizeof(char));
            if(!hash_word)
            {
                fprintf(stderr, "ERROR: calloc hash_word\n");
                return CALLOC_ERROR;
            }

            strncpy(hash_word, word_buff, word_elem);

            uint32_t hash = CRC32((const uint8_t*)hash_word, word_elem);

            bool is_in_table = CheckWordInTable(hash_table, hash_word, hash);

            if(is_in_table == 0)
            {
                AddNewWord(hash_table, hash_word, hash);
                uniq_words++;
            }

            word_elem = 0;
            free(hash_word);
            hash_word = NULL;
        }
    }
    printf("\nuniq words = %d\n\n", uniq_words);
    free(buffer);
    buffer = NULL;
    return OK;
}

int AddNewWord(HashTable_t* hash_table, const char* word, uint32_t hash)
{
    assert(hash_table);
    assert(word);

    hash %= HASH_TABLE_SIZE;
    ListInsert(&hash_table->buckets[hash], word);

    return 0;
}

bool CheckWordInTable(HashTable_t* hash_table, const char* word, uint32_t hash)
{
    assert(word);
    assert(hash_table);

    hash %= HASH_TABLE_SIZE;
    ListElem_t* list_ptr = hash_table->buckets[hash].head;

    while(list_ptr != NULL)
    {
        if(!strcmp(word, list_ptr->elem))
        {
            return IN_TABLE;
        }
        else
        {
            list_ptr = list_ptr->next;
        }
    }
    return NOT_IN_TABLE;
}

char* ReadFile(size_t* file_size)
{
    FILE* text_file = fopen(file_name, "rb");
    if(!text_file)
    {
        fprintf(stderr, "cannot open file :%s\n", file_name);
        return NULL;
    }

    struct stat file_info = {};
    stat(file_name, &file_info);

    *file_size = file_info.st_size;

    char* buffer = (char*) calloc(*file_size, sizeof(char));
    if(!buffer)
    {
        fprintf(stderr, "ERROR: calloc in fill_table\n");
        return NULL;
    }

    size_t temp = fread(buffer, sizeof(char), *file_size, text_file);
    if(temp != *file_size)
    {
        fprintf(stderr, "ERROR: something wrong with fread(fread = %d actual size = %d)\n", temp, *file_size);
        return NULL;
    }

    fclose(text_file);

    return buffer;
}

