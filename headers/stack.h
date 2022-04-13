#ifndef _STACK_H_
#define _STACK_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int top;
	int capacity;
	int* array;
};

struct Stack* createStack(int capacity);
void pushS(struct Stack* stack, int item);
int popS(struct Stack* stack);
int lookS(struct Stack* stack);

#endif
