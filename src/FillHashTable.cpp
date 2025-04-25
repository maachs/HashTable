#include "FillHashTable.h"

const char* file_name = "text.txt";

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
    printf("%s\n\n", buffer);
    char word_buff[MAX_WORD_SIZE] = {};
    int buff_elem = 0, word_elem = 0;
    while(buffer[buff_elem] != '\0')
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
            //TODO calc hash and add to hash table
            word_buff[word_elem] = '\0';
            fprintf(stderr, "%s ", word_buff);
            word_elem = 0;
        }

    }
    free(buffer);
    buffer = NULL;
    return OK;
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

    printf("size buff %ld\n", file_info.st_size);

    char* buffer = (char*) calloc(*file_size, sizeof(char));
    if(!buffer)
    {
        fprintf(stderr, "ERROR: calloc in fill_table\n");
        return NULL;
    }

    size_t temp = fread(buffer, sizeof(char), *file_size, text_file);
    if(temp != *file_size)
    {
        fprintf(stderr, "ERROR: something wrong with fread(fread = %ld actual size = %ld)\n", temp, *file_size);
        return NULL;
    }

    fclose(text_file);

    return buffer;
}

