# 编译器类型
CC  = gcc
# 编译标准
STD = -std=c99
# 编译参数
ARG = -g -Wall 
# 可执行文件
BIN = sams
# 项目源文件
SRC = main.c sams.c admin.c teacher.c tools.c list.c
# 项目目标文件
OBJ = main.o sams.o admin.o teacher.o tools.o list.o

all:obj
	$(CC) -o $(BIN) $(OBJ)
obj:
	$(CC) -c $(AGR) $(SRC) $(STD)
clean:
	rm $(OBJ)
