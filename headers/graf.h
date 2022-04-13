#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>

struct Neighbors
{
	int dest;
	double weight;
	struct Neighbors* next;
};

struct Graph
{
	int w, k;
	struct Neighbors** array;
};

void addToGraph(struct Graph* graph, int src, int dest, double weight);
struct Graph* makeGraph(int w, int k);
void writeGraph(struct Graph* graph, FILE* file);
struct Graph* readGraph(FILE* file);

#endif
