CC = gcc

CFLAGS = -g -Wall -Wextra -O4 -fexec-charset=UTF-8 -finput-charset=UTF-8

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

TARGET = main.exe

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@if exist $(TARGET) del $(TARGET)
	@if exist *.o del *.o

run:
	$(TARGET)


rerun: all run
