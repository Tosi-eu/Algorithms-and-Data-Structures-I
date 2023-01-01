#include <stdio.h>
#include <stdlib.h>
#include "static_list.h"

int main() {
	GROUP_ST my_group;
	ELEMENT_ST my_element;

	start(my_group);

	my_element = 45;
	printf("pertinence %d\n",pertinence(my_element, my_group));

	my_element = 45;
	printf("Insert: %d %d\n", my_element, insert(my_element, my_group));

	my_element = 45;
	printf("Insert: %d %d\n", my_element, insert(my_element, my_group));

	my_element = 5;
	printf("Insert: %d %d\n", my_element, insert(my_element, my_group));

	my_element = 5;
	printf("perticpertinence %d\n",pertinence(my_element, my_group));

	my_element = 4;
	printf("perticpertinence %d\n",pertinence(my_element, my_group));

	my_element = 45;
	printf("perticpertinence %d\n",pertinence(my_element, my_group));

	my_element = 75;
	printf("Insert: %d %d\n", my_element, insert(my_element, my_group));

	my_element = 22;
	printf("Insert: %d %d\n", my_element, insert(my_element, my_group));

	my_element = 98;
	printf("Insert: %d %d\n", my_element, insert(my_element, my_group));

	print(my_group);

	my_element = 45;
	remove_element(my_element, my_group);

	print(my_group);


}

