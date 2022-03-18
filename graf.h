#include <stdio.h>

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
void addEdge(struct Graph* graph, int src, int dest, double weight);
struct Graph* createGraph(int V);
struct AdjListNode* newAdjListNode(int dest, double weight);
void writeGraph(struct Graph* graph, FILE* f);
struct Graph* readGraph(FILE* f);
