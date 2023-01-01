#ifndef DYNA_H
#define DYNA_H

#define EXIT -2
#define ERROR_NOT_FOUND -1
#define LIST_IS_FULL 0
#define RETURN_SUCCESS 1
#define NULL_POINTER_ERROR 2

typedef int KEY_ST;

typedef struct ELEMENT_ST {
	KEY_ST key;
	char name[50];
} ELEMENT_ST;

typedef struct KNOT_ST *POINTER_ST;
typedef struct KNOT_ST {
	ELEMENT_ST element;
	POINTER_ST next;
} KNOT_ST;

typedef struct {
	POINTER_ST first;
	POINTER_ST last;
} LIST_ST;

int create(LIST_ST *list);
int insert(LIST_ST *list, ELEMENT_ST element);
int remove_item(LIST_ST *list, KEY_ST key);
ELEMENT_ST search(LIST_ST *list, KEY_ST key);
int modify(LIST_ST *list, ELEMENT_ST new_element);
int empty(LIST_ST *list);
int full(LIST_ST *list);
void print(LIST_ST *list);

#endif