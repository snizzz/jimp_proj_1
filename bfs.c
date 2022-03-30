#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "graf.h"
#include "bfs.h"
bool if_connected(struct Graph* graph)
{
	bool *odwiedzone = malloc((graph->k*graph->w)*sizeof*odwiedzone);
	int *kolejka = malloc((graph->k*graph->w)*sizeof*kolejka);
	for(int i =0; i<graph->k*graph->w;i++) kolejka[i]=-1;
	for(int i=0;i<graph->V;i++) odwiedzone[i] = false;
	kolejka[0] = 0;
	odwiedzone[0] = true;
	int kolejka_licznik=1;
	for(int i=0; i<graph->V; i++){
		int w = kolejka[i];
	      	struct AdjListNode* pCrawl = graph->array[i+1].head;
		while(pCrawl) {
			int j =0;
			if(!odwiedzone[pCrawl->dest] && pCrawl->weight !=0){
				kolejka[kolejka_licznik++] = pCrawl->dest;
				odwiedzone[pCrawl->dest] = true;
			}
			pCrawl = pCrawl->next;
			j++;
		}
	}
	for(int i =0; i<graph->V; i++) if(odwiedzone[i] == false) return false;
	return true;
}

/*void path_bfs(struct Graph *graph, int start, int dest)
{


}*/

