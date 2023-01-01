#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LittleContacts.h"

/**
 * @author Guilherme Henrique Galdini Tosi - 11781587
 * @author Pedro Santos Souza - 12567502
*/

#define ALLOCATION_ERROR 500
#define EMPTY -1

//faz rotação simples à esquerda
static void leftRotation(AVL *avl)
{
  pointer_st aux, aux2;

  aux = (*avl)->right; //armazena o conteúdo do filho à direita
  
  aux2 = aux->left;  //armazena o conteúdo do filho à esquerda

  (*avl)->right = aux2; // a sub-arv muda de pai pela antiga raiz
  
  aux->left = (*avl); //esquerda é a nova raiz

  if(getHeight(&(*avl)->left) > getHeight(&(*avl)->right))
  {
    (*avl)->height = getHeight(&(*avl)->left) + 1;
  }
  else
  {
    (*avl)->height = getHeight(&(*avl)->right) + 1;
  }

  aux->height = (*avl)->height;

  *avl = aux;
}

//faz rotação simples à direita
static void rotacao_dir(AVL *avl)
{
  pointer_st aux, aux2;

  aux = (*avl)->left;

  aux2 = aux->right;

  (*avl)->left = aux2; // a antiga raiz faz o filho mudar de pai

  aux->right = (*avl);  // aux passa a ser a raiz

  if(getHeight(&(*avl)->left) > getHeight(&(*avl)->right))
  {
    (*avl)->height = getHeight(&(*avl)->left) + 1;
  }
  else
  {
    (*avl)->height = getHeight(&(*avl)->right) + 1;
  }

  aux->height = (*avl)->height;

  *avl = aux;
}

//faz rotação à direita, depois à esquerda
static void rotationRightLeft(AVL *avl)
{
  rotacao_dir(&(*avl)->right);
  leftRotation(avl);
}

//faz rotação à esquerda, depois à direita
static void rotationLeftRight(AVL *avl)
{
  leftRotation(&(*avl)->left);
  rotacao_dir(avl);
}

//retorna novo nó se a inserção foi satisfeita
int static createRootNode(AVL *avl, element_st element)
{
  // cria uma raiz ao inserir um novo elemento(nova chave) em um nó folha ou avl vazia
  *avl = (AVL)malloc(sizeof(avl_st));
  if (*avl == NULL)
    return ALLOCATION_ERROR;

  (*avl)->left = NULL;
  (*avl)->right = NULL;
  (*avl)->element = element;
  (*avl)->height = 0;

  return 1;
}

//pega o menor valor e faz a troca, caso de remoção de pai com 2 subarvores
static void getBiggerValue(AVL *raiz, AVL *subTree)
{
  if ((*subTree)->right == NULL)
  {
    pointer_st p;

    (*raiz)->element = (*subTree)->element;

    p = *subTree;
    *subTree = (*subTree)->left;
    free(p);

  } 
  else
  {
    getBiggerValue(raiz, &(*subTree)->right);
  }
}

//ajuda no balanceamento, a fim de evitar grande repetição do mesmo script
int getHeight(AVL *avl)
{
  if ((*avl) == NULL)
  {
    return EMPTY;
  }
  else
    return (*avl)->height;
}

//retorna o fb para que seja feita rebalanceamento na inserção e/ou remoção se necessário
int getBalanceFactor(AVL *avl) //balanceamento
{
  if ((*avl) == NULL)
    return EMPTY;
  else {
    if ((*avl)->left == NULL && (*avl)->right == NULL)
    {
      return 0;
    } 
    else
    {
      int He = getHeight(&(*avl)->left);
      int Hd = getHeight(&(*avl)->right);
      return (He - Hd);
    }
  }
}

