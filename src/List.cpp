#include "List.h"

ListElem_t* ListInsert(List_t* list, const char* word)
{
    assert(word);
    assert(list);

    ListElem_t* new_list_elem = (ListElem_t*) calloc(1, sizeof(ListElem_t));
    if(!new_list_elem)
    {
        fprintf(stderr, "ERROR: calloc insert error\n");
        return NULL;
    }

    size_t size_word = strlen(word);   //maybe create argument func with len

    new_list_elem->counter = 0;
    new_list_elem->elem = (char*) calloc(size_word + 1, sizeof(char));
    if(!new_list_elem->elem)
    {
        fprintf(stderr, "ERROR: calloc new word error\n");
        return NULL;
    }

    strncpy(new_list_elem->elem, word, size_word);

    if(list->size == 0)
    {
        list->size++;
        list->head = new_list_elem;
        list->tail = new_list_elem;
        return new_list_elem;
    }

    list->size++;
    list->tail->next = new_list_elem;
    list->tail = new_list_elem;


    return new_list_elem;
}

ErrorCode ListDtor(List_t* list)
{
    assert(list);

    ListElemDtor(list->head);

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return OK;
}

ListElem_t* ListElemDtor(ListElem_t* list_elem)
{
    assert(list_elem);

    if(list_elem->next != NULL) ListElemDtor(list_elem->next);

    free(list_elem->elem);
    list_elem->elem = NULL;
    free(list_elem);
    list_elem = NULL;

    return NULL;
}
