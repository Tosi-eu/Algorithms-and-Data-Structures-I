#ifndef QUEUE_H
#define QUEUE_H

#define true 0
#define false 1
#define MAX 100

#define IMPOSSIBLE 0
#define QUEUE 2
#define STACK 1
#define UNDEFINED 3

//pilha e fila são TAD's que possuem grande parte dos ponteiros e comum, assim como uma lista, dessa forma, em Queue.h 
//se encontram ponteiros para as duas ED's, uma vez que se fossemos separar em arquivos diferentes, seria muito mais fácil de haver
//erro de incompatibilidade, pois o gcc identificaria uma estrtura TipoElemento em dois .h diferentes, por explo. Dessa maneira é mais trivial a visualização.

typedef int KEY_ST; //TipoChave
typedef int boolean; //tipo bool

typedef struct
{
  KEY_ST key[MAX]; //comum para pilha e fila
} ELEMENT_ST;

typedef struct KNOT_ST *pointerType; //comum para pilha e fila

typedef struct KNOT_ST
{
	ELEMENT_ST element; //comum para pilha e fila
	pointerType next; //comum para pilha e fila
} KNOT_ST;

typedef struct
{
	pointerType first, last; //exclusivo da fila
    pointerType top; //exclusivo da pilha
} QUEUE_STACK_ST;

void createQueue(QUEUE_STACK_ST *queue);//criação da fila 
boolean enqueue(QUEUE_STACK_ST *queue, ELEMENT_ST element);//insere novos elementos na fila
boolean dequeue(QUEUE_STACK_ST *queue,ELEMENT_ST element);//remove elementos da fila -> pré conndição: existir o elemento
boolean emptyQueue(QUEUE_STACK_ST *queue);//retona true se vazia, false se tem elemento(s)
void freeQueueKnots(QUEUE_STACK_ST *queue);//libera os nós da fila

#endif