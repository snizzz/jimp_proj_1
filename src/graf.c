#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/graf.h"

struct Graph* makeGraph(int w, int k)
{
	struct Graph* graph = (struct Graph*)
		malloc(sizeof(struct Graph));
	graph->w = w;
	graph->k = k;

	graph->array = (struct Neighbors**)
		malloc((w * k) * sizeof(struct Neighbors*));

	return graph;
}

void addToGraph(struct Graph* graph, int src, int dest, double weight)
{
	struct Neighbors* newNode = (struct Neighbors*)malloc(sizeof(struct Neighbors));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	newNode->next = graph->array[src];
	graph->array[src] = newNode;
}

void writeGraph(struct Graph* graph, FILE* file)
{
	fprintf(file, "%d %d\n", graph->w, graph->k);
	for (int i = 0; i < (graph->w * graph->k); i++) {
		struct Neighbors* neighbors = graph->array[i];
		fprintf(file, "\t ");
		while (neighbors) {
			if (!(neighbors->next)) {
				fprintf(file, "%d :%lf ", neighbors->dest, neighbors->weight);
			}
			else fprintf(file, "%d :%lf  ", neighbors->dest, neighbors->weight);
			neighbors = neighbors->next;
		}
		fprintf(file, "\n");
	}
}


struct Graph* readGraph(FILE* file) {
	int w, k;
	char str[12];
	fgets(str, 12, file);
	if (sscanf(str, "%d %d", &w, &k) != 2) {
		fprintf(stderr, "BŁĄD 5: niewłaściwy format danych wejściowych w pliku\n");
		exit(0);
	}
	else {
		struct Graph* graph = makeGraph(w, k);
		graph->w = w;
		graph->k = k;
		int dest;
		double waga;
		char check, check1;
		for (int i = 0; i < w * k; i++) {
			while (fscanf(file, "%d :%lf%c%c ", &dest, &waga, &check, &check1) == 4) {
				addToGraph(graph, i, dest, waga);
				if (check == '\n' || check1 == '\n') break;
			}
		}
		return graph;
	}
}
