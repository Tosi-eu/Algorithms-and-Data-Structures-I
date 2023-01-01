#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "utils.h"

//para criar a pilha, basta dizer que o topo é NULL
void createStack(QUEUE_STACK_ST *stack)
{ 
  stack->top = NULL; 
}

//sendo a pilha LIFO, a inserção se dá no topo
boolean push(QUEUE_STACK_ST *stack, ELEMENT_ST element)
{
  pointerType newElement = (pointerType)malloc(sizeof(KNOT_ST));

  if (newElement == NULL)
    return false;//erro de alocação

  newElement->element = element;
  newElement->next = stack->top;
  stack->top = newElement;//inseriu no topo, com sucesso

  return true;
}

//função que verifica se a pilha está vazia ou não 
boolean stackEmpty(QUEUE_STACK_ST *stack)
{
  if (stack->top == NULL)
    return false;//está vazia

	return true;//não está vazia
}

//sendo a pilha LIFO, pop promete remover do topo da pilha
boolean pop(QUEUE_STACK_ST *stack, ELEMENT_ST element)
{
  if (stackEmpty(stack))
    return false;//falso se vazia
    
  if (elementExist(stack->top->element, *(element.key)) == false) {
    return false;//se não tem topo, a pilha está vazia
  }

  pointerType aux = stack->top;//auxiliar pra não perder o ponteiro da pilha
  stack->top = stack->top->next;
  free(aux);//remove o nó

  return true; 
}

 //função que libera os nós da pilha
void freeStackKnots(QUEUE_STACK_ST *stack)
{
  pointerType P = stack->top;//P aponta para o top antes de percorrer
  while (P != NULL) {
    stack->top = P->next;//stack percorre todos os elementos da pilha
    free(P);
    P = stack->top;//P volta a apontar para o primeiro da pilha até acabar
  }
}