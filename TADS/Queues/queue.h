#ifndef QUEUE_H
#define QUEUE_H

#define EXIT -2
#define MAX_TAM 100
#define ERROR_NOT_FOUND -1
#define QUEUE_IS_FULL 0
#define RETURN_SUCCESS 1

typedef int KEY_ST;

typedef struct ELEMENT_ST {
	KEY_ST key;
	char name[50];
} ELEMENT_ST;

typedef struct KNOT_ST *POINTER_ST;
typedef struct KNOT_ST {
	ELEMENT_ST element;
	POINTER_ST next;
} KNOT_ST;

typedef struct {
	POINTER_ST first;
	POINTER_ST last;
} QUEUE_ST;

int create(QUEUE_ST *queue);
int enqueue(QUEUE_ST *queue, ELEMENT_ST elemment);
int dequeue(QUEUE_ST *queue);
KNOT_ST see_next(QUEUE_ST *queue);
int empty(QUEUE_ST *queue);
int full(QUEUE_ST *queue);
int count(QUEUE_ST *queue);
//void print(QUEUE_ST *queue);

#endif