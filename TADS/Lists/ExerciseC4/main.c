#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {

    LIST_ST list_element;
    ELEMENT_ST element;

    int op = -1;
    create(&list_element);

    while (op != 0) {

        menu();

        scanf("%d", &op);

        switch (op) {
            case 0: // exit
                //TODO funcao de limpar a lista
                break;
            case 1: // insert
                printf("Element to be inserted: ");
                scanf("%d", &element.key);
                insert(&list_element, element);
                break;
            case 2: // remove_item
                printf("Element to be removed: ");
                scanf("%d", &element.key);
                remove_item(&list_element, element.key);
                break;
            case 3: // print
                print(&list_element);
                break;
            case 4: // reverse
                reverse(&list_element);
                break;
            default:
                exit(ERROR_NOT_FOUND);
        }

    }

	return 0;
}