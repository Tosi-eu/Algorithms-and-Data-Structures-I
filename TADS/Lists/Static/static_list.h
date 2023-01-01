#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#define MAX 100

#define NO_ERRORS 0
#define ALREADY_EXIST 1
#define UNKNOWN_ERROR 2

typedef int ELEMENT_ST;
typedef ELEMENT_ST GROUP_ST[MAX];

void start(GROUP_ST group_element);
char insert(ELEMENT_ST element, GROUP_ST group_element);
char remove_element(ELEMENT_ST element, GROUP_ST group_element);
char pertinence(ELEMENT_ST element, GROUP_ST group_element);
void print(GROUP_ST group_element);

#endif