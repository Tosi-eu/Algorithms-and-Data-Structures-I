<strong> <s>Anotações não tão boas</s> de aula </strong>
<br>
<h1>Resumo lista, pilha e fila</h1>
<ul>
    <li>Listas: Podem ser -> padrões, ordenadas (só pode ter versão estática, pois alterar o tamanho da lista fará que com se precise de reordenação de valores), dulamente ligadas ou circulares (com versão estática ou dinâmica)</li>
    <li>Filas: FIFO, mesmas funções da lista inserção, remoção, pesquisa, deleção</li>
    <li>Pilhas: em breve...</li>
</ul>
<hr>
<h1>Filas</h1>
<ul>
    <li>Convém a padronização estática, uma vez que a fila (por enquanto) exige uma cabeça e uma cauda</li>
    <li>Para emoção, convém a lista ser circular, a fim de reduzir a complexidade da fila.</li>
    <li>Função exclusiva: função <strong>frente</strong> -> Verifica o próximo termo de list[i]</li>
    <li>O ponteiro para o final da fila é <strong>conveniente</strong></li>
    <li>Implementação mais difícil que a da lista, porém mais eficaz no que se refere à economia de memória</li>
    <li>Na inserção, o ponteiro que aponta para o fim aponta para o conteúdo a ser inserido, e o que estava no final (NULL) vai para fim + 1, e o ponteiro vai junto</li>
    <li>No contexto da fila, não faz sentido a busca, basta REMOVER aux->inicio, inicio = inicio->proximo, free(aux)</li>
</ul>