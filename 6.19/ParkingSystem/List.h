#ifndef __LIST_H__
#define __LIST_H__

#include<stdlib.h>
#include<stdio.h>
#define elementType int

typedef struct NODE {
	 elementType item;
	 struct NODE * next;
}Node;

typedef struct LIST{
	Node* head;
	Node* tail;
	int length;
}List;

List* createList();
int isEmpty(List* list);
int getLength(List *list);
void insertNode(List* list, elementType item);
Node* findNode(List* list, elementType item);
void delNode(List* list, elementType item);
void destoryList(List* list);
void displayList(List* list);
#endif