//função de inserção retorna m novo elemento na árvore se não existe essa chave, senão retorn erro
int insertInNode(AVL *avl, element_st element, int *responseIndex, int responses[MAX]) 
{
  if ((*avl) == NULL) 
  {
    return createRootNode(avl, element);
  }

  if (strcmp((*avl)->element.contactName, element.contactName) == 0)// == 0 -> já existe
  {
    responses[*responseIndex] = ALREADY_INSERTED;
    *responseIndex = *responseIndex + 1;
  } 
  else
   {
    if (strcmp((*avl)->element.contactName, element.contactName) > 0) 
    {
      insertInNode(&(*avl)->left, element, responseIndex,responses); // insere contato à esquerda,recursivamente

  if((*avl)->height > getHeight(&(*avl)->left))
  {
    (*avl)->height += 1;
  }
  else
  {
    (*avl)->height = getHeight(&(*avl)->left) + 1;
  }
    }
    if (strcmp((*avl)->element.contactName, element.contactName) < 0)
     {
      insertInNode(&(*avl)->right, element, responseIndex, responses); // insere contato à direita, recursivamente
      if((*avl)->height > getHeight(&(*avl)->right))
        {
          (*avl)->height += 1;
        }
        else
        {
          (*avl)->height = getHeight(&(*avl)->right) + 1;
        }
    }
  }

  int fb = getBalanceFactor(avl); //pode desbalancear a árvore, assim como a remoção

  // ocorre do lado esquerdo da avl, sendo 2 casos possíveis
  if (fb > 1) 
  { 
    int fb_filho = getBalanceFactor(&(*avl)->left); //declarando dentro do if para evitar gasto de memória desncessário

    if (fb_filho >= 0)
    {
      rotacao_dir(avl); 
    } 
    else
    {
      rotationLeftRight(avl); 
    }
  } 
  else if (fb < -1) // ocorre do lado direito da avl
   { 
    int fb_filho = getBalanceFactor(&(*avl)->right); //declarando dentro do if para evitar gasto de memória desncessário
    if (fb_filho <= 0)
     {
      leftRotation(avl); 
     } 
    else 
    {
      rotationRightLeft(avl);
    }
  }
  return NOT_FOUND_ERROR;
}

//Realiza a busca dos contatos em O(logn) -> retorna contato->telefone se existir, senão, retorna erro
int searchInNodes(AVL *avl, key name, int *responseIndex, int responses[MAX], int *contactPhoneId, long int contactsNumbers[MAX])
{
  if ((*avl) == NULL) //NULL -> contato não existe
  {
    responses[*responseIndex] = NOT_FOUND_ERROR;
    *responseIndex = *responseIndex + 1;
    return EMPTY;
  }

  if (strcmp((*avl)->element.contactName, name) == 0) //se está comparando, é *avl != NULL, então o contato existe
  {
    responses[*responseIndex] = CONTACT_FOUND;
    *responseIndex = *responseIndex + 1;
    contactsNumbers[*contactPhoneId] = (*avl)->element.contactNumber;
    *contactPhoneId = *contactPhoneId + 1;  
  } 
  else
  {
    if (strcmp(name, (*avl)->element.contactName) < 0) //se ainda não encontrou, faz uma busca recursiva para encontrar
    {
      return searchInNodes(&(*avl)->left, name, responseIndex, responses, contactPhoneId, contactsNumbers);
    } 
    else
    {
      return searchInNodes(&(*avl)->right, name, responseIndex, responses, contactPhoneId, contactsNumbers);
    }
  }
  return NOT_FOUND_ERROR;
}

