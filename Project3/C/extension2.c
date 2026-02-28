/*
 * Extension 3: Robust stack with auto-expand and extra library functions
 * - Handles overflow by doubling capacity when full (no silent failure).
 * - Additional functions: size, clear, copy, shrink_to_fit.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Expandable stack: same idea as Stack but capacity can grow on push when full */
typedef struct {
    int *data;     /* pointer to the start of the backing array */
    int *top;      /* points to the next place to insert (one past top element) */
    int capacity;  /* current max size of the backing array */
} ExpStack;

/* Allocate an expandable stack with initial capacity cap. Returns NULL on failure. */
static ExpStack *estk_create(int cap) {
    ExpStack *s = malloc(sizeof(ExpStack));
    if (!s) return NULL;

    /* allocate the backing array for stack elements */
    s->data = malloc((size_t)cap * sizeof(int));
    if (!s->data) {
        free(s);  /* don't leak the struct if array allocation failed */
        return NULL;
    }

    s->top = s->data;  /* stack is empty: top points to first slot */
    s->capacity = cap;
    return s;
}

/* Return 1 if stack is empty (or s is NULL), otherwise 0. */
static int estk_empty(ExpStack *s) {
    return !s || s->top == s->data;
}

/* Return the number of elements currently on the stack. */
static int estk_size(ExpStack *s) {
    return s ? (int)(s->top - s->data) : 0;
}

/* Double the backing array size via realloc. Returns 1 on success, 0 on failure. */
static int estk_grow(ExpStack *s) {
    int new_cap = s->capacity * 2;
    int *new_data = realloc(s->data, (size_t)new_cap * sizeof(int));
    if (!new_data) return 0;

    /* realloc may move the block; update top to point into the new block */
    s->top = new_data + (s->top - s->data);
    s->data = new_data;
    s->capacity = new_cap;
    return 1;
}

/* Push val onto the stack. If full, grow the array first; report error only if grow fails. */
static void estk_push(ExpStack *s, int val) {
    if (!s) return;

    /* if no room, try to double capacity */
    if (s->top >= s->data + s->capacity)
        if (!estk_grow(s)) {
            fprintf(stderr, "Error: cannot grow stack (out of memory).\n");
            return;
        }

    *s->top = val;
    s->top++;
}

/* Return the value on top without removing it. Warn and return 0 if empty. */
static int estk_peek(ExpStack *s) {
    if (!s || estk_empty(s)) {
        fprintf(stderr, "Warning: peek on empty stack.\n");
        return 0;
    }
    return *(s->top - 1);
}

/* Remove and return the top value. Warn and return 0 if empty. */
static int estk_pop(ExpStack *s) {
    if (!s || estk_empty(s)) {
        fprintf(stderr, "Warning: pop on empty stack.\n");
        return 0;
    }
    s->top--;
    return *s->top;
}

/* Reset stack to empty without freeing the backing array (capacity unchanged). */
static void estk_clear(ExpStack *s) {
    if (s) s->top = s->data;
}

/* Free the backing array and the stack struct. */
static void estk_destroy(ExpStack *s) {
    if (s) {
        free(s->data);
        free(s);
    }
}

/* Allocate a new stack with the same capacity and copy all elements onto it. */
static ExpStack *estk_copy(ExpStack *s) {
    if (!s) return NULL;

    ExpStack *c = estk_create(s->capacity);
    if (!c) return NULL;

    for (int *p = s->data; p < s->top; p++)
        *c->top++ = *p;
    return c;
}

/* Shrink the backing array to exactly fit current size (frees unused capacity). */
static int estk_shrink_to_fit(ExpStack *s) {
    if (!s || estk_empty(s)) return 1;

    int n = estk_size(s);
    int *new_data = realloc(s->data, (size_t)n * sizeof(int));
    if (!new_data) return 0;

    s->data = new_data;
    s->top = s->data + n;
    s->capacity = n;
    return 1;
}

int main(void) {
    /* Demo 1: start with capacity 2, push 1..10 to show auto-expand */
    ExpStack *s = estk_create(2);
    if (!s) return 1;

    printf("Push 1..10 (initial capacity 2, will auto-expand):\n");
    for (int i = 1; i <= 10; i++)
        estk_push(s, i);
    printf("  size=%d capacity=%d\n", estk_size(s), s->capacity);

    printf("Pop until empty: ");
    while (!estk_empty(s))
        printf("%d ", estk_pop(s));
    printf("\n");
    estk_destroy(s);

    /* Demo 2: copy stack, then clear original and show copy still has the data */
    s = estk_create(4);
    estk_push(s, 10), estk_push(s, 20), estk_push(s, 30);
    ExpStack *c = estk_copy(s);
    estk_clear(s);
    printf("After clear, size=%d. Copy contents: ", estk_size(s));
    while (!estk_empty(c)) printf("%d ", estk_pop(c));
    printf("\n");
    estk_destroy(s);
    estk_destroy(c);
    return 0;
}
