#ifndef _PQ_H_
#define _PQ_H_

typedef struct Que {
	int value;
	double priority;
	struct Que* next;

}Queue;

void addpQ(Queue** que, int x, double priority);
int emptypQ(Queue** que);
int poppQ(Queue** que);
void freepQ(Queue** que);

#endif
