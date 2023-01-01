#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "twosum.h"

/**
 * @author Guilherme Henrique Galdini Tosi - 11781587
 * @author Pedro Santos Souza - 12567502
*/

/*

A entrada é iniciada por uma linha contendo um inteiro N valores (0 < N < 10^9), 
representando o número de elementos do conjunto A. Na linha seguinte, são
fornecidos os N valores pertencentes a A. 

Após isso, se dá início às consultas, sendo que a primeira linha contém um inteiro M (0 < M < 10^6),
representando o número de consultas a serem feitas. A cada uma das próximas M linhas, há um
inteiro k, para o qual deve ser encontrada a soma de par.

*/

int main()
{
    //'elements' representa os 'n' elementos, 'verifications' representa as 'M' próximas linhas e 'sum' representa o inteiro k
    int elements, verifications, sum;

     while(!scanf("%d", &elements)) //pra ser impossível a entrada de valores incompatíveis
    {
        scanf("%d", &elements);
    }

    if(elements < 0 || elements > pow(10, 9)) //range dado pelo enunciado
        exit(INTEGER_OUT_OF_RANGE);

    HASH_ST *table[elements]; 
    int *array = malloc(elements*sizeof(int));

    //setando as posições lista 'tabela' com valor nulo, a fim de evitar lixos de memória nela
     for(int i = 0; i < elements; i++)
	{
        table[i] = NULL; 
    }

    for(int i = 0; i < elements; i++) 
	{
        scanf("%d", &array[i]);
        insert_in_table(table, array[i], elements);
    }

    while(!scanf("%d", &verifications)) //pra ser impossível a entrada de valores incompatíveis
    {
        scanf("%d", &verifications);
    }

    if(verifications < 0 || verifications > pow(10, 6)) //range dado pelo enunciado
        exit(INTEGER_OUT_OF_RANGE);

    for(int i = 0; i < verifications; i++)
		{
          while(!scanf("%d", &sum)) //pra ser impossível a entrada de valores incompatíveis
            {
                 scanf("%d", &sum);
            }

          if(verify_content(table, elements, sum) == true)
            {
                printf("S\n");
            }
           else
                printf("N\n");
        }
            
    free_table(table, elements);
    free(array);

    return 0;
}
