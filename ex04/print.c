/*
** EPITECH PROJECT, 2024
** C, Life, the Universe and everything else
** File description:
** Strings and Pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char *reversedString = strdup(str);
    char temp = ' ';
    size_t length = strlen(reversedString);

    for (size_t i = 0; i < length / 2; ++i){
        temp = reversedString[i];
        reversedString[i] = reversedString[length - i - 1];
        reversedString[length - i - 1] = temp;
    }
    printf("%s\n", reversedString);
    free(reversedString);
};

void print_upper(const char *str)
{
    char *upperCaseString = strdup(str);
    size_t length = strlen(upperCaseString);

    for (size_t i = 0; i < length - 1; ++i){
        if (islower(upperCaseString[i])){
            upperCaseString[i] = toupper(upperCaseString[i]);
        }
    }
    printf("%s\n", upperCaseString);
    free(upperCaseString);
}

void print_42(const char *str)
{
    printf("42\n");
};

void do_action(action_t action, const char *str)
{
    void(*action_func)(const char *);
    void(*actions[])(const char *) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };

    actions[action](str);
}
