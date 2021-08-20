SRCS:=$(wildcard *.cc)
ELFS:=$(SRCS:%.cc=%)
OUT:=a.out
CC:=g++

all:
	$(CC) $(SRCS) -o $(OUT)
.PHONY:clean rebuild
clean:
	rm -rf $(OUT)
rebuild:clean all
