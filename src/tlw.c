#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/graf.h"
#include "../headers/tlw.h"

struct Graph* generateTlw(int w, int k, double w1, double w2) {
	struct Graph* graph = makeGraph(w, k);
	graph->w = w;
	graph->k = k;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++) {
			int dest = k * i + j;
			srand(time(NULL));
			double r1 = w1 + (w2 - w1) * rand() / RAND_MAX;
			double r2 = w1 + (w2 - w1) * rand() / RAND_MAX;
			double r3 = w1 + (w2 - w1) * rand() / RAND_MAX;
			double r4 = w1 + (w2 - w1) * rand() / RAND_MAX;
			if (i == 0 && j == 0) {
				addToGraph(graph, dest, j + 1, r1);
				addToGraph(graph, dest, k, r2);
			}
			else if (i == 0 && j == k - 1) {
				addToGraph(graph, dest, j - 1, r3);
				addToGraph(graph, dest, k + j, r4);
			}
			else if (w * k - k == k * i + j) {
				addToGraph(graph, dest, k * i + 1, r1);
				addToGraph(graph, dest, k * i - k, r2);
			}
			else if (w * k - 1 == k * i + j) {
				addToGraph(graph, dest, k * i - 1, r3);
				addToGraph(graph, dest, k * i + j - 1, r4);
			}
			else if (j == 0) {
				addToGraph(graph, dest, k * i - k, r1);
				addToGraph(graph, dest, k * i + k, r2);
				addToGraph(graph, dest, k * i + 1, r3);
			}
			else if (i == 0) {
				addToGraph(graph, dest, j - 1, r4);
				addToGraph(graph, dest, j + 1, r1);
				addToGraph(graph, dest, k + j, r2);
			}
			else if (j == k - 1) {
				addToGraph(graph, dest, k * i - 1 + j, r3);
				addToGraph(graph, dest, k * i + j - k, r4);
				addToGraph(graph, dest, k * i + k + j, r1);
			}
			else if (i == w - 1) {
				addToGraph(graph, dest, k * i + j - 1, r2);
				addToGraph(graph, dest, k * i + j + 1, r3);
				addToGraph(graph, dest, k * i + j - k, r4);
			}
			else {
				addToGraph(graph, dest, k * i + j + 1, r1);
				addToGraph(graph, dest, k * i + j - 1, r2);
				addToGraph(graph, dest, k * i + j - k, r3);
				addToGraph(graph, dest, k * i + j + k, r4);
			}

		}
	}
	return graph;
}

