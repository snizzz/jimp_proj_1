#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graf.h"
#include "tlw.h"

struct Graph* generate_tlw(int w, int k, double w1, double w2) {
	struct Graph* graph = createGraph(w*k);
	graph->w =w;
	graph->k =k;
	for(int i =0; i<w;i++){
		for(int j =0; j<k;j++){
			int dest=k*i+j+1;
			time(NULL);
			double r1 = w1 + (w2-w1)*rand()/RAND_MAX;
			double r2 = w1 + (w2-w1)*rand()/RAND_MAX;
			double r3 = w1 + (w2-w1)*rand()/RAND_MAX;
			double r4 = w1 + (w2-w1)*rand()/RAND_MAX;
			if(i==0 && j==0){
				addEdge(graph, dest, j+1, r1);
			       	addEdge(graph, dest, k, r2);	
			}
			else if(i==0 && j==k-1){
				addEdge(graph, dest, j-1, r3);
				addEdge(graph, dest, k+j, r4);
			}
			else if(w*k-k == k*i+j){
				addEdge(graph, dest, k*i+1, r1);
				addEdge(graph, dest, k*i-k, r2);
			}
			else if(w*k-1 == k*i+j){
				addEdge(graph, dest, k*i-1, r3);
				addEdge(graph, dest, k*i+j-1, r4);
			}
			else if(j==0){
				addEdge(graph, dest, k*i-k, r1);
				addEdge(graph, dest, k*i+k, r2);
				addEdge(graph, dest, k*i+1, r3);
			}
			else if(i==0){
				addEdge(graph, dest, j-1, r4);
				addEdge(graph, dest, j+1, r1);
				addEdge(graph, dest, k+j, r2);
			}
			else if(j==k-1) {
				addEdge(graph, dest, k*i-1+j, r3);
				addEdge(graph, dest, k*i+j-k, r4);
				addEdge(graph, dest, k*i+k+j, r1);
			}
			else if(i == w-1) {
				addEdge(graph, dest, k*i+j-1, r2);
				addEdge(graph, dest, k*i+j+1, r3);
				addEdge(graph, dest, k*i+j-k, r4);
			}
			else {
				addEdge(graph, dest, k*i+j+1, r1);
				addEdge(graph, dest, k*i+j-1, r2);
				addEdge(graph, dest, k*i+j-k, r3);
				addEdge(graph, dest, k*i+j+k, r4);
			}

		}
	}
	return graph;	
}

