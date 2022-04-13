#include <stdio.h>
#include "../headers/graf.h"

int main(int argc, char** argv) {

	FILE* f = argc > 1 ? fopen(argv[1], "r") : stdin;
	FILE* g = argc > 2 ? fopen(argv[2], "w") : stdout;
	if (f == NULL) printf("Pusty plik");
	struct Graph* graph = readGraph(f);
	writeGraph(graph, g);
	fclose(f);
	fclose(g);
	return 0;
}

