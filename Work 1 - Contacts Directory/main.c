#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "schedule.h"

int main()
{
  TYPE_DL list;
  ELEMENT element;

  char opcao;//como as opções são letras, o operador que as manipula é do tipo char

  createList(&list);

  while(true)
  {
      //menu(); -> vide schedule.c se necessário
      setbuf(stdin, NULL);
      scanf(" %c", &opcao);

      if (opcao == '0')//condição de parada 
      {
        freeList(&list);
        break;
      }

    switch(opcao)
    {

    case 'I': //insertContact

          validName(&element); //função para name sempre retornar true
          validNumber(&element); //função para número sempre ser true
          insertContact(&list, element);
      break;
    case 'R': //removeContact contato
        validName(&element);
        removeContact(&list, element.name);
      break;
    case 'A': //modify contato
          validName(&element);
          validNumber(&element);
          modify(&list, element);
      break;
    case 'P': //search contato
        validName(&element);
        search(&list, element.name);
      break;
   /*case 'M':
      printaContatos(&ista);
      break;
    */
    default:
      printf("### erro -> comando inválido ### OUTPUT %d ###\n", false);
    }
  }
  return 0;
}