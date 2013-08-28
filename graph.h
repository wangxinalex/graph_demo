#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES_NUM 100

#define MAX_FILE_NAME 20
#define MAX_LINE 100

typedef struct s_node{
	int value;
	char name[MAX_FILE_NAME];
}node;

typedef struct s_graph{
	int node_num;
	int edge_num;
	node node_list[MAX_NODES_NUM];
	int matrix[MAX_NODES_NUM][MAX_NODES_NUM];
}graph;

#endif
