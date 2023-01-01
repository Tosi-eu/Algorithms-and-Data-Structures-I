#include <stdio.h>
#include <stdlib.h>
#include "twosum.h"

static int hashing(int element, int size) //função para hashing modular
{
	int result = element % size;

	return result;
}

void insert_in_table(pointer *table, int value, int n)
{
	int insertionIndex = hashing(value, n); //hashing modular
    pointer newElement = malloc(sizeof(HASH_ST));

	if(newElement == NULL)
	{
		exit(false);
	}

    //value inserido na table é adicionado ma poosição dada pela função hashing
    newElement->value = value;
    newElement->next = table[insertionIndex];
    table[insertionIndex] = newElement; 
}

//função booleana, se retorna 1 o algoritmo printa S, senão printa N
boolean verify_content(HASH_ST **table, int n, int sum)
{
    int i, difference, result;
    pointer aux, checkSum;

    for(i = 0; i < n; i++)
		{
        aux = table[i]; //ponteiro auxilar para a tabela
        while(aux != NULL)
        {
            difference = sum - aux->value;
            result = hashing(difference, n); //a posição do elemento é calculada pela diferença dele mesmo com a soma k'
            if(result >= 0)
            {
              checkSum = table[result];
              while(checkSum != NULL) 
				{
                  if(checkSum->value == difference)
				  {
                     return true;
                  }
                  checkSum = checkSum->next;
                }
            }
            aux = aux->next;
        }
    } 
    return false;
}        

void free_table(HASH_ST **table, int table_size)
{
    pointer aux, aux2;
    for (int i = 0; i < table_size; i++)
    {
        aux = table[i];
        while (aux && aux->next != NULL)
        {
            aux2 = aux->next; //[i]
            aux->next = aux2->next; //[j]
            free(aux2);
        }
        free(aux);
    }
}