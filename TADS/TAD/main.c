#include <stdio.h>
#include "groups.h"

int main() {

	group_st my_group;
	element_st my_element;

	start(my_group);

	my_element = 45;
	printf("belong %d\n",belong(my_element, my_group));

	my_element = 45;
	printf("insere %d %d\n", my_element, insert(my_element, my_group));

	my_element = 45;
	printf("insere %d %d\n", my_element, insert(my_element, my_group));

	my_element = 5;
	printf("insere %d %d\n", my_element, insert(my_element, my_group));

	print(my_group);

	my_element = 45;
	remove_item(my_element, my_group);

	print(my_group);

}


