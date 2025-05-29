/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Rush 02
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
}

void string_destroy(string_t *this)
{
    free(this->str);
}

void assign_s(string_t *this, const string_t *str)
{
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    this->str = strdup(s);
}

void append_s(string_t *this, const string_t *ap)
{
    strcat(this->str, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    strcat(this->str, ap);
}

char at(const string_t *this, size_t pos)
{
    int stringLength = strlen(this->str);

    stringLength -= 2;
    if (this->str[pos] != NULL && pos < stringLength){
        return this->str[pos];
    } else {
        return -1;
    }
}

void clear(string_t *this)
{
    free(this->str);
    string_init(this, "");
}

int length(const string_t *this)
{
    return strlen(this->str);
}

int compare_s(const string_t *this, const string_t *str)
{
    return strcmp(this->str, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    return strcmp(this->str, str);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t length_desired = pos + n;
    size_t string_size = length(this);

    if (pos < string_size && length_desired == string_size){
        strncpy(s, this->str + pos, n);
        return strlen(s);
    }
    return 0;
}

const char *c_str(const string_t *this)
{
    return this->str;
}

int empty(const string_t *this)
{
    if (length(this) == 0){
        return 1;
    } else {
        return 0;
    }
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    int lenstr = length(this);
    char *pfound;

    if (lenstr > 0 || !(pos > lenstr) || !(pos < 0)){
        pfound = strstr(this->str + pos, str->str);
        if (pfound != NULL){
            return (int)(pfound - (this->str + pos));
        }
    }
    return -1;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    int lenstr = length(this);
    char *pfound;

    if (lenstr > 0){
        pfound = strstr(this->str + pos, str);
        if (pfound != NULL){
            return (int)(pfound - (this->str + pos));
        }
    }
    return -1;
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    strcat(this->str + pos, str);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    strcat(this->str + pos, str->str);
}

int to_int(const string_t *this)
{
    size_t slength = length(this);
    int ascii_value = 0;

    for (size_t i = 0; this->str[i] != '\0'; i++){
        ascii_value += toascii(this->str[i]);
    }
    return ascii_value;
}

int atoi_func(const string_t *this)
{
    return atoi(this->str);
}

void print(const string_t *this)
{
    printf("%s", this->str);
}

void join_c(string_t *this, char delim, const char *const *array)
{
    char delim_str[2] = {delim, '\0'};

    for (size_t i = 0; array[i] != NULL; i++){
        if (i != 0){
            strcat(this->str, delim_str);
        }
        strcat(this->str, array[i] + '\0');
    }
}

void join_s(string_t *this, char delim, const string_t *const *array)
{
    char delim_str[2] = {delim, '\0'};

    for (size_t i = 0; array[i]->str != NULL; i++){
        if (i != 0){
            strcat(this->str, delim_str);
        }
        strcat(this->str, array[i]->str + '\0');
    }
}

size_t get_start(const string_t *this, size_t start, int offset)
{
    start = start > strlen(this->str) ? strlen(this->str) : start;
    if (offset < 0){
        start = strlen(this->str) + offset;
    } else {
        start = offset;
    }
    return start;
}

string_t *substr(const string_t *this, int offset, int length)
{
    size_t start;
    size_t copy_length;
    string_t *result;

    result = (string_t *)malloc(sizeof(string_t));
    start = get_start(this, start, offset);
    if (length < 0){
        copy_length = strlen(this->str) - start;
    } else {
        copy_length = length;
    }
    copy_length = (start + copy_length
        > strlen(this->str)) ? (strlen(this->str) - start) : copy_length;
    result->str = (char *)malloc(copy_length + 1);
    strncpy(result->str, this->str + start, copy_length);
    result->str[copy_length] = '\0';
    return result;
}

