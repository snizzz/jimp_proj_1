#include <stdio.h>
#include "../headers/graf.h"
#include "../headers/dijkstra.h"



int main(int argc, char* argv[]) {
	FILE* f = fopen(argv[1], "r");
	if (f == NULL) fprintf(stderr,"Zly plik\n");
	struct Graph* graph = readGraph(f);
	dijkstra(graph, atoi(argv[2]), atoi(argv[3]));
	fclose(f);
	return 0;
}
