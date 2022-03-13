#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graf.h"
#include "stack.h"


typedef struct vertex_t {
	int path_n;
	int path_s;
	int path_w;
	int path_e;
	int direction_count;
	int visited;

}vertex_t;

struct Graph* generate_bt(int n, int m);