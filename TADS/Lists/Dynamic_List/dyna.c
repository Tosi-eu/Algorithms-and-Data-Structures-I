#include <stdio.h>
#include <stdlib.h>
#include "dyna.h"

int create(LIST_ST *list) {
	list->first = NULL;
	list->last = NULL;
}

int insert(LIST_ST *list, ELEMENT_ST element) {

	POINTER_ST new_element = (POINTER_ST)malloc(sizeof(KNOT_ST));
	if (new_element == NULL)
		return LIST_IS_FULL;

	new_element->element = element;
	new_element->next = list->first;
	list->first = new_element;

	return RETURN_SUCCESS;

}

static POINTER_ST search_position(LIST_ST *list, KEY_ST key) {

	POINTER_ST ppr = list->first;
	if(ppr == NULL)
		return NULL_POINTER_ERROR;

	while(ppr != NULL) {
		if (ppr->element.key == key)
			return ppr;
		ppr = ppr->next;
	}

	return NULL;
}

int remove_item(LIST_ST *list, KEY_ST key);

    ELEMENT_ST search(LIST_ST *list, KEY_ST key) {
	POINTER_ST ppr = search_position(list, key);
	return ppr->element;
}

int modify(LIST_ST *list, ELEMENT_ST new_element);
int empty(LIST_ST *list);
int full(LIST_ST *list);
void print(LIST_ST *list);