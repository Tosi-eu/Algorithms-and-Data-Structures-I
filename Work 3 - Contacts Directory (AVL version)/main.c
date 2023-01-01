#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LittleContacts.h"

/**
 * @author Guilherme Henrique Galdini Tosi - 11781587
 * @author Pedro Santos Souza - 12567502
*/

int main() 
{
  AVL A = NULL; //como incializar a árvore é simplesmente setar o valor inicial do ponteiro como NULL, isso satisfaz
  element_st element; //tem a chave(nome) e o número de telefone

  int operationReturn[MAX], operationId = 0; //responáveis por armazenar o retorno de todos inputs
  long int contactNumber[MAX]; // vetor que armazena os  da saida
  int contactId = 0; // indice do ultimo telefone da saida
  int contactIndexSearch = 0;
  char op;

  while (1)
  {
    while(!scanf(" %c", &op)) //garante 100% de acertividade no scanf, o que faz com que n se precise de um default
    {
      scanf(" %c", &op);
    }

    switch (op)
    {
    case 'I': //inserir
      while(!scanf("%s", element.contactName))
      {
        scanf("%s", element.contactName);
      }
       if (scanf("%ld", &element.contactNumber) == 1)
          insertInNode(&A, element, &operationId, operationReturn);
      break;
    case 'R': //deletar
      while(!scanf("%s", element.contactName))
      {
        scanf("%s", element.contactName);
      }
        deleteNode(&A, element.contactName, &operationId, operationReturn);
      break;
    case 'A': //modificar
      while(!scanf("%s", element.contactName))
      {
        scanf("%s", element.contactName);
      }
        if (scanf("%ld", &element.contactNumber) == 1)
          modifyNode(&A, element, &operationId, operationReturn);
      break;
    case 'P': //procurar
      while(!scanf("%s", element.contactName))
      {
        scanf("%s", element.contactName);
      }
        searchInNodes(&A, element.contactName, &operationId, operationReturn, &contactId, contactNumber);

      break;
    case '0': //encerrar
        for (int i = 0; i <= operationId - 1; i++) 
        {
          if(operationReturn[i] == ALREADY_INSERTED)
          {
            printf("Contatinho ja inserido\n");
          }
          else if(operationReturn[i] == NOT_FOUND_ERROR)
          {
            printf("Contatinho nao encontrado\n");
          }
          else if(operationReturn[i] == CONTACT_FOUND)
          {
            printf("Contatinho encontrado: telefone %ld\n", contactNumber[contactIndexSearch]);
            contactIndexSearch++;
          }
          else if(operationReturn[i] == INVALID_OP_SEARCH)
          {
            printf("Operacao invalida: contatinho nao encontrado\n");
          }
          else if(operationReturn[i] == INVALID_OP)
          {
            printf("Operacao invalida\n");
          }
          else
              operationReturn[operationId] = INVALID_OP;
        }
        freeAVLinPosOrder(&A);
        exit(EXIT_SUCCESS);
      }
    }

  return 0;
}