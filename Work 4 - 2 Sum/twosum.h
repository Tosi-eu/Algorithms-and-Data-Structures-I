#ifndef TWOSUM_H
#define TWOSUM_H

#define INTEGER_OUT_OF_RANGE -1
#define true 1
#define false -1

typedef struct HASH_ST *pointer; //ponteiro para os elementos que serão insridos na tabela
typedef int boolean; //para criar funções booleanas

typedef struct HASH_ST
{
  int value; //serão sempre maiores que 0
  pointer next;
  //int chave -> devido o propósito do exercício, não é necessário trabalho com chave e valor

}HASH_ST;

boolean verify_content(HASH_ST **tabela, int n, int soma);
void insert_in_table(HASH_ST **tabela, int value, int n);
void free_table(HASH_ST **table, int table_size);
#endif

