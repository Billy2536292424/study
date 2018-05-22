#define _CRT_SECURE_NO_WARNINGS
//#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define COUNT 77//雷数

#define COL 9
#define ROW 9

#define COLS COL+2
#define ROWS COL+2

//
void init_board(char board[ROWS][COLS],char set, int row, int col);
void display_board(char board[ROWS][COLS], int row, int col);
void set_mine(char mine[ROWS][COLS]);
int get_mine_count(char mine[ROWS][COLS], int x, int y);


#endif //扫雷小游戏
