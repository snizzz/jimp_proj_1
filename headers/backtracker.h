#ifndef _BACKTRACKER_H_
#define _BACKTRACKER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct VertexT {
	int path_n;
	int path_s;
	int path_w;
	int path_e;
	int direction_count;
	int visited;

}Vertex;

struct Graph* generateBt(int n, int m, double w1, double w2);

#endif
