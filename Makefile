# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall -Wextra -O2 -I.

# 目标文件
OBJS = list_sort.o main.o pdqsort.o queue.o timsort.o harness.o report.o

# 生成的可执行文件名
TARGET = main

# 规则开始

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 依赖关系
list_sort.o: list_sort.c list_sort.h list.h
main.o: main.c list_sort.h pdqsort.h queue.h timsort.h harness.h
pdqsort.o: pdqsort.c pdqsort.h
queue.o: queue.c queue.h list.h harness.h
timsort.o: timsort.c timsort.h
harness.o: harness.c harness.h report.h
report.o: report.c report.h
