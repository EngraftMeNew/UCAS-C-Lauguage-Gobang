/*
总头文件，定义各种变量和函数
*/
#ifndef HEAD_H
#define HEAD_H

#include "config.h"
extern int board[BOARD_SIZE][BOARD_SIZE];

const int dirs[4][2] = { //{dx,dy}
    {1, 0},
    {0, 1},
    {1, 1},
    {1, -1}};
/*attention: dx 对应col dy对应row*/

void init_board(void);
void display_board(void);
void input_move(void);
int is_in_board(int row, int col);
int is_legal_move(int row, int col, int color);
int count_continuous(int row, int col, int dx, int dy, int color); // 某一方向上连续棋子
int five_check(int row, int col, int color);
int overline(int row, int col, int color);

typedef struct
{
    int live_four;
    int rush_four;
    int live_three;
    int sleep_three;
} pattern;

void analyze_line(int row, int col, int color, int dx, int dy, pattern *out); // 单独分析某个方向
void analyze_point_patterns(int row, int col, int color, pattern *out);       // 某个点

#endif