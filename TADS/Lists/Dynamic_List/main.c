#include "dyna.h"

#include <stdio.h>

int main() {

    LIST_ST l;
    ELEMENT_ST e;
	  POINTER_ST p;

    create(&l);

    e.key = 5;
    insert(&l, e);

    e.key = 3;
    insert(&l, e);

    e.key = 7;
    insert(&l, e);

  //print(&l);
	
	return 0;
}