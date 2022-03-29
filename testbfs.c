#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "bfs.h"
#include "graf.h"

int main(int argc, char **argv){
	FILE *f = argc > 1 ? fopen(argv[1], "r") : stdin;
	struct Graph* graph = readGraph(f);
	bool wynik =if_connected(graph);
	if(wynik) printf("spojny\n");
	else printf("niespojny\n");	
}
