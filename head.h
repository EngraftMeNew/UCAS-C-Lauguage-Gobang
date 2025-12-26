/*
总头文件，定义各种变量和函数
*/
#ifndef HEAD_H
#define HEAD_H

#include "config.h"

/*===========================显示相关===========================*/
extern const char play1Pic[]; // 黑棋子;
extern const char play1CurrentPic[];
extern const char play2Pic[]; // 白棋子;
extern const char play2CurrentPic[];

// 此数组用于记录当前的棋盘的格局
extern int board[SIZE][SIZE]; // to keep 0/1/2 for empty/black/white

// 此数组存储用于显示的棋盘
extern char Display_Board[SIZE][SIZE * CHARSIZE + 1];

// 空棋盘模板
extern const char Display_EmptyBoard[SIZE][SIZE * CHARSIZE + 1];

extern const int dirs[4][2];
/*attention: dx 对应col dy对应row*/

/*===========================棋盘维护相关===========================*/

extern int last_row_black;
extern int last_col_black;
extern int last_row_white;
extern int last_col_white;
extern int last_color;

void initBoard(void);
void DisplayBoard(void);
// void init_board(void);
// void display_board(void);
void input_move(int turn);
int is_in_board(int row, int col);
int is_legal_move(int row, int col, int color);
int count_continuous(int row, int col, int dx, int dy, int color); // 某一方向上连续棋子
int five_check(int row, int col, int color);
int overline(int row, int col, int color);

/*===========================棋形相关===========================*/
typedef struct
{
    int live_four;
    int rush_four;
    int live_three;
    int sleep_three;
} PatternStat; // 统计这个点所有方向上的棋形数量

extern PatternStat ps_black[SIZE][SIZE];
extern PatternStat ps_white[SIZE][SIZE];
// ps_[r][c] 表示：假设 color 落在 (r,c) 后，该点四方向的 PatternStat

void init_pattern_stats(void);
extern const char *pattern_live_four;
extern const char *pattern_rush_four;
extern const char *pattern_live_three;
//extern const char *pattern_sleep_three;

int extract_line(int row, int col, int dx, int dy, int color, char line[LINE_LEN + 1], int *center_idx);
int match_pattern(const char *line, int center_idx, const char *pattern);

void analyze_line(int row, int col, int color, int dx, int dy, PatternStat *out); // 单独分析某个方向
void analyze_point_patterns(int row, int col, int color, PatternStat *out);       // 某个点

/*===========================对战相关===========================*/
void pvp(void);
// void pve(void);
#endif