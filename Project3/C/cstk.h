#ifndef CSTK_H
#define CSTK_H

typedef struct Stack
{
    int *data;     // pointer to the start of the data for the stack
    int *top;      // points to the next place to insert in the stack
    int capacity;  // the maximal size of the stack
} Stack;

/* Creates a Stack with a maximal capacity specified by the int value */
Stack *stk_create(int);

/* Returns 1 if the given Stack is empty, otherwise 0 */
int stk_empty(Stack *);

/* Returns 1 if the given Stack is full, otherwise 0 */
int stk_full(Stack *);

/* Adds a new value to the top of the stack if there's space.
   If there's no space, prints a warning but does nothing. */
void stk_push(Stack *, int);

/* Returns the value on top of the stack if it exists.
   Otherwise prints a warning and returns 0. */
int stk_peek(Stack *);

/* Removes and returns the value on top of the stack if it exists.
   Otherwise prints a warning and returns 0. */
int stk_pop(Stack *);

/* Prints the stack in reverse order (LILO) if the int is 1,
   otherwise in original order (LIFO). */
void stk_display(Stack *, int);

/* Frees up the memory */
void stk_destroy(Stack *);

/* Copies the contents into another Stack of the same maximal size and returns it */
Stack *stk_copy(Stack *);

#endif /* CSTK_H */
