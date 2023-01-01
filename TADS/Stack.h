#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void createStack(QUEUE_STACK_ST *stack);//criação da pilha
boolean push(QUEUE_STACK_ST *stack, ELEMENT_ST element);//empilha elementos no topo da pilha -> push
boolean pop(QUEUE_STACK_ST *stack, ELEMENT_ST element);//desempilha elementos do topo da pilha -> pop
boolean stackEmpty(QUEUE_STACK_ST *stack);//verfica se está vazia ou não
void freeStackKnots(QUEUE_STACK_ST *stack);//é como free(), mas só que para todos os nós das pilha

#endif
