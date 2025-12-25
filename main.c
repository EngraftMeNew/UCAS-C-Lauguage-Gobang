/*
主函数，模式选择
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include "head.h"
#include "config.h"
#include <stdio.h>

const char play1Pic[] = "●"; // 黑棋子;
const char play1CurrentPic[] = "▲";

const char play2Pic[] = "◎"; // 白棋子;
const char play2CurrentPic[] = "△";

// 此数组用于记录当前的棋盘的格局
int arrayForInnerBoardLayout[SIZE][SIZE]; // to keep 0/1/2 for empty/black/white
// 此数组存储用于显示的棋盘
char Display_Board[SIZE][SIZE * CHARSIZE + 1];

// 空棋盘模板
const char Display_EmptyBoard[SIZE][SIZE * CHARSIZE + 1] =
    {
        "┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛"};

const int dirs[4][2] = { //{dx,dy}
    {1, 0},
    {0, 1},
    {1, 1},
    {1, -1}};
/*attention: dx 对应col dy对应row*/

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    initBoard();
    int mode = 0;
    printf("==============================\n");
    printf("please input your mode choose:\n");
    printf("1 for pvp\n");
    printf("2 for pvp\n");
    printf("==============================\n");
    printf("Your choice: ");
    scanf("%d", &mode);
    DisplayBoard();
    if (mode == 1)
    {
        pvp();
    }

    // input_move();
    // input_move();
    // display_board();
    return 0;
}