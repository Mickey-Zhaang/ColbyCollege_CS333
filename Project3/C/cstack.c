#include <stdio.h>
#include <stdlib.h>
#include "cstk.h"

Stack *stk_create(int capacity) {
    // allocate memory for a Stack struct 
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

int stk_empty(Stack *s) {
    if (s == NULL) return 1;
    return s->top == s->data;
}

int stk_full(Stack *s) {
    if (s == NULL) return 1;
    return s->top >= s->data + s->capacity;
}

void stk_push(Stack *s, int val) {
    if (s == NULL) return;
    if (stk_full(s)) {
        fprintf(stderr, "Warning: stack full, cannot push.\n");
        return;
    }
    *s->top = val;
    s->top++;
}

int stk_peek(Stack *s) {
    if (s == NULL || stk_empty(s)) {
        fprintf(stderr, "Warning: cannot peek empty stack.\n");
        return 0;
    }
    return *(s->top - 1);
}

int stk_pop(Stack *s) {
    if (s == NULL || stk_empty(s)) {
        fprintf(stderr, "Warning: cannot pop empty stack.\n");
        return 0;
    }
    s->top--;
    return *s->top;
}

void stk_display(Stack *s, int reverse) {
    if (s == NULL) return;
    if (stk_empty(s)) {
        printf("[]\n");
        return;
    }
    if (reverse) {
        for (int *p = s->data; p < s->top; p++)
            printf("%d ", *p);
    } else {
        for (int *p = s->top - 1; p >= s->data; p--)
            printf("%d ", *p);
    }
    printf("\n");
}

void stk_destroy(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
}

Stack *stk_copy(Stack *s) {
    if (s == NULL) return NULL;
    Stack *copy = stk_create(s->capacity);
    if (copy == NULL) return NULL;
    for (int *p = s->data; p < s->top; p++)
        stk_push(copy, *p);
    return copy;
}