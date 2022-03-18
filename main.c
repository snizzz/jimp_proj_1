#include <stdio.h>
#include "graf.h"
int main(int argc, char** argv) {
	void writeGraphtest(struct Graph* graph, FILE *f)
	{
		int v;
		for (v = 1; v < graph->V+1; ++v) {
			struct AdjListNode* pCrawl = graph->array[v].head;
			printf("\n Adjacency list of vertex %d\n head ", v-1);
			while (pCrawl) {
				printf(" -%lf->%d", pCrawl->weight, pCrawl->dest);
				pCrawl = pCrawl->next;
			}
			printf("\n");
		}
	}
	FILE* f = fopen("mygraph", "r");
	FILE* g = fopen("wynik", "w");
	if(f == NULL) printf("Pusty plik");
	struct Graph* graph = readGraph(f);
	writeGraphtest(graph, f);
	writeGraph(graph,g);
	return 0;
}
