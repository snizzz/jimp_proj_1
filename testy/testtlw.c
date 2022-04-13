#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../headers/tlw.h"
#include "../headers/graf.h"


int main(int argc, char** argv) {
	FILE* out = argc > 1 ? fopen(argv[1], "w") : fopen("testtlw", "w");
	int a = argc > 2 ? atoi(argv[2]) : 7;
	int b = argc > 3 ? atoi(argv[3]) : 4;
	double w1 = argc > 4 ? atof(argv[4]) : 0;
	double w2 = argc > 5 ? atof(argv[5]) : 1;
	struct Graph* graph = generateTlw(a, b, w1, w2);
	writeGraph(graph, out);
	fclose(out);
	return 0;
}
