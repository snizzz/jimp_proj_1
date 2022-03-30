#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "graf.h"
#include "stack.h"




void dijkstra(struct Graph* graph, int start, int end) {
	int V = graph->k * graph->w;

	struct Path* pathto = malloc(V * sizeof(struct Path));

	struct AdjListNode* vertex = graph->array[0].head;

	struct Stack* stack = createStack(V);

	double minw = 10000.0;
	int next;
	int current=start;

	int** sasiedzi = malloc(V * sizeof(int*));
	int* nsasiedzi = malloc(V * sizeof(int));

	for (int i = 0; i < V; i++) {
		vertex = graph->array[i].head;
		int j = 0;
		while (vertex->next != NULL) {
			j++;
			vertex = vertex->next;
		}
		nsasiedzi[i] = j;
		sasiedzi[i] = malloc(3*j * sizeof(int));
		vertex = graph->array[i].head;
		for (int k = 0; k < 3*j; k+=3) {
			sasiedzi[i][k] = vertex->dest;
			sasiedzi[i][k + 1] = 0;
			sasiedzi[i][k + 2] = 0;
		}
	}

	vertex = graph->array[start].head;

	while (vertex->next != NULL) {
		pathto[vertex->dest].from = start;
		pathto[vertex->dest].value = vertex->weight;
		if (vertex->weight < minw) {
			next = vertex->dest;
			minw = vertex->weight;
		}
		vertex = vertex->next;
	}
	push(stack, start);


	while (isEmpty2(stack) != 1) {
		minw = 100000;
		current = next;
		int suma = 0;
		for (int i = 0; i < 3*nsasiedzi[current]; i+=3) {
			suma += (sasiedzi[current][i+1] + sasiedzi[current][i+2]);
		}
		if (suma != nsasiedzi[current]) {
			vertex = graph->array[current].head;
			int n = 1;
			while (vertex->next != NULL) {
				if (pathto[vertex->dest].value > (pathto[current].value + vertex->weight)) {
					pathto[vertex->dest].from = current;
					pathto[vertex->dest].value = pathto[current].value + vertex->weight;
				}
				if (sasiedzi[current][n + 1] == 0|| sasiedzi[current][n + 2] == 0) {
					if (pathto[vertex->dest].value < minw) {
						next = vertex->dest;
						minw = vertex->weight;
					}

				}

				sasiedzi[current][n + 1] = 1;
				vertex = vertex->next;
				n += 3;
			}
			for (int l = 0; l < nsasiedzi[next] * 3; l += 3) {
				if (sasiedzi[next][l] == current) {
					sasiedzi[next][l + 2] = 1;
				}
			}
			if (minw == 100000) {
				next = pop(stack);
			}
			else 
				push(stack, current);
		}
		else {
			next=pop(stack);
		}
	}


	struct Stack* stack2 = createStack(V);
	current = end;
	while (current != start) {
		push(stack2, current);
		current = pathto[current].from;
	}
	
	printf("%d", start);
	while (isEmpty2(stack2) != 1) {
		printf("->%d", pop(stack2));
	}
	printf("\n");

}
