#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"

void game()
{
    char board[ROWS][COLS] = {0};
	int ret = 0;
	init_board(board,ROWS, COLS);//初始化棋盘
	display_board(board,ROWS, COLS);//打印棋盘
	//srand((unsigned int)time(NULL));
	//产生一个随机值
	while(1)
	{
		player_move(board, ROWS, COLS);//玩家下
	if ((ret = check_win(board,ROWS,COLS)) != ' ')
//若所下坐标不为空，则跳出重新打印
		break;
	display_board(board,ROWS, COLS);
	
	computer_move(board, ROWS, COLS);
	if ((ret = check_win(board,ROWS,COLS)) != ' ')//若所下坐标不为空，跳出重新打印

		break;
	display_board(board, ROWS, COLS);


	}
	if(ret == 'X')//check_win函数的返回值是“X”
	{
		printf("玩家赢\n");
	}
	else if(ret == '$')//...
	{
		printf("电脑赢\n");
	}
	else if(ret == 'q')//...
	{
		printf("平局\n");
	}

	display_board(board, ROWS,COLS);//返回值是' '重新打印
}
void menu()//打印菜单
{
	printf("**********************\n");
	printf("**** 1.play 0.exit ***\n");
	printf("**********************\n");

}

void test()
{
	int input = 0;
srand((unsigned int)time(NULL));//产生一个随机值
	do
	{
	menu();
	printf("请选择:>");
	scanf("%d", &input);
	switch(input)//玩家输入选择开始游戏
	{
	case 1:
		game();
		break;
		
	case 0:
		break;
	default://输入除0 1外其他无效选项，打印提示信息
		printf("输入错误\n");
		break;
	}
	}
	while(input);
	
}


int main()
{
	test();
	return 0;
}
