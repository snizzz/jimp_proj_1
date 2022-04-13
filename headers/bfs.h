#ifndef _BFS_H_
#define _BFS_H_

#include <stdio.h>
#include <stdbool.h>

struct Queue
{
	int dest;
	struct Queue* next;
};

void push(struct Queue* queue, int dest);
struct Queue* popDelete(struct Queue* queue);
int pop(struct Queue* queue);
bool ifConnected(struct Graph* graph);

#endif
