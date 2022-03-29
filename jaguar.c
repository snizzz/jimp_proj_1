#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "graf.h"
#include "bfs.h"
#include "tlw.h"

int main(int argc, char **argv){
	int mode=0; // 1 dla trybu mode in, 2 dla trybu mode out
	struct Graph* graph=NULL;
	FILE *in, *out;
	for(int i =0; i<argc; i++) {
		if(strcmp(argv[i], "--mode")==0){
			if(strcmp(argv[i+1], "in")==0){
				mode =1;
				if(argv[i+2][0] != '-'){
					in = fopen(argv[i+2], "r");
					if(in == NULL){
						fprintf(stderr, "Nie udalo sie wczytac pliku");
						return EXIT_FAILURE;
					}
					graph = readGraph(in);
				} 
			}
			else if(strcmp(argv[i+1],"out")==0){
				if(argv[i+2][0] != '-'){
					out = fopen(argv[i+2], "w");
					mode = 2;
				}	
			}
			else if(argv[i+1][0] != '-') fprintf(stderr, "BLAD 2: Podano nieprawidlowy argument %s do flagi --mode\n", argv[i+1]);
		}	
	}
	for(int i =1; i<argc; i++){
		if(strcmp(argv[i], "--if_connected") == 0 && mode == 1) {
			if(if_connected(graph)) fprintf(stdout, "Wczytany graf jest spójny\n");
			else if(if_connected(graph)) fprintf(stdout, "Wczytany graf nie jest spójny\n");
		}
	}
	for(int i =1; i <argc; i++) {
		if(strcmp(argv[i], "--tlw") == 0 && mode == 2) {
			int a, b, c=0,d=1;
			if(argv[i+1][0] != '-') {
			       	a = atoi(argv[i+1]);
				if(argv[i+2][0] != '-'){
					b = atoi(argv[i+2]);
					if(argv[i+3][0] != '-') {
						c = atoi(argv[i+3]);
						if(argv[i+4][0] != '-'){
							d = atoi(argv[i+4]);
						}
					}
				}

			}
			graph = generate_tlw(a, b, c, d);
			writeGraph(graph, out);
		}
		else if(strcmp(argv[i], "--tlw") == 0 && mode == 1){
			fprintf(stderr, "BLAD 1: uzyto niewlasciwej flagi --tlw do podanego trybu\n");
		}
	}
	return 0;
}
