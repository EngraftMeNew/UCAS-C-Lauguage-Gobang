/*
AI下棋
*/

#include "head.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


static int pattern_score(const PatternStat *ps)
{
    int s = 0;
    s += ps->live_four * 1000000;
    s += ps->rush_four * 200000;
    s += ps->live_three * 20000;
    s += ps->sleep_three * 2000;
    return s;
}

// 对某点给分：进攻分 + 防守分(对手在这里能有多强)
int eval_move(int row, int col, int color)
{
    if (!is_legal_move(row, col, color))
        return INT_MIN / 4;

    // 试落子
    board[row][col] = color;

    // 直接成五：最高分
    if (five_check(row, col, color))
    {
        board[row][col] = 0;
        return INT_MAX / 4;
    }

    PatternStat me = {0};
    analyze_point_patterns(row, col, color, &me);

    // 撤销
    board[row][col] = 0;

    // 防守：如果对手在这里下很强，我也应该优先占掉
    int opp = opposite_color(color);
    int def = 0;
    if (is_legal_move(row, col, opp))
    {
        board[row][col] = opp;
        PatternStat him = {0};
        analyze_point_patterns(row, col, opp, &him);
        board[row][col] = 0;
        def = pattern_score(&him);
    }

    return pattern_score(&me) + (def * 8 / 10); // 防守权重 0.8，你可调
}
