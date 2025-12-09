/*
读取用户的输入，转化为落子
*/
#include "config.h"
#include "head.h"
#include <stdio.h>

void input_move()
{
    int row, col;
    scanf("%d %d", &row, &col);
    board[row - 1][col - 1] = 1;
    return ;
}