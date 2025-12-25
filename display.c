/*
显示与UI
*/

#include "config.h"
#include "head.h"
#include <stdio.h>

int last_row_black;
int last_col_black;
int last_row_white;
int last_col_white;
int last_color;

static void put_cell(char rowbuf[], int col, const char *utf8_piece)
{
    int pos = col * CHARSIZE;
    memcpy(&rowbuf[pos], utf8_piece, CHARSIZE);
}

void DisplayBoard(void)
{
    // 1) 先把空棋盘模板复制到显示棋盘
    for (int r = 0; r < SIZE; r++)
    {
        memcpy(Display_Board[r], Display_EmptyBoard[r], SIZE * CHARSIZE);
        Display_Board[r][SIZE * CHARSIZE] = '\0';
    }

    // 2) 把棋子写进去
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            int v = board[r][c];
            if (v == 1)
            {
                // 黑棋：如果是当前落子点，用 ▲
                if (r == last_row_black && c == last_col_black && last_color == 1)
                    put_cell(Display_Board[r], c, play1CurrentPic);
                else
                    put_cell(Display_Board[r], c, play1Pic);
            }
            else if (v == 2)
            {
                // 白棋：如果是当前落子点，用 △
                if (r == last_row_white && c == last_col_white && last_color == 2)
                    put_cell(Display_Board[r], c, play2CurrentPic);
                else
                    put_cell(Display_Board[r], c, play2Pic);
            }
            // v==0 空，不改模板
        }
    }

    // 3) 清屏
    // system("cls");

    // 4) 打印
    printf("  ");
    for (int c = 0; c < SIZE; c++)
        printf("%d", c+1);
    putchar('\n');

    // === 4) 打印每行：行号 + 棋盘行 ===
    for (int r = 0; r < SIZE; r++)
    {
        printf("%2d ", r+1);      // 行号
        puts(Display_Board[r]); // 原来的棋盘行字符串
    }
}