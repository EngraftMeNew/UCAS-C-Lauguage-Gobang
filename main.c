/*
主函数，模式选择
*/
#include "head.h"
#include "config.h"
#include <stdio.h>
int main()
{
    init_board();
    board[5][7] = 1;
    board[6][7] = 2;
    display_board();
    return 0;
}