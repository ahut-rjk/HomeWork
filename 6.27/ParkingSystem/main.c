#include"menu.h"
#include"service.h"

typedef void (*FuncType)();

int main(){
	char opt;
	FuncType serviceFuncs[5] = {myExit, add, myRemove, find, showAll}; 
	init();
	while(1){
		showMenu();
		showRemain();
		printf("请选择操作:\n");
		scanf("%c", &opt);
		while (getchar() != '\n');
		if(opt>='0' && opt<='4')
		{
			printf("\x1b[H\x1b[2J");//清屏作用
			serviceFuncs[opt-'0']();
			printf("\x1b[H\x1b[2J");
		}
		else
		{
			printf("除了菜单选项其它的我理解不了的，客官重新输入试试.....\n");
		}
		if(opt == '0'){
			break;
		}
	}
	return 0;
}
