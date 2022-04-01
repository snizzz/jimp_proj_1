#include <stdio.h>
#include <stdbool.h>

struct Queue
{
	int dest;
	struct Queue* next;
};

void push(struct Queue* queue, int dest);
struct Queue* pop_delete(struct Queue* queue);
int pop(struct Queue* queue);
bool if_connected(struct Graph* graph);
//void path_bfs(struct Graph* graph, int start, int dest);
