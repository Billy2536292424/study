#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**********************\n");
	printf("*****1.play0.exit*****\n");
	printf("**********************\n");
}
void game()
{
	char mine[ROWS][COLS] = {0};//记录雷的信息
	char show[ROWS][COLS] = {0};//排出雷的信息
	int x = 0;
	int y = 0;
	int win = 0;
	init_board(mine, '0',ROWS, COLS);//初始化棋盘
	init_board(show, '*', ROWS, COLS);//初始化棋盘

	set_mine(mine);
	display_board(mine, ROW, COL);//打印棋盘
	display_board(show, ROW, COL);//...
	while(win < ROW*COL-COUNT)
	{
		printf("请输入要排查的坐标：>");
		scanf_s("%d%d",&x,&y);
		if(((x>=1)&&(x<=9))&&((y>=1)&&(y<=9)))//判断坐标是否合理
		{
			if(mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				break;
			}
			else
			{
				//统计周围雷的个数
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				win++;
				display_board(show, ROW, COL);
			}
		}
		else
		{	
			printf("坐标非法\n");
		}
	}

	if(win==ROW*COL-COUNT)//结束条件
	{
		printf("恭喜排雷成功\n");
	}
}

void test()
{	

	int input = 0;
	srand((unsigned int)time(NULL));//使用随机函数
	do
	{
		menu();//打印菜单
		printf("请选择>:");//玩家选择开始游戏
		scanf_s("%d",&input);//接收玩家选择结果
		switch(input)
		{
		case 1:
			game();//开始游戏
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入>");
			break;
		}
	}
	while(input);
}

int main()
{

	test();//测试
	return 0;
}
