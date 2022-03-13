#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct AdjListNode
{
	int dest;
	double weight;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode* head;
};

struct Graph
{
	int V, w, k;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, double weight);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest, double weight);
void writeGraph(struct Graph* graph, FILE* f);
struct Graph* readGraph(FILE* f);