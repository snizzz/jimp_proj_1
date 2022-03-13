#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "graf.h"

struct AdjListNode* newAdjListNode(int dest, double weight)
{
	struct AdjListNode* newNode =
		(struct AdjListNode*)
		malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)
		malloc(sizeof(struct Graph));
	graph->V = V;

	graph->array = (struct AdjList*)
		malloc(V * sizeof(struct AdjList));

	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest, double weight)
{
	struct AdjListNode* newNode = newAdjListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
}

void writeGraph(struct Graph* graph, FILE *f)
{
	fprintf(f, "%d %d\n", graph->w, graph->k);
	int v;
	for (v = 1; v < graph->V+1; ++v) {
		struct AdjListNode* pCrawl = graph->array[v].head;
		fprintf(f, "\t ");
		while (pCrawl) {
			fprintf(f, "%d :%lf   ", pCrawl->dest, pCrawl->weight);
			pCrawl = pCrawl->next;
		}
		fprintf(f, "\n");
	}
}


struct Graph* readGraph(FILE* f) {
	int w, k;
	char str[4];
	fgets(str, 4, f);
	sscanf(str, "%d %d", &w, &k);
	struct Graph* graph = createGraph(w * k);
	graph->w = w;
	graph->k = k;
	int dest, dest1, dest2, dest3;
	double waga, waga1, waga2, waga3;
	char check, check1;
	for (int i =1; i < w * k + 1; i++) {
		while (fscanf(f, "%d :%lf%c%c ", &dest, &waga,&check, &check1)!=EOF) {
			addEdge(graph, i, dest, waga);
			if (check == '\n'|| check1 == '\n') break;
		}
	}
	return graph;
}
