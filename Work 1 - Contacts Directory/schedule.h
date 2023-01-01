#ifndef SCHEDULE_H
#define SCHEDULE_H

#define true 1
#define false 0

//estruturas de identificação dos elementos
typedef char KEY[12]; //número máximo de caracteres pro name do contato = 12
typedef long int CONTATO; //poderia ser um vetor com valor definido, mas como estamos considerando contatos de vários lugares distintos, não faz muito sentido
typedef int boolean; //tipo booleano

//ponteiro de manipulação dos nós
typedef struct KNOT_ST *pointerType;

//estrutura caraterísticas do contatinho
typedef struct
{
  KEY name;
  CONTATO cell;
} ELEMENT;

//estrutura do tipo nó
typedef struct KNOT_ST
{
  ELEMENT element; //ponteiro para elemento
  pointerType next; //ponteiro próximo d list
} KNOT_ST;

//estrutura do tipo list com os ponteiros cabeça e cauda
typedef struct
{
  pointerType first, last;
} TYPE_DL; //TipoListaDinâmica

void createList(TYPE_DL *list);//cria a list
boolean insertContact(TYPE_DL *list, ELEMENT element);//insere novos contatos
boolean removeContact(TYPE_DL *list, KEY name);//remove contatos já existentes
pointerType searchContactPosition(TYPE_DL *list, KEY name); //devolve a posição buscada
void search(TYPE_DL *list, KEY name);//printa o telefone quando encontrado
boolean modify(TYPE_DL *list, ELEMENT element);//altera o contato encontrado
void freeList(TYPE_DL *list); //apagar lista

//funções auxiliares -> algumas são só para debuggar, como printaContatos
boolean exist(ELEMENT name, KEY name2);
void menu();//para ficar legível
void printContacts(TYPE_DL *list);//para debuggar
void validName(ELEMENT *element);
void validNumber(ELEMENT *element);

#endif