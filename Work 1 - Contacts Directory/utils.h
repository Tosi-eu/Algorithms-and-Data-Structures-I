#ifndef UTILS_H
#define UTILS_H
#include "schedule.h"

#define true 1
#define false -1

//inteiro para tipo booleano
typedef int boolean;

boolean existe(tipoElemento nome, CHAVE nome2);
void menu();//para ficar legível
void printaContatos(tipoListaDinamica *lista);//para debuggar
void validaNome(tipoElemento *elemento);
void validaNumero(tipoElemento *elemento);

#endif