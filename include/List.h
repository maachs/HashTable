#ifndef LIST_
#define LIST_

#include "HashTable.h"

ListElem_t* ListInsert(List_t* list, const char* word);
ListElem_t* ListElemDtor(ListElem_t* list);
ErrorCode ListDtor(List_t* list);

#endif
