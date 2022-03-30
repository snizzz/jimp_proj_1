#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include "graf.h"
#include "stack.h"
struct Path {
	int from;
	double value;
};


void dijkstra(struct Graph* graph, int start, int end);

#endif 

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
