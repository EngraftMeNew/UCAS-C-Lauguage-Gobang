/*
参数配置
*/
#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
#include "config.h"

#define BOARD_SIZE 15
#define SIZE BOARD_SIZE
#define CHARSIZE 3

#define EMPTY 0
#define BLACK 1
#define WHITE 2

#define AI_MAX_DEPTH 4

#define SCORE_FIVE 10000
#define SCORE_LIVE_FOUR 9999

// 一条线的最大长度（取9格：中心±4）
//  必须是奇数！
#define LINE_LEN 9

#define opposite_color(color) ((color) == BLACK ? WHITE : BLACK)

#endif