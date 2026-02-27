#include <stdio.h>
#include <stdlib.h>
#include "cstk.h"

Stack *stk_create(int capacity) {
    // allocate memory for a Stack struct (lowercase 'sizeof' in C)
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL) return NULL;

    // allocate memory for the stack (underlying array)
    int *arr = malloc(capacity * sizeof(int));
    if (arr == NULL) {
        free(s);  // don't leak the struct if array allocation failed
        return NULL;
    }

    s->data = arr;
    s->top = arr;
    s->capacity = capacity;
    return s;
}