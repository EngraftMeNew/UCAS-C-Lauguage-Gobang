# 中国科学院大学C语言五子棋

---

~~我在24年因为偷懒没认真写五子棋，落得遗憾，碰巧今年遇上一些特殊情况，打算重新写一遍，先开个仓库~~

目前只有大体框架，还没有写具体的代码，等有时间了一点点补充上去。

一键编译命令：mingw32-make.exe

（需在gobang目录下）

运行命令： ./main.exe

when input : we input 1-15

when check in program,we use 0-14

attention!

已完成：
1）棋盘与显示
initboard
displayboard

2)输入与合法性
input_move
is_in_board
is_legal_move(缺少对黑棋禁手的检查)

3)
count_continues 连续棋子数目
five_check

4）
extract_line 提取一行
match_pattern 匹配
黑棋legal判断
analyze_line(int row, int col, int color, int dx, int dy, PatternStat *out); // 单独分析某个方向
analyze_point_patterns(int row, int col, int color, PatternStat *out);       // 某个点

待做：
算杀部分
minimax部分

"now, we r in ldr's computer for test"
