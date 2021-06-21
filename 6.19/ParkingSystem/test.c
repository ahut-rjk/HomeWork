#include"List.h"

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
	printf("length: %d \n", getLength(list));
	printf("%d \n", findNode(list, 5)->item);
	delNode(list, 5);
	displayList(list);
	printf("length: %d \n", getLength(list));
	destoryList(list);
}
