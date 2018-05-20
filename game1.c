#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
void init_board(char board[ROWS][COLS], int row, int col)//初始化棋盘函数
{
	memset(board,' ',row*col*sizeof(char));

}
void display_board(char board[ROWS][COLS], int row, int col)//打印棋盘函数
{
	int i = 0;
	for(i=0; i<row; i++)//将棋盘打印出来
	{
		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		if(i!=2)
			printf("---|---|---\n");
	}
	
}
void player_move(char board[ROWS][COLS], int row, int col)//玩家下
{
	int x = 0;
	int y = 0;
	while(1)
	{
	printf("请输入坐标:>");
	scanf("%d%d",&x,&y);
	x--;
	y--;
	if(((x>=0)&&(x<=2))&&((y>=0)&&(y<=2)))//判断输入坐标是否合理
	{
	if(board[x][y] == ' ')//判断所下位置是否已经下过
	{
		{
			board[x][y] = 'X';
		break;
		}
	}
	else
	{
		printf("坐标错误,重新输入\n");
	}
	}
	else
	{
		printf("坐标错误，重新输入\n");
	}
	}


}
void computer_move(char board[ROWS][COLS], int row, int col)//电脑下
{
	int x = 0;
	int y = 0;
	while(1)
	{
		x = rand()%3;
		y = rand()%3;
	
	
	if(board[x][y]==' ')
	{
		board[x][y] = '$';
	    break;
	
	}
	
	}
	
}
static int is_full(char board[ROWS][COLS], int row, int col)//判断棋盘是否已经下满
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
		{
		if(board[i][j]==' ')
			return 0;
		}
	return 1;
}
char check_win(char board[ROWS][COLS], int row, int col)//判断输赢
{
	int i = 0;
	for(i=0; i<row; i++)//同行的三个相同
	{
	if((board[i][0]==board[i][1])&&
		(board[i][1]==board[i][2])&&
		(board[i][1]!=' '))
		return board[i][1];
	}
	for(i=0; i<col; i++)//同列的三个相同
	{
	if((board[0][i]==board[1][i])&&
		(board[1][i]==board[2][i])&&
		(board[1][i]!=' '))
		return board[1][i];
	}
	if((board[0][0]==board[1][1])&&
		(board[1][1]==board[2][2])&&
		(board[1][1]!=' '))//对角线三个相同
		return board[1][1];
	if((board[0][2]==board[1][1])&&
		(board[1][1]==board[2][0])&&
		(board[1][1]!=' '))//对角线三个相同
		return board[1][1];
	
	if (is_full(board,row,col))

	{
		return 'q';
	}
	return ' ';
}
