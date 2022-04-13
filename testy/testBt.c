#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../headers/backtracker.h"
#include "../headers/graf.h"
#include "../headers/bfs.h"


int main(int argc, char** argv) {
	FILE* out = argc > 1 ? fopen(argv[1], "w") : fopen("testBackTracker", "w");
	int a = argc > 2 ? atoi(argv[2]) : 4;
	int b = argc > 3 ? atoi(argv[3]) : 3;
	double w1 = argc > 4 ? atof(argv[4]) : 0;
	double w2 = argc > 5 ? atof(argv[5]) : 1;
	struct Graph* graph = generateBt(a, b, w1, w2);
	writeGraph(graph, out);
	fclose(out);
	free(graph->array);
	free(graph);
	FILE* in = argc > 1 ? fopen(argv[1], "r") : fopen("testBackTracker", "r");
	graph = readGraph(in);
	if (if_connected(graph) == true) {
		fprintf(stdout, "\nTEST BACKTRACKER SUCESSFULL\n");
		return EXIT_SUCCESS;

	}
	else {
		fprintf(stderr, "\nTEST BACKTRACKER UNSUCESSFULL <graph not connected>\n");
		return EXIT_FAILURE;
	}
	free(graph->array);
	free(graph);

	return 0;
}
