#include <stdio.h>
#include <stdlib.h>
#include "static_list.h"

void start(GROUP_ST group_element) {
	memset(group_element, 0, sizeof(GROUP_ST));
}

char insert(ELEMENT_ST element, GROUP_ST group_element) {
	if (!pertinence(element, group_element)) {
		group_element[element] = 1;
		return NO_ERRORS;
	} else {
		return ALREADY_EXIST;
	}
}

char remove_element(ELEMENT_ST element, GROUP_ST group_element) {
	if (pertinence(element, group_element)) {
		group_element[element] = 0;
		return NO_ERRORS;
	} else {
		return UNKNOWN_ERROR;
	}
}

char pertinence(ELEMENT_ST element, GROUP_ST group_element) {
	return group_element[element];
}

void print(GROUP_ST group_element)
{
	printf("{");
	for (int i = 0; i < MAX; i++)
		if (pertinence(i, group_element))
			printf("%d, ", i);
	printf("}\n");
}