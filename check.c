/*
棋形/禁手检查
*/
#include "config.h"
#include "head.h"
#include <stdio.h>
#include <string.h>

const char *pattern_live_four = "011110";
const char *pattern_rush_four = "011112|211110|10111|11011|11101";
const char *pattern_live_three = "011100|001110|011010|010110";
const char *pattern_sleep_three = "0011120|0211100|2011100|0011200|0021100|0101120|0121000|0101210|0110120|0211010|0102110";
// TODO:检查pattern是否正确

// row,col shoule be [0,15)
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
    if (color == BLACK)
    {
        board[row][col] = color;
        for (int i = 0; i < 4; i++)
        {
            int len = count_continuous(row, col, dirs[i][0], dirs[i][1], color);
            if (len > 5)
            {
                board[row][col] = 0;
                return 0; // overline禁手
            }
        }
        PatternStat ps = {0};
        analyze_point_patterns(row, col, color, &ps);
        board[row][col] = 0;
        // 禁手判断
        if (ps.live_four + ps.rush_four >= 2)
            return 0; // 四四禁手
        if (ps.live_three >= 2)
            return 0; // 双活三禁手
    }
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
    return cnt;
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

// 提取出一个方向上左右各四个到Line数组，center_idx为当前子坐标
int extract_line(int row, int col, int dx, int dy, int color, char line[LINE_LEN + 1], int *center_idx)
{
    int idx = 0;
    int max_k = LINE_LEN / 2;
    for (int k = -max_k; k <= max_k; k++)
    {
        int r = row + k * dy;
        int c = col + k * dx;
        char ch;
        if (!is_in_board(r, c))
        {
            ch = '3';
        }
        else if (board[r][c] == 0)
        {
            ch = '0';
        }
        else if (board[r][c] == color)
        {
            ch = '1'; // 己方
        }
        else
            ch = '2'; // 对方
        line[idx++] = ch;
    }
    line[idx] = '\0';
    *center_idx = max_k;
    return idx;
}

// 匹配某一种特殊棋形
int match_pattern(const char *line, int center_idx, const char *pattern)
{
    if (!line || !pattern)
        return 0;

    // normalize: treat '3'(out of board) as '2'(blocked)
    char norm[LINE_LEN + 1];
    int n = (int)strlen(line);
    for (int i = 0; i < n; i++)
        norm[i] = (line[i] == '3') ? '2' : line[i];
    norm[n] = '\0';

    unsigned int used_start[LINE_LEN] = {0};
    int cnt = 0;
    //  iterate alternatives separated by '|'
    const char *p = pattern;
    while (*p)
    {
        // alt starts at p, ends before '|' or '\0'
        const char *q = p;
        while (*q && *q != '|')
            q++;
        int m = (int)(q - p); // length of this alternative

        if (m > 0)
        {
            // try every start position s in norm where substring length m fits
            for (int s = 0; s + m <= n; s++)
            {
                // must cover center_idx
                if (!(s <= center_idx && center_idx < s + m))
                    continue;

                int ok = 1;
                for (int k = 0; k < m; k++)
                {
                    if (norm[s + k] != p[k])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                    if (!used_start[s])
                    {
                        used_start[s] = 1;
                        cnt++;
                    }
            }
        }

        // move to next alternative
        p = (*q == '|') ? (q + 1) : q;
    }
    return cnt;
}

/*==================对于一个点==================*/

/*调用顺序：
is_legal_move?  ->analyze_point_patterns    ->analyze_line  ->  extract_line+match_pattern
是否合法？  统计这个点所有方向上的棋形数量   单独分析某个方向    提取出一个方向上左右各四个到Line数组，匹配某一种特殊棋形
 */
// 单独分析某个方向
void analyze_line(int row, int col, int color, int dx, int dy, PatternStat *out)
{
    char line[LINE_LEN + 1];
    int center;
    extract_line(row, col, dx, dy, color, line, &center);

    out->live_four += match_pattern(line, center, pattern_live_four);
    out->rush_four += match_pattern(line, center, pattern_rush_four);
    out->live_three += match_pattern(line, center, pattern_live_three);
    out->sleep_three += match_pattern(line, center, pattern_sleep_three);
}

// 某个点
void analyze_point_patterns(int row, int col, int color, PatternStat *out)
{
    out->live_four = out->rush_four = out->live_three = out->sleep_three = 0;
    for (int i = 0; i < 4; i++)
    {
        analyze_line(row, col, color, dirs[i][0], dirs[i][1], out);
    }
}
