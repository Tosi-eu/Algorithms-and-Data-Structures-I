#ifndef LITTLE_CONTACTS_H
#define LITTLE_CONTACTS_H

#define INVALID_OP 0
#define ALREADY_INSERTED 1
#define NOT_FOUND_ERROR 2
#define CONTACT_FOUND 3
#define INVALID_OP_SEARCH 4
#define MAX 100000
/**
 * @author Guilherme Henrique Galdini Tosi - 11781587
 * @author Pedro Santos Souza - 12567502
*/

typedef char key[256];
typedef struct avl_st *pointer_st; //ponteiro responsável pelas buscas recursivas
typedef pointer_st AVL; //ponteiro para AVL

typedef struct CONTATINHO_ST//Class Contatinho
{
	key contactName;
	long int contactNumber;
} element_st;

typedef struct avl_st //Class AVL
{
	element_st element;
	pointer_st left, right;
	int height; 
} avl_st;

//auxiliar para o balanceamento da árvore
int getHeight(AVL *avl);
//auxiliar para o balanceamento da árvore
int getBalanceFactor(AVL *avl);
//insere um contato na árvore, dado uma chave innexstente nela
int insertInNode(AVL *avl, element_st element, int *idxResp, int responses[MAX]);
//retorna o número de telefone do contato, dado uma chave existente
int searchInNodes(AVL *avl, key contactName, int *idxResp, int responses[MAX], int *idxTel, long int telefones[MAX]);
//deleta um nó, dado uma chave existente na árvore
int deleteNode(AVL *avl, key contactName, int *idxResp, int responses[MAX]);
//retorna a alteração desejada, dado uma chave existente na árvore
int modifyNode(AVL *avl, element_st novo, int *idxResp, int responses[MAX]);
//livra todos nós em posOrder
void freeAVLinPosOrder(AVL *avl);
//trata a chave com um loop, pra sempre ser verdadeira, pois ela é essêncial
void treatName(element_st element);
#endif
