<strong> Class 5 - Variações de listas </strong>

*REAPROVEITANDO AULA 4 E 5*

*Primeiro tipo* - LISTA DUPLAMENTE LIGADA
|_> Apresenta o ponteiro para o elemento anterior, sendo que na lista estática, dinâmica só tem pro próximo.

"desvantagem" -> Mais compicada de implementar, mas a estrutura é a mesma.
Complexidade de espaço -> Apresenta um ponteiro a mais (como a knot_st apresenta 1 elemento na struct, mais um equivale a 50% da estrutura).

OBS: Se preocupar com as extremidades da lista, uma vez que o anterior ao primeiro e o posterior ao último serão NULL.

*Segundo tipo* - LISTA ORDENADA 

Como ordenar -> chamar o algorítmo de ordenação sempre que a lista mudar? NÃO!

/*
Comentários:

    É pesada para uma única busca, inserção, remoção, mas para VÁRIAS dessas operações nessa mesma lista, talvez seja interessante, uma vez que coisas recorrentemente pesquisadas (exemplo) estarão mais próximas da, se não na própria cabeça.

    Lista ordenada dinâmica -> *Não* permite busca binária (como o meio é a média do meio e o fim, numa lista dinâmica, isso seria caro).

    Lista Estática -> Permite busca binária (sendo a lista de tamanho LIST_SIZE, o meio é definido uma só vez).

*/

*Terceiro tipo* - LISTAS CIRCULARES (assim como as outras, é uma lista de knot_st)

Diferentemente das demais listas, as extremidades não apontam para NULL, a última aponta pra primeira e a primeira para a última
|_> Se for implementar um jogo de cartas, por exemplo, faria muito sentido.

|_> Necessita de ponteiros para início e fim (se for estática).

|_> Necessita de MOD (%) para que seja feita 'a volta' na lista. Exemplo: retornar do último para o terceiro.

|_> Para pesquisa binária, é preciso que o início não seja zero, pois pode fazer o vetor 'estourar' -> mid = ((inicio + fim)/ 2)MOD(LIST_SIZE).

|_> Para inserção, é necessário que se lembre a posição início e fi, pois pode-se acabar sobrescrevendo dados, por exemplo, se você inserir logo depois do 
    fim, sobrescreve-se o começo.

*Quarto tipo* - LISTA CIRCULAR DINÂMICA

|_> Lista dinâmica comum, só muda que o último é o primeiro, logo, as operações são análogas

|_> Desvantagem: Algumas listas requerem que se tenha ciência da cauda, da cabeça. Ponto negativo para listas dinâmicas.