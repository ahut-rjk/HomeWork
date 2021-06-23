#ifndef __LIST_H__
#define __LIST_H__

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#define elementType CarInfo

typedef struct CARINFO{
	char carNumber[20];
	struct tm timeinfo;//time.h库,获取系统时间
}CarInfo;

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
void destoryList(List** plist);
void displayList(List* list);

int isEqual(elementType itemA, elementType itemB);
void showItem(elementType item);
#endif
