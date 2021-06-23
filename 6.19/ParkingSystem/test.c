#include"List.h"

int main(){
	List *list = createList();
	char buffer[100];
	CarInfo tmp;
	time_t now;
	strncpy(tmp.carNumber, "123456", 7);
	while(1){
		memset(buffer, 0, 100);
		printf("输入车牌号:\n");
		scanf("%s", buffer);
		if(!strcmp(buffer, "99999")){
			break;
		}
		CarInfo *info = (CarInfo*)malloc(sizeof(CarInfo));
		time(&now);
		info->timeinfo = localtime(&now);
		strcpy(info->carNumber, buffer);
		insertNode(list, *info);
	}
	displayList(list);
	printf("length: %d \n", getLength(list));
	//showItem(findNode(list, tmp)->item);
	delNode(list, tmp);
	displayList(list);
	printf("length: %d \n", getLength(list));
	destoryList(&list);
}
