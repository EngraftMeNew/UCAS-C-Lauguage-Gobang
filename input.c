/*
读取用户的输入，转化为落子
*/
#include "config.h"
#include "head.h"
#include <stdio.h>

void input_move(int turn)
{
    int row, col;
    scanf("%d %d", &row, &col);
    if (!is_legal_move(row - 1, col - 1, turn))
    {
        printf("Illegal move. Try again.\n");
        input_move(turn);
        return;
    }
    board[row - 1][col - 1] = turn;
    if (turn == BLACK)
    {
        last_row_black = row - 1;
        last_col_black = col - 1;
    }
    else if (turn == WHITE)
    {
        last_row_white = row - 1;
        last_col_white = col - 1;
    }
    last_color = turn;
    return;
}