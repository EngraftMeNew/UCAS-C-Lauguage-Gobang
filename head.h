/*
总头文件，定义各种变量和函数
*/
#ifndef HEAD_H
#define HEAD_H

#include "config.h"
extern int board[BOARD_SIZE][BOARD_SIZE];
void init_board();
void display_board();
void input_move();
#endif