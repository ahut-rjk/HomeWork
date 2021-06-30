#include"service.h"

List *list;	

void init(){
	list = createList(9999);
}

void add(){
	while(1){
		time_t now;
		char tag;
		CarInfo *info = (CarInfo*)malloc(sizeof(CarInfo));
		printf("输入入库车牌号：\n");
		scanf("%s",info->carNumber);
		while (getchar() != '\n');
		time(&now);
		info->timeinfo = *localtime(&now);
		insertNode(list, *info);	
		printf("入库成功\n");
		showRemain();
		printf("您可以输入\"0\",返回菜单,输入其它内容则继续入库.....\n");
		scanf("%c", &tag);
		while (getchar() != '\n');//清空输入缓存，避免影响下次输入
		if(tag == '0'){
			break;
		}
	}
}

void myRemove(){
	char tag;
	time_t now;
	time_t past;
	time_t until;
	CarInfo tinfo;
	Node *tnode;
	while(1){
		printf("输入需要出库车辆车牌号：\n");
		scanf("%s", tinfo.carNumber);
		while (getchar() != '\n');
		tnode = findNode(list, tinfo);
		if( tnode != NULL){
			printf("将删除的车辆信息:\n");
			showItem(tnode->item);
			past = mktime(&(tnode->item.timeinfo));
			now = time(&now);
			until = now - past;
			if(until%3600 != 0){
				printf("停留时长：%dh %d min \n", until/3600, (until%3600)/60);
				until = until/3600+1;
			}else{
				printf("停留时长：%dh %d min \n", until/3600, (until%3600)/60);
				until = until/3600;			
			}	
			printf("应缴费用：%d ￥(每小时5元，未满一小时的按一小时计费)\n", until*5);
			printf("确认出库？输入\"1\"继续出库，输入\"2\" 重新输入车辆信息，输入\"0\",返回菜单.....\n");
			int flag = 1 ;
			while(flag != 0){
				scanf("%c", &tag);
				while (getchar() != '\n');
				switch(tag){
					case '0': return;
					case '1':
						delNode(list, tinfo);
						flag = 0;
						break;
					case '2':
						flag = 0;
						break;
					default:
						printf("输入不合法,请重新输入\n");
						break;
				}
			}
			if(tag == '1'){
				printf("出库成功\n");
				showRemain();
				printf(" 您可以输入\"0\"，返回菜单，或任意输入其它内容继续出库.....\n");
				scanf("%d", &tag);
				while (getchar() != '\n');
				if(tag == 0){
					break;
				}
			}
		}else{
			printf("库内未查到有该车辆,请检查输入信息!\n");
			printf("您可以输入\"1\" 选择继续出库车辆, 或者输入\"0\"，返回菜单.....\n");
			scanf("%c", &tag);
			while (getchar() != '\n');
			if(tag == '0'){
				break;
			}
		}
	}	
}

void find(){
	while(1){
		Node *node;
		CarInfo tinfo;
		char tag;
		printf("输入需要查找的车牌号\n");
		scanf("%s", tinfo.carNumber);
		while (getchar() != '\n');
		node = findNode(list, tinfo);
		if(node!=NULL){
			printf("查找到信息如下:\n");
			showItem(node->item);
		}else{
			printf("记录信息中没有找到相关内容，请检查车牌号！\n");
		}
		printf("你可以输入\"0\",返回菜单，输入其它内容继续查找......\n");
		scanf("%c", &tag);
		while (getchar() != '\n');
		if(tag == '0'){
			break;
		}
	}
}

void myExit(){
	destoryList(&list);
}

void showAll(){
	char tag;
	printf("目前记录了以下信息：\n");
	displayList(list);
	printf("输入任意内容返回主菜单......\n");
	scanf("%c", &tag);
	while (getchar() != '\n');
}
void showRemain(){
	printf("剩余车位：%d \n", list->maxSize-list->length);
	printf("=================================\n");
}
