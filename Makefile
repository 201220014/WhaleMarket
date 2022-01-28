.PHONY: clean # 伪目标

# 自定义环境变量
CC = gcc # 指定编译器

CFLAGS = -I include # 指定头文件目录
CFILES = $(shell find src -name "*.c") # 搜索所有的源文件
OBJS = $(CFILES:.c=.o) # 所有的目标文件
TARGET = main # 最终生成目标
DATA = src/data/*.txt # 搜索所有的数据文件

RM = -rm -f # 删除方式

all: $(TARGET)

# 项目构建方式
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%o : %c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS) $(DATA)
