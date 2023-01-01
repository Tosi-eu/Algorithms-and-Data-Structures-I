#include <stdio.h>
#include <string.h>
#include "groups.h"

void start(group_st c) {
	memset(c, 0, sizeof(group_st));
}

char insert(element_st e, group_st c) {
	if (!belong(e, c)) {
		c[e] = 1;
		return NO_ERROR_FOUND;
	} else {
		return ALREADY_EXIST;
	}
}

char remove_item(element_st e, group_st c) {
	if (belong(e, c)) {
		c[e] = 0;
		return NO_ERROR_FOUND;
	} else {
		return ANY_ERROR;
	}
}

char belong(element_st e, group_st c) {
	return c[e];
}

void print(group_st c)
{
	printf("{");
	for (int i = 0; i < max; i++)
		if (belong(i, c))
			printf("%d, ", i);
	printf("}\n");
}
