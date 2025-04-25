#include "List.h"

ListElem_t* ListInsert(ListElem_t* parent, const char* word)
{
    assert(word);

    ListElem_t* new_list_elem = (ListElem_t*) calloc(1, sizeof(ListElem_t));
    if(!new_list_elem)
    {
        fprintf(stderr, "ERROR: calloc insert error\n");
        return NULL;
    }

    size_t size_word = strlen(word);

    new_list_elem->elem = (char*) calloc(size_word + 1, sizeof(char));
    if(!new_list_elem->elem)
    {
        fprintf(stderr, "ERROR: calloc new word error\n");
        return NULL;
    }

    strncpy(new_list_elem->elem, word, size_word);

    if(parent)
    {
        parent->next = new_list_elem;
    }

    return new_list_elem;
}

ListElem_t* ListElemDtor(ListElem_t* list)
{
    assert(list);

    if(list->next) ListElemDtor(list->next);

    free(list->elem);
    list->elem = NULL;

    return NULL;
}
