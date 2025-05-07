#ifndef HASH_TABLE_
#define HASH_TABLE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>
#include <ctype.h>
#include <assert.h>

const int HASH_TABLE_SIZE = 100;

enum ErrorCode
{
    OK = 0,
    CALLOC_ERROR = 1,
    BUFFER_ERROR = 2
};

enum IsInTableStatus
{
    IN_TABLE     = 1,
    NOT_IN_TABLE = 0
};

struct ListElem_t
{
    ListElem_t* next;
    char*       elem;
};

struct List_t
{
    ListElem_t* head;
    ListElem_t* tail;
    int size;
};

struct HashTable_t
{
    List_t* buckets;
    int     size;
};

#endif
