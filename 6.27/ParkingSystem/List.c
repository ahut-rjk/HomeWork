#include"List.h"


List* createList(int maxSize){//maxSize为-1时表示没有容量限制
	List* list = (List*)malloc(sizeof(List));
	if(list == NULL){
		printf("fail to get memory\n");
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	list->maxSize = maxSize;
	return list;
}

int isEmpty(List* list){
	if(list == NULL){
		printf("list is NULL\n");
		return -1;
	}
	return list->head == NULL;
}

int isFull(List* list){
	if(list == NULL){
		printf("list is NULL\n");
		return -1;
	}
	if(list->maxSize == -1){
		return 0;
	}
	return list->maxSize <= list->length;
}

void insertNode(List* list, elementType item){//头插
	if(list == NULL){
		printf("list is NULL\n");
		return ;
	}
	if(isFull(list)){
		printf("list is full\n");
		return;
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
		if(isEqual(p->item, item)){
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
		printf("list is NULL\n");
		return ;
	}
	if(getLength(list) == 0){//对在空链上的删除操作给出提示
		printf("fail to delete, no item in the list\n");
		return ;
	}
	Node *p, *pre;
	for(p = list->head; p!= NULL; pre = p,p = p->next){
		if(isEqual(p->item, item)){
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
void destoryList(List **plist){		
	List *list = *plist;
	if(plist == NULL || list == NULL){
		printf("list is NULL");
		return ;
	}
	if(isEmpty(list)){
		free(list);
		*plist = NULL;
	}
	for(Node* p=list->head; p!=NULL;){
		Node* temp = p;
		p = p->next;
		free(temp);
	}
	free(list);
	*plist = NULL;
}

void displayList(List* list){
	if(list == NULL){
		printf("list is NULL");
		return;
	}
	for(Node* p=list->head; p!=NULL; p=p->next){
		 showItem(p->item);
		//printf("%d ", p->item);//待改进，要根据elementType来做输出处理......
	}
	printf("\n");
}

void showItem(elementType item){
	printf("车牌号：%s \n入库时间:%d-%d-%d %d:%02d:%02d\n", item.carNumber, item.timeinfo.tm_year+1900,
		item.timeinfo.tm_mon+1, item.timeinfo.tm_mday, item.timeinfo.tm_hour, item.timeinfo.tm_min, item.timeinfo.tm_sec);	
}

int isEqual(elementType itemA, elementType itemB){
	return strcmp(itemA.carNumber, itemB.carNumber) == 0;
}