//Realiza a busca do do contato a ser removido em O(logn), retona a exclusão e rebalanceia a árvore se necessário, senão, retornna error
int deleteNode(AVL *avl, key name, int *responseIndex, int responses[MAX]) 
{
  if ((*avl) == NULL) //NULL -> não existe o contato
  {
    responses[*responseIndex] = INVALID_OP_SEARCH;
    *responseIndex = *responseIndex + 1;
    return EMPTY;
  }
  
  //se está nesse passo, é pq o contato existe, far-se-á uma busca recursiva para encontrá-lo
  if (strcmp((*avl)->element.contactName, name) < 0)
  {
    deleteNode(&(*avl)->right, name, responseIndex, responses);
    if((*avl)->height > getHeight(&(*avl)->left))
      {
        (*avl)->height += 1;
      }
      else
      {
        (*avl)->height = getHeight(&(*avl)->left) + 1;
      }
  } 
  else if (strcmp((*avl)->element.contactName, name) > 0) 
  {
    deleteNode(&(*avl)->left, name, responseIndex, responses);
    if((*avl)->height > getHeight(&(*avl)->left))
    {
      (*avl)->height += 1;
    }
    else
    {
      (*avl)->height = getHeight(&(*avl)->left) + 1;
    }
  } 
  else if (strcmp((*avl)->element.contactName, name) == 0) 
  {
    pointer_st p;
    if ((*avl)->left == NULL && (*avl)->right == NULL) //remoção caso folha se filhos
    { 
      p = *avl;
      *avl = NULL;
      free(p);
    } 
    //remoção folha com filho à direita
    else if ((*avl)->left ==NULL)
    {
      p = *avl;
      *avl = (*avl)->right;
      free(p);
    //remoção folha com filho à esquerda
    } 
    else if ((*avl)->right == NULL)
    { 
      p = *avl;
      *avl = (*avl)->left;
      free(p);
    } 
    //remoção folha com com dois flhos
    else 
    { 
      getBiggerValue(avl, &(*avl)->left);
    }

    int fb = getBalanceFactor(avl); //assim como a inserção, pode desbalancear a árvore
  
    //lado esquerdo da AVL
    if (fb > 1)
    {
      int fb_filho = getBalanceFactor(&(*avl)->left); 
    if (fb_filho >= 0)
       {
        rotacao_dir(avl); // rotação simples à direita
      } 
      else
       {
        rotationLeftRight(avl); // rotação dupla à direita
       }
    } 
    //lado direito da AVL
    else if (fb < -1)
     {
      int fb_filho = getBalanceFactor(&(*avl)->right);
      if (fb_filho <= 0)
      {
        leftRotation(avl);
      } 
      else
      {
        rotationRightLeft(avl);
      }
    }
  }
  return NOT_FOUND_ERROR;
}

//função recursiva, baseada na busca pela name(contactName), retorna a modificação requisitada, se encontrado, senão retorna erro
int modifyNode(AVL *avl, element_st novo, int *responseIndex, int responses[MAX])
{
  if ((*avl) == NULL)
  {
    responses[*responseIndex] = INVALID_OP_SEARCH;
    *responseIndex = *responseIndex + 1; 
    return -1;
  }

  if (strcmp((*avl)->element.contactName, novo.contactName) == 0) //== 0, é o contato procurado
  {
    (*avl)->element.contactNumber = novo.contactNumber;
  } 
  else
  {
    if (strcmp((*avl)->element.contactName, novo.contactName) > 0)
    {
      return modifyNode(&(*avl)->left, novo, responseIndex, responses);
    } 
    else
     {
      return modifyNode(&(*avl)->right, novo, responseIndex, responses);
    }
  }
  return NOT_FOUND_ERROR;
}

//posOrder é feita para primeiro livrar os filhos
//para somente aí livrar o pai, caso contrário poderia ocorrer de n conseguir acessar um filho
//pq o pai foi apagado, por exemplo no acesso inOrder
void freeAVLinPosOrder(AVL *avl)
{
  if ((*avl) != NULL)
  {
        freeAVLinPosOrder(&(*avl)->left);
        freeAVLinPosOrder(&(*avl)->right);
        free(*avl);
  }
}

//roda um while para poder sempre existirem chaves válidas
void treatName(element_st element)
{
  while(!scanf(" %s", element.contactName)) //garante 100% de acertividade no scanf
    {
      scanf(" %s", element.contactName);
    }
}