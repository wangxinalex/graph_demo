CC = gcc
all: graph.c transfer.c queue.c
	$(CC) -o graph graph.c transfer.c queue.c
.PHONY:clean
clean: 
	rm graph 
