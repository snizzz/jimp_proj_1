#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "graf.h"
#include "bfs.h"

void push(struct Queue* queue, int dest)
{
	while(queue->next != NULL) queue = queue->next;
	struct Queue* new = (struct Queue*) malloc(sizeof(struct Queue));
	new->dest = dest;
	new->next = NULL;
	queue->next=new;
}

struct Queue* pop_delete(struct Queue* queue)
{
	struct Queue *temp = queue;
	queue=queue->next;
	free(temp);
	return queue;
}

int pop(struct Queue* queue)
{
	return queue->dest;
}

bool if_connected(struct Graph* graph)
{
	bool *visited = malloc((graph->k*graph->w)*sizeof*visited);
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	for(int i=0;i<graph->V;i++) visited[i] = false;
	push(queue,0);
	visited[0] = true;
	while(queue!=NULL){
		int w = pop(queue);
	      	struct AdjListNode* pCrawl = graph->array[w+1].head;
		while(pCrawl) {
			if(!visited[pCrawl->dest] && pCrawl->weight !=0){
				push(queue,pCrawl->dest);
				visited[pCrawl->dest] = true;
			}
			pCrawl = pCrawl->next;
		}
		queue = pop_delete(queue);
	}
	for(int i =0; i<graph->V; i++) if(visited[i] == false) return false;
	return true;
}

/*void path_bfs(struct Graph *graph, int start, int dest)
{


}*/

