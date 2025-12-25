/*
用来供人人对战
*/

#include "head.h"
#include <stdio.h>

void pvp()
{
    int turn = BLACK; // 1 for black, 2 for white
    while (1)
    {
        printf("Player %d's turn. Please input your move (row col): ", turn);
        input_move(turn);

        DisplayBoard();
        turn = opposite_color(turn);
        if (five_check(last_color == BLACK ? last_row_black : last_row_white,
                       last_color == BLACK ? last_col_black : last_col_white,
                       last_color))
        {
            printf("Player %d wins!\n", last_color);
            break;
        }
    }
    return;
}