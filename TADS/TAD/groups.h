#ifndef GROUPS_H
#define GROUPS_H

#define max 200

#define NO_ERROR_FOUND 0
#define ALREADY_EXIST 1
#define ANY_ERROR 2

typedef int element_st;
typedef element_st group_st[max];

void start(group_st c);
char insert(element_st e, group_st c);
char remove_item(element_st e, group_st c);
char belong(element_st e, group_st c);
void print(group_st c);

#endif