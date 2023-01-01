#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static int num_nos;

int create(QUEUE_ST *queue) {
	queue->first = NULL;
	queue->last = NULL;
	num_nos = 0;
}

int enqueue(QUEUE_ST *queue, ELEMENT_ST element) {

	POINTER_ST new_element = (POINTER_ST) malloc(sizeof(KNOT_ST));
	if (new_element == NULL)
		return QUEUE_IS_FULL;

	new_element->element = element;
	new_element->next = NULL;
	
	if (empty(queue)) {
		queue->first = new_element;
	} else {
		queue->last->next = new_element;
	}
	queue->last = new_element;
	num_nos++;

	return EXIT_SUCCESS;

}


int dequeue(QUEUE_ST *queue) {

	if (empty(queue)) 
		return ERROR_NOT_FOUND;

	if (queue->first == queue->last) // unitaria
		queue->last = NULL;

	POINTER_ST aux = queue->first;
	queue->first = queue->first->next;
	free(aux);

	num_nos--;

	return EXIT_SUCCESS;

}

KNOT_ST see_next(QUEUE_ST *queue) {
	//TODO
	/*if (empty(queue))
		return NO_VAZIO;*/ 
	return *(queue->first);
}

int empty(QUEUE_ST *queue) {
	if(queue->first == NULL &&
		queue->last == NULL)
		return 1;
	else
		return 0;
}

int full(QUEUE_ST *queue) {

}

int count(QUEUE_ST *queue) {
	return num_nos;
}

void print(QUEUE_ST *queue);