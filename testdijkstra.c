#include <stdio.h>
#include "graf.h"
#include "dijkstra.h"



int main(int argc, char** argv) {
	
	FILE* f =  fopen(argv[1], "r");
	if(f == NULL) printf("Pusty plik");
	struct Graph* graph = readGraph(f);
	dijkstra(graph, argv[2], argv[3]);
	fclose(f);
	return 0;
}