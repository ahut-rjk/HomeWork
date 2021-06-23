#include"cycleList.h"



List* createList(){
	List *list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

int isEmpty(List *list){
	if(list == NULL){
		printf("list is NULL\n");
		return -1;
	}
	return list->length == 0;
}

int getLength(List *list){
	return list->length;
}

void insertNode(List *list, elementType item){//头插
	if(list == NULL){
		printf("list is NULL\n");
		return ;
	}
	Node *pnode = (Node*)malloc(sizeof(Node));
	pnode->item = item;
	pnode->next = NULL;
	if(isEmpty(list)){
		list->head = list->tail = pnode;
		list->tail->next = list->head;
		++(list->length);
		return;
	}
	pnode->next = list->head;
	list->head = pnode;
	list->tail->next = list->head;
	++(list->length);
}

void delNode(List *list, elementType item){//若有多个相同元素每次只删除一个，可通过多次删除实现删除全部指定元素
	if(list == NULL){
		printf("list is NULL\n");
		return ;
	}
	if(getLength(list) == 0){//认为对空链做删除是异常情况，给出提示
		printf("fail to delete , no item in the list\n");
		return ;
	}

	Node *curNode = list->head;
	Node *preNode = NULL;
	if(curNode->item == item){
		list->head = curNode->next;
		list->tail->next = list->head;
		--(list->length);
		free(curNode);
		return;
	}
	preNode= curNode;
	curNode = curNode->next;
	for(; curNode!=list->head; preNode=curNode, curNode=curNode->next){
		if(curNode->item == item){		
			preNode->next = curNode->next;
			--(list->length);
			if(curNode == list->tail){
				list->tail = preNode;
			}
			free(curNode);
			curNode = NULL;
			break;
		}
	}
}

Node* findNode(List *list, elementType item){
	if(list == NULL){
		printf("list is NULL\n");
		return NULL;
	}
	if(getLength(list) == 0){
		return NULL;
	}
	Node* curNode = list->head;
	if(curNode->item == item){
		return curNode;
	}
	curNode = curNode->next;
	for(; curNode!=list->head; curNode=curNode->next){
		if(curNode->item == item){
			break;
		}
	}
	return curNode==list->head ? NULL : curNode; 
}

void destoryList(List **plist){
	List *list = *plist;
	if(plist == NULL || list == NULL){
		printf("list is NULL\n");
		return ;
	}
	if(getLength(list) == 0){
		free(list);
		*plist = NULL;
		return ;
	}
	Node *curNode = list->head;
	Node *tNode = curNode;
	curNode = curNode->next;
	free(tNode);
	for(; curNode!=list->head; ){
		tNode = curNode;
		curNode = curNode->next;
		free(tNode);
	}
	free(list);
	*plist = NULL;
}

void displayList(List *list){
	if( list == NULL){
		printf("list is NULL\n");
		return ;
	}
	if(getLength(list) == 0){	
		return ;
	}
	Node *curNode = list->head;
	printf("%d ", curNode->item);
	curNode = curNode->next;
	for(; curNode!=list->head; curNode=curNode->next){
		printf("%d ", curNode->item);
	}
	printf("\n");
}

