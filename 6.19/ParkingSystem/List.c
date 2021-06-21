#include"List.h"


List* createList(){
	List* list = (List*)malloc(sizeof(List));
	if(list == NULL){
		printf("fail to get memory\n");
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

int isEmpty(List* list){
	if(list == NULL){
		printf("list is NULL\n");
		return -1;
	}
	return list->head == NULL;
}

void insertNode(List* list, elementType item){//头插
	if(list == NULL){
		printf("list is NULL\n");
		return ;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	node->item = item;
	node->next = NULL;
	if(isEmpty(list)){
		list->head = node;
		list->tail = node;
		++(list->length);
		return;
	}
	node->next = list->head;
	list->head = node;
	++(list->length);
}

Node* findNode(List* list, elementType item){
	if(list == NULL){
		printf("Head is NULL\n");
		return NULL;
	}
	if(isEmpty(list)){
		printf("there is no items in list\n");
		return NULL;
	}
	Node* p;
	for(p=list->head; p!=NULL; p=p->next){
		if(p->item == item){
			break;
		}
	}
	return p;
}

int getLength(List *list){
	return list->length;
}

void delNode(List* list, elementType item){
	if(list == NULL){
		printf("Head is NULL\n");
		return ;
	}
	Node *p, *pre;
	for(p = list->head; p!= NULL; pre = p,p = p->next){
		if(p->item == item){
			break;
		}
	}
	if(p == NULL){	
		printf("fail to delete item from list,it is not in the list");
		return ;
	}
	(list->length)--;
	if(p == list->head){
		list->head  = p->next;
		free(p);
		return;
	}
	if(p == list->tail){
		list->tail = pre;
		list->tail->next = NULL;
		free(p);
		return;
	}
	pre->next = p->next;
	free(p);
}
void destoryList(List* list){		
	if(list == NULL){
		printf("list is NULL");
		return ;
	}
	for(Node* p=list->head; p!=NULL;){
		Node* temp = p;
		p = p->next;
		free(temp);
	}
	free(list);
	list = NULL;
}

void displayList(List* list){
	if(list == NULL){
		printf("list is NULL");
		return;
	}
	for(Node* p=list->head; p!=NULL; p=p->next){
		 printf("%d ", p->item);//待改进，要根据elementType来做输出处理......
	}
	printf("\n");
}
