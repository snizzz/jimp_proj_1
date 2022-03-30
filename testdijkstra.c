#include <stdio.h>
#include "graf.h"
#include "dijkstra.h"



int main(int argc, char* argv[]) {
	printf("%d  l %d\n",atoi(argv[2]),atoi(argv[3]));
	FILE* f =  fopen(argv[1], "r");
	if(f == NULL) printf("Pusty plik");
	printf("%d %d\n",atoi(argv[2]),atoi(argv[3]));

	struct Graph* graph = readGraph(f);
	dijkstra(graph, atoi(argv[2]), atoi(argv[3]));
	fclose(f);
	return 0;
}
