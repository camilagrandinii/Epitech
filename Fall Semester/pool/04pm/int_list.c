/*
** EPITECH PROJECT, 2024
** Marvin’s List
** File description:
** Manipulating Lists
*/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = (int_list_t *)malloc(sizeof(int_list_t));
    int_list_t *current = *front_ptr;
    if (new_node == NULL){
        return false;
    }
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL){
        *front_ptr = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return true;
}

void int_list_dump(int_list_t *list)
{
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}

int int_list_get_recursive_size(int_list_t *list, int count)
{
    if (list == NULL) {
        return count;
    } else {
        int_list_get_recursive_size(list->next, ++count);
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    return int_list_get_recursive_size(list, 0);
}

bool int_list_is_empty(int_list_t *list)
{
    return list == NULL;
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *temp;
    while (*front_ptr != NULL) {
        temp = *front_ptr;
        *front_ptr = (*front_ptr)->next;
        free(temp);
    }
}
