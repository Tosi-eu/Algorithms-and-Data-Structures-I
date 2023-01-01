#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "utils.h"

//ao criar a fila, basta o primeiro e o último apontarem para NULL
void createQueue(QUEUE_STACK_ST *queue)
{
  queue->first = NULL;
  queue->last = NULL;
}

//função enqueue promete inserir no fim da fila, corroborando com a propriedade FIFO da fila
boolean enqueue(QUEUE_STACK_ST *queue, ELEMENT_ST element)
{

  pointerType newElement = (pointerType)malloc(sizeof(KNOT_ST));

  if (newElement == NULL)
    {
      return false;//se der erro de alocaçao 
    }else{
        newElement->element = element;
        newElement->next = NULL;
    }

  if (emptyQueue(queue)) {
    queue->first = newElement;//se vazia
  } else {
    queue->last->next = newElement;//se !vazia e !cheia
  }

  queue->last = newElement;

  return true;
}

//dequeue é remoção de fila, como fila é FIFO, a função promete remover o primeiro elemento da fila
boolean dequeue(QUEUE_STACK_ST *queue, ELEMENT_ST element)
{
  if (emptyQueue(queue)){
    return false; //fila já vazia
  }
  
  if (elementExist(queue->first->element, *(element.key)) == false) {
    return false; //fila sem o elemento procurado
  }
  
  if (queue->first == queue->last) {
    queue->last = NULL; //remoção em uma fila com um elemento
  }
 
  pointerType aux = queue->first;//auxiliar para não perder o ponteiro da fila
  queue->first = queue->first->next;

  free(aux);
  return true;
}

//booleano que verifica se a pilha/fila está vazia
boolean emptyQueue(QUEUE_STACK_ST *queue)
{
  if (queue->last == NULL && queue->first == NULL) {
    return false; //vazia
  } else
    return true; //!vazia
} 

//função que libera os nós da fila 
void freeQueueKnots(QUEUE_STACK_ST *queue)
{
  pointerType P = queue->first;//aponta para o inicio para percorrer a fila/pilha toda
  while (P != NULL) {
    queue->first = P->next;//aponta pro próximo
    free(P);
    P = queue->first;//como P aponta pro próximo e a lista->primeiro aponta pra P, após o free() o ponteiro aponta pro início, queria o valor da posição i+i
  }
}