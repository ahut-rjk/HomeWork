#ifndef __CYCLE_LIST_H__
#define __CYCLE_LIST_H__

#include<stdio.h>
#include<stdlib.h>

#define elementType int

typedef struct NODE{
	elementType item;
	struct NODE *next;
}Node;

type struct LIST{
	Node *head;
	Node *tail;
	int length;
}List;

List* createList();
void destoryList(List *list);
int isEmpty(List *list);
int getLength(List *list);
void insertNode(List *list, elementType item);
void delNode(List *list, elementType item);
Node* findNode(List *list, elementType item); 
void displayList(List *list);

#endif
