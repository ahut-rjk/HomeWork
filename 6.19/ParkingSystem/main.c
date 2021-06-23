#include"menu.h"
#include"service.h"
int main(){
	char opt;
	init();
	printf("\x1b[H\x1b[2J");
	showMenu();
	while(1){
		printf("请选择操作:\n");
		scanf("%c", &opt);
		while (getchar() != '\n');
		switch(opt){
			case '1': 
				add();
				printf("\x1b[H\x1b[2J");//清屏作用
				showMenu();
				break;
			case '2':
				myRemove();
				printf("\x1b[H\x1b[2J");
				showMenu();
				break;
			case '3':
				find();
				printf("\x1b[H\x1b[2J");
				showMenu();
				break;
			case '4':
				showAll();
				break;
			case '0':
				myExit();
				break;
			default:
				printf("除了菜单选项其它的我理解不了的，客官重新输入试试.....\n");
				break;
		}
		if(opt == '0'){
			break;
		}
	}
	return 0;
}
