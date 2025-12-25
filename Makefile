CC = gcc

CFLAGS = -g -Wall -Wextra -O4 -fexec-charset=UTF-8 -finput-charset=UTF-8

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = main.exe

all: clean $(TARGET)

preclean:
	-@taskkill /IM $(TARGET) /F >nul 2>nul || exit 0
	-@if exist $(TARGET) del /F /Q $(TARGET)
	-@if exist *.o del /F /Q *.o
	
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist $(TARGET) del $(TARGET)
	@if exist *.o del *.o

# 注意：PowerShell/cmd 都能执行 chcp；加 >nul 让它不输出那句提示
run:
	@powershell -NoProfile -Command "chcp 65001 *> $$null; [Console]::OutputEncoding=[Text.UTF8Encoding]::new(); [Console]::InputEncoding=[Text.UTF8Encoding]::new(); .\$(TARGET)"


rerun: all run
