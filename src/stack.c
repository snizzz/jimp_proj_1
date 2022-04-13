#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"



struct Stack* createStack(int capacity)
{
	struct Stack* stack = malloc(sizeof * stack);
	if (stack == NULL)
		return NULL;
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = malloc(stack->capacity * sizeof(int));
	return stack;
}

void pushS(struct Stack* stack, int item)
{
	if (stack->top == stack->capacity - 1)
		return EXIT_FAILURE;
	stack->array[++stack->top] = item;
}
int popS(struct Stack* stack)
{
	if (stack->top == -1)
		return EXIT_FAILURE;
	return stack->array[stack->top--];
}

int lookS(struct Stack* stack)
{
	if (stack->top == stack->capacity - 1)
		return EXIT_FAILURE;
	return stack->array[stack->top];
}

