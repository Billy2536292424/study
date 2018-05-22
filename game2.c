#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include<string.h>
#include<stdio.h>


void init_board(char board[ROWS][COLS],char set,int row, int col)//初始化棋盘声明
{
	memset(board,set,row*col*sizeof(board[0][0]));
}
void display_board(char board[ROWS][COLS], int row, int col)//打印棋盘函数声明
{
	int i = 0;
	int j = 0;
	printf("  ");
	for(i=1; i<=col; i++)
	{
		printf("%d ",i);


	}
	printf("\n");
	for(i=1; i<row+1; i++)
	{
		printf("%d ",i);
		for(j=1; j<col+1; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}
void set_mine(char mine[ROWS][COLS])//设置雷
{
	int count =	COUNT;
	int x = 0;
	int y = 0;
	while(count>0)
	{
		x = rand()%ROW+1;
		y = rand()%COL+1;
		if(mine[x][y]=='0')
		{
			mine[x][y] = '1';
			count--;
		}

	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)//排雷成功条件
{
	return mine[x-1][y-1]+
		mine[x][y+1]+
		mine[x+1][y+1]+
		mine[x-1][y]+
		mine[x+1][y]+
		mine[x-1][y+1]+
		mine[x][y-1]+
		mine[x+1][y-1]-8*'0';
}
