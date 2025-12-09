/*
显示与UI
*/

#include "config.h"
#include "head.h"
#include <stdio.h>

void display_board()
{
    int i, j;

    // 打印列号（1~15）
    printf("   ");
    for (j = 0; j < BOARD_SIZE; j++)
    {
        printf("%3d ", j + 1);
    }
    printf("\n");

    // 每一行
    for (i = 0; i < BOARD_SIZE; i++)
    {
        int col;

        // 打印分隔线：+---+---+...
        printf("   ");
        for (col = 0; col < BOARD_SIZE; col++)
        {
            printf("+---");
        }
        printf("+\n");

        // 打印行号
        printf("%2d ", i + 1);

        // 打印每一列的格子和棋子
        for (j = 0; j < BOARD_SIZE; j++)
        {
            const char *ch;
            if (board[i][j] == 1)
                ch = "X"; // 黑子
            else if (board[i][j] == 2)
                ch = "O"; // 白子
            else
                ch = " "; // 空

            printf("| %s ", ch);
        }
        printf("|\n");
    }

    // 最底下一条分隔线
    printf("   ");
    for (j = 0; j < BOARD_SIZE; j++)
    {
        printf("+---");
    }
    printf("+\n");
}