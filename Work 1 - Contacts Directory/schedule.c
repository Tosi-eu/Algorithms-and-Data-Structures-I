#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

void createList(TYPE_DL *list)//list apontando para primeiro e ultimo ao memso tempo implica dizer que ela está vazia
{
  list->first = NULL;
  list->last = NULL;
}

boolean insertContact(TYPE_DL *list, ELEMENT element)
{
  pointerType newContact = (pointerType)malloc(sizeof(KNOT_ST));//tipoAPontador para novo contato
  pointerType aux = (pointerType)malloc(sizeof(KNOT_ST));//necessario para não perder a list

  if (newContact == NULL || aux == NULL)
  {
    return false;
  }else
    aux = list->first;

  //verifica se o elemento já está na lista, para que não seja inserido novamente
  while (aux != NULL)
  { 
    if (exist(aux->element, element.name) == true)
    {
      printf("Contatinho ja inserido\n");
      return true;
    }
    aux = aux->next;//o ponteiro auxiliar serve para percorrer o vetor, insertContact o contato e ser removido sem prejudicar a integridade da list
  }
  //a inserção se dá no começo da list
  newContact->element = element;
  newContact->next = list->first;
  list->first = newContact;

  free(aux); //terinou a operação, libera-se a memória alocada.. Como é um auxiliar, não se perde a list
  return true;
}

pointerType searchContactPosition(TYPE_DL *list, KEY name)
{
  pointerType ppr = list->first;
  if (ppr == NULL)
    return NULL;

//percorre o vetor, verificando se o mesmo já exist
  while (ppr != NULL)
  {
    if (exist(ppr->element, name) == true)
      return ppr;
    ppr = ppr->next;
  }
  return ppr;
}

void search(TYPE_DL *list, KEY name)
{
  pointerType ppr = searchContactPosition(list, name);

  if (ppr == NULL)
    printf("Contatinho nao encontrado\n");
  else
  {
    printf("Contatinho encontrado: telefone %ld \n", ppr->element.cell);
  }
}

static boolean removeContactIndex(TYPE_DL *list, pointerType p)
{

  pointerType aux = list->first;//auxliliar para percorrer o vetor até o anterior de p

  //verifica se não é NULO (contato não está na list)
  if (p == NULL)
  {
    return false; //posição inváida (-1 ou list->primeiro->anterior)
  }

  //como a list está vazia, então só se cria a list e retorna sucesso
  if (p == list->first && p == list->last)
  {
    createList(list);
    free(p);
    return true;
  }

  //se a cabeça for aquela a ser removida, é necessário que p aponte para primeiro->proximo 
  if (p == list->first)
  {
    list->first = list->first->next;
    free(p);
    return true;
  }

  while (aux->next != NULL && aux->next != p)
  {
    aux = aux->next;
  }

  aux->next = p->next; //aux aponta para o próximo de p 'pela uma casa(a que será removida)'
  
  if (aux->next == NULL)
  {
    list->last = aux;
  }

  free(p);
  return true;
}

boolean removeContact(TYPE_DL *list, KEY name)
{
  //ponteiro aponta para o retorno da pesquisa, e element recebe o retorno da osição a ser removida (proxima de p), se a posição é -1, printa erro
  //senão, remove com sucesso
  pointerType ppr = searchContactPosition(list, name);
  int element = removeContactIndex(list, ppr);

  if(element == false) //se está em uma posição inválida
  {
    printf("Operacao invalida: contatinho nao encontrado\n");
    return false;
  }
  return true;
}

boolean modify(TYPE_DL *list, ELEMENT element) //alteração nesse caso é somente do número, o name atua como chave primária
{
  //ponteiro aponta para o retorno da pesquisa, se não encontrou, printa erro, senão permite a alteração
  pointerType ppr = searchContactPosition(list, element.name);

  if (ppr == NULL)
    printf("Operacao invalida: contatinho nao encontrado\n");
  else{
    ppr->element.cell = element.cell;
    return true;
  }

  return false;
}

//apaga lista
void freeList(TYPE_DL *list)
{
      pointerType ppr = list->first;
      while (ppr != NULL)
        {
          list->first = ppr->next;
          free(ppr);
          ppr = list->first;
        }
}

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

//enquanto o retorno de scanf não é 1, o loop continua. 1 significa que o elemento é valido para o tipo de dado
void validName(ELEMENT *element)
{
    while(scanf("%s", element->name) != true)
    {
        scanf("%s", element->name);
    }
}

//enquanto o retorno de scanf não é 1, o loop continua. 1 significa que o elemento é valido para o tipo de dado
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