/*
棋形/禁手检查
*/
#include "config.h"
#include "head.h"
#include <stdio.h>

int is_in_board(int row, int col)
{
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}
int is_legal_move(int row, int col, int color)
{
    if (!is_in_board(row, col))
        return 0;
    if (board[row][col] != 0)
        return 0;
    // TODO:加入黑棋的禁手判断

    return 1;
}

int count_continuous(int row, int col, int dx, int dy, int color)
{
    int r = row;
    int c = col;
    int cnt = 0;
    while (is_in_board(r, c) && board[r][c] == color)
    {
        cnt++;
        r += dy;
        c += dx;
    }
    r = row - dy;
    c = col - dx;
    while (is_in_board(r, c) && board[r][c] == color)
    {
        cnt++;
        r -= dy;
        c -= dx;
    }
}

int five_check(int row, int col, int color)
{
    for (int i = 0; i < 4; i++)
    {
        int len = count_continuous(row, col, dirs[i][0], dirs[i][1], color);
        if (len >= 5)
            return 1;
    }
    return 0;
}