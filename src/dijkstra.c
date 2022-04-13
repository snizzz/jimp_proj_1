#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "../headers/prioque.h"
#include "../headers/dijkstra.h"
#include "../headers/graf.h"
#define INFINI DBL_MAX


void dijkstra(struct Graph* graph, int start, int end, char t) {

	if (start<0 || end>(graph->k * graph->w - 1)) {
		fprintf(stderr, "\n<jaguar>: start:%d end:%d niepoprawne wierzcholki\n\n", start, end);
		exit(0);
	}
	int* predecesor = malloc((graph->w * graph->k) * sizeof(int));
	double* distance = malloc((graph->w * graph->k) * sizeof(double));
	int* visited = malloc((graph->w * graph->k) * sizeof(int));

	for (int i = 0; i < (graph->w * graph->k); i++) {
		predecesor[i] = -1;
		distance[i] = INFINI;
		visited[i] = 0;
	}

	distance[start] = 0.0;

	Queue* que = malloc(sizeof(Queue));
	if (start == 0) {
		que->value = 1;
		que->priority = distance[1];
		que->next = NULL;
	}
	else {
		que->value = 0;
		que->priority = distance[0];
		que->next = NULL;
	}

	for (int i = 0; i < (graph->w * graph->k); i++) {
		if (i != start)
			addpQ(&que, i, distance[i]);

	}

	int current = start;
	do {
		struct Neighbors* neighbors = graph->array[current + 1];
		while (neighbors) {
			if (distance[neighbors->dest] > (distance[current] + neighbors->weight)) {
				distance[neighbors->dest] = (distance[current] + neighbors->weight);
				predecesor[neighbors->dest] = current;
				addpQ(&que, neighbors->dest, distance[neighbors->dest]);
			}
			neighbors = neighbors->next;
		}
		visited[current] = 1;
		current = poppQ(&que);
		while (1 == 1) {
			if (emptypQ(&que) == 1) break;
			if (visited[current] == 0) break;
			current = poppQ(&que);
		}
	} while (!emptypQ(&que));

	freepQ(&que);

	if (distance[end] == INFINI) {
		printf("Path between %d and %d doesnt exist\n", start, end);
	}
	else {
		current = end;
		int i = 0;
		while (current != start) {
			i++;
			current = predecesor[current];
		}
		int* anwser = malloc(i * sizeof(int));

		current = end;
		for (int j = i - 1; j >= 0; j--) {
			anwser[j] = current;
			current = predecesor[current];
		}

		if (t == 'w') {

			printf("%d", start);
			for (int j = 0; j < i; j++) {
				printf("-%f->%d", distance[anwser[j]], anwser[j]);
			}
		}
		else {
			printf("%d", start);
			for (int j = 0; j < i; j++) {
				printf("->%d", anwser[j]);
			}
		}

		printf("\n");
		free(anwser);
	}

	free(predecesor);
	free(distance);
	free(visited);


}
