#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int create(LIST_ST *list) {
	list->first = NULL;
	//list->ultimo = NULL;
}

void reverse(LIST_ST *list) {


    if(list->first == NULL)
        exit(ERROR_NOT_FOUND);
    if(list->first->next == NULL)
        exit(UNITARY_LIST);

    POINTER_ST previous = NULL;
    POINTER_ST next_element = list->first;

    do { // para quando o next_element for null
        next_element = list->first->next;
        list->first->next = previous; // inverter o next
        previous = list->first; // andar com o previous pra frente
        list->first = next_element; // cuidado com a cabeça da list indo pra frente
    } while(next_element != NULL);
    list->first = previous;

    //TODO cabeça da list

}


int insert(LIST_ST *list, ELEMENT_ST element) {

	POINTER_ST new_element = (POINTER_ST) malloc(sizeof(KNOT_ST));
	if (new_element == NULL)
		return LIST_IS_FULL;

	new_element->element = element;
	new_element->next = list->first;
	list->first = new_element;

	return EXIT_SUCCESS;

}

static POINTER_ST search_pos(LIST_ST *list, KEY_ST key) {

	POINTER_ST P = list->first;
	if(P == NULL)
		return NULL;

	while(P != NULL) {
		if (P->element.key == key)
			return P;
		P = P->next;
	}

	return NULL;

}

int remove_item(LIST_ST *list, KEY_ST key) {

	POINTER_ST P = list->first;
	if(P == NULL)
		return ERROR_NOT_FOUND;

	// element a remove_item é o first da list
	if (P->element.key == key) { 
		list->first = list->first->next;
		free(P);
		return EXIT_SUCCESS;
	}

	while(P->next != NULL) {
		if (P->next->element.key == key) {
			POINTER_ST aux = P->next;
			P->next = P->next->next;
			free(aux);
			return EXIT_SUCCESS;
		}
		P = P->next;
	}

	return ERROR_NOT_FOUND;

}

ELEMENT_ST search(LIST_ST *list, KEY_ST key) {
	POINTER_ST P = search_pos(list, key);
	return P->element;
}

int modify(LIST_ST *list, ELEMENT_ST new_element){
		return NULL;
}

int empty(LIST_ST *list){
    if(list->first == NULL)
        exit(EMPTY_LIST);
}
int full(LIST_ST *list){
	//if(list->last != NULL)
	//return LIST_IS_FULL;
}

void print(LIST_ST *list) {

	POINTER_ST P = list->first;
	
	while(P != NULL) {
		printf("%d ", P->element.key);
		P = P->next;
	}
	printf("\n");

}

void menu(){

    printf("Operations available: \n");
    printf("0 - exit\n");
    printf("1 - Insert an element\n");
    printf("2 - remove an element\n");
    printf("3 - print all elements\n");
    printf("4 - reverse entire list\n\n");

}