#include <stdlib.h>
#include <stdio.h>
#include "../headers/prioque.h"

void addpQ(Queue** que, int x, double priority) {
	Queue* head = *que;
	Queue* newData = (Queue*)malloc(sizeof(Queue));
	newData->value = x;
	newData->priority = priority;
	newData->next = NULL;

	if (head->priority > priority) {
		newData->next = *que;
		(*que) = newData;
	}
	else {
		while (head->next != NULL) {
			if (head->next->priority > priority) {
				break;
			}
			head = head->next;
		}
		newData->next = head->next;
		head->next = newData;
	}

}

int poppQ(Queue** que) {
	int ret = (*que)->value;
	Queue* head = *que;
	(*que) = (*que)->next;
	free(head);
	return ret;
}


int emptypQ(Queue** que) {
	if ((*que) == NULL) return 1;
	else return 0;
}

void freepQ(Queue** que) {
	Queue* head;
	while ((*que) != NULL) {
		head = *que;
		(*que) = (*que)->next;
		free(head);
	}
}


