#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "schedule.h"

boolean exist(ELEMENT element, KEY name){
    if(strcmp(element.name, name) == 0)
      {
        return true;
      }
    return false;
}

void printContact(TYPE_DL *list) //função para debuggar
{
  pointerType ppr = list->first;
  while(ppr != NULL)
  {
    printf("%s %ld\n", ppr->element.name, ppr->element.cell);
    ppr = ppr->next;
  }
}

void validName(ELEMENT *element)
{
    while(scanf("%s", element->name) != true)
    {
        scanf("%s", element->name);
    }
}

void validNumber(ELEMENT *element)
{
    while(scanf("%ld", &element->cell) != true)
    {
        scanf("%ld", &element->cell);
    }
}

void menu() //função para deixar bonitinho e para não esquecer o que cada letra significa
{
  printf("========================\n");
  printf("A - Moodificar contato\n");
  printf("I - Inserir contato\n");
  printf("R - Remover contato\n");
  printf("P - Procurar contato\n");
  printf("M - Printar contatos\n");
  printf("0 - Sair\n");
  printf("=========================\n");
}