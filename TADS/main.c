#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

/*
  N - Número inteiro que indica quantidade de execuções (entre 1 e 100)
  K - Quantidade de operações de inserção e remoção (entre 2 e 100)
*/

int main()
{
  QUEUE_STACK_ST stack, queue;  
  ELEMENT_ST element;
  //posições setados como true por que a ideia é que a posição do vetor torne-se false quando alguma operação da pila ou da filha dêem errado
  boolean storeResults[2] = {true, true};//posição 0 armazena o resultado das operações da pilha, e 1, da fila

  int N, K, i = 0; 
  int trueFalseFlags[2] = {0, 0};//variáveis que serão incrementadas caso alguma das operações não ocorra pra determinado TAD
  //sendo posição 0 para stack e 1 para queue
  char op;//indica para o loop se a operação será de inserção ou remoção

  createQueue(&queue);
  createStack(&stack);

  scanf("%d", &N);

  if(N < 1 || N > 100) //limite especificado no pdf
    exit(EXIT_FAILURE);

  int *array = malloc(N*sizeof(int));

  if(array == NULL)
    exit(EXIT_FAILURE);

  while(i < N) // N execuções
  {
    scanf("%d", &K);//K operações

  if(K < 2 || K > 100){ //limite especificado no pdf
    exit(EXIT_FAILURE); 
  }

  for (int j = 0; j < K; j++)
    {
      scanf(" %c %d", &op, &(*element.key));

      while(op != 'i' && op != 'r') //trativa de caso de operações inexistentes
      {
        scanf(" %c", &op);
      }

      if(op == 'i')
      {
        storeResults[0] = push(&stack, element); //booleano que armazena 'false' se não deu certo o push
        storeResults[1] = enqueue(&queue, element);//booleano que armazena 'false' se não deu certo o enqueue
      }else if(op == 'r')
      {
        storeResults[0] = pop(&stack, element);//booleano que armazena 'false' se não deu certo o pop
        storeResults[1] = dequeue(&queue, element);//booleano que armazena 'false' se não deu certo o dequeue
      }

      if (storeResults[0] == false) {
        trueFalseFlags[0]++;
      }
      if (storeResults[1] == false) {
        trueFalseFlags[1]++;
      }
    }

    if (trueFalseFlags[0] > 0 && trueFalseFlags[1]> 0) {
      array[i] = IMPOSSIBLE; //duas operações opostas ao mesmo tempo == impossivel
    } else if (trueFalseFlags[1] > 0) {
      array[i] = STACK; //pilha
    } else if (trueFalseFlags[0] > 0) {
      array[i] = QUEUE; //fila
    } else { 
      array[i] = UNDEFINED; //caso de indefinição
    }

    freeQueueKnots(&queue);//é necessário liberar a queue após cada incrementação do for para que 
    freeStackKnots(&stack);//é necessário liberar a stack após cada incrementação do for para que 

    createQueue(&queue);//cria-se uma nova queue após liberar todos os nós 
    createStack(&stack);//cria-se uma nova stack após liberar todos os nós 

    for(int flag = 0; flag < 2; flag++)
        trueFalseFlags[flag] = 0; //reseta valores de flag
    i++;
  }

  //responsavel por acessar as posições do vetor que armazena as respostas
  for (int i = 0; i < N; i++) {
    if(array[i] == IMPOSSIBLE){
       printf("impossivel\n");
    }else if(array[i] == STACK){
       printf("pilha\n");
    }else if(array[i] == QUEUE){
       printf("fila\n");
    }else
       printf("indefinido\n"); //array[i] == UNDEFINED
  }

  free(array);
  return 0;
}