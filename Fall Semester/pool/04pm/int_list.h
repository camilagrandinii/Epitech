#ifndef INT_LIST_H
#define INT_LIST_H

#include <stdbool.h>

typedef struct int_list {
    int value;
    struct int_list *next;
} int_list_t;

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem);
void int_list_dump(int_list_t *list);
unsigned int int_list_get_size(int_list_t *list);
bool int_list_is_empty(int_list_t *list);
void int_list_clear(int_list_t **front_ptr);

#endif