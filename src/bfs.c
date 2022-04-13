#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../headers/graf.h"
#include "../headers/bfs.h"

void push(struct Queue* queue, int dest)
{
	while (queue->next != NULL) queue = queue->next;
	struct Queue* new = (struct Queue*)malloc(sizeof(struct Queue));
	new->dest = dest;
	new->next = NULL;
	queue->next = new;
}

struct Queue* popDelete(struct Queue* queue)
{
	struct Queue* temp = queue;
	queue = queue->next;
	free(temp);
	return queue;
}

int pop(struct Queue* queue)
{
	return queue->dest;
}

bool ifConnected(struct Graph* graph)
{
	bool* visited = malloc((graph->k * graph->w) * sizeof * visited);
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	for (int i = 0; i < graph->k * graph->w; i++) visited[i] = false;
	push(queue, 0);
	visited[0] = true;
	while (queue != NULL) {
		int w = pop(queue);
		struct Neighbors* neighbors = graph->array[w + 1];
		while (neighbors) {
			if (!visited[neighbors->dest] && neighbors->weight != 0) {
				push(queue, neighbors->dest);
				visited[neighbors->dest] = true;
			}
			neighbors = neighbors->next;
		}
		queue = popDelete(queue);
	}
	for (int i = 0; i < graph->k * graph->w; i++) if (visited[i] == false) return false;
	return true;
}




