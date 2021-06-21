#include"cycleList.h"



List* createList(){
	List *list = (List*)malloc(sizeof(List));
	list->head = NULL:
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
	list->tail->next = list->tail;
	(list->length)++;
}

void delNode(List *list, elementType item){//若有多个相同元素每次只删除一个，可通过多次删除实现删除全部指定元素
	if(list == NULL){
		printf("list is NULL\n");
		return ;
	}
	if(getLength(list) > 0){
		Node *tNode = list->head;
		if(tNode->item == item){
			list->head = tNode->next;
			list->tail->next = list->head;
			--(head->length);
			return;
		}
		tNode = tNode->next;
		for(; tNode!=list->head; tNode=tNode->next){
			if(tNode->item == item){		
				if(tNode == list->tail){
					
				}
			}
		}
	}else{
		printf("fail to delete , no item in the list\n");
	}
}

