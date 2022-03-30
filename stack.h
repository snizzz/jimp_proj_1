#ifndef _STACK_H_
#define _STACK_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack;
struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty2(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int peek(struct Stack* stack);

#endif
