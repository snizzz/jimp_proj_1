#include <stdio.h>
#include "graf.h"
#include "stack.h"
struct Path {
	int from;
	double value;
};


void dijkstra(struct Graph* graph, int start, int end);