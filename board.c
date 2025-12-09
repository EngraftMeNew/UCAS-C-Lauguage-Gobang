/*
棋盘的维护
定义
初始化
落子/悔子
是否在棋盘内
*/

#include "config.h"
#include "head.h"

int board[BOARD_SIZE][BOARD_SIZE];

void init_board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
}