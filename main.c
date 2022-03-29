#include <stdio.h>
#include "graf.h"
void writeGraphtest(struct Graph * graph, FILE *f);

int main(int argc, char** argv) {
	
	FILE* f = argc > 1 ? fopen(argv[1], "r") : stdin;
	FILE* g = argc > 2 ? fopen(argv[2], "w") : stdout;
	if(f == NULL) printf("Pusty plik");
	struct Graph* graph = readGraph(f);
	writeGraphtest(graph, g);
	writeGraph(graph,g);
	fclose(f);
	fclose(g);
	return 0;
}

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
