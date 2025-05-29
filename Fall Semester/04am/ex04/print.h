#ifndef PRINT_H
#define PRINT_H

typedef enum {
    NORMAL,
    REVERSE,
    UPPER,
    FORTY_TWO
} action_t;

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

#endif