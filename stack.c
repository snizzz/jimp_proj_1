#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = malloc(sizeof * stack);
    if (stack == NULL)
        return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty2(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
int pop(struct Stack* stack)
{
    if (isEmpty2(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
    if (isEmpty2(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

