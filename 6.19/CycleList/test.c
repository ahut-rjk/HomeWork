#include"cycleList.h"

int main(){
	List *list = createList();
	insertNode(list, 1);
	insertNode(list, 2);
	insertNode(list, 3);
	insertNode(list, 4);
	insertNode(list, 5);
	insertNode(list, 6);
	insertNode(list, 7);
	displayList(list);
	Node *pnode = findNode(list, 1);
	printf("%d -> %d\n", pnode->item, pnode->next->item);	
	printf("length: %d\n", list->length);
	delNode(list, 1);
	printf("length: %d\n", list->length);
	insertNode(list, 11);
	displayList(list);
	pnode = findNode(list, 2);
	printf("%d -> %d\n", pnode->item, pnode->next->item);	
	destoryList(&list);
	return 0;
}
