#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

extern int parse(char[],int[]);
extern int decode(int[][MAX_NODES_NUM],int[],int);
extern void print_matrix(int[][MAX_NODES_NUM],int );
extern int enqueue(void *item);
extern void * dequeue();
extern int initializeQueue();
extern int isEmpty();
extern int isFull();

graph* create_graph(int adj_matrix[MAX_NODES_NUM][MAX_NODES_NUM],int vertex_num);
void print_graph(graph *);
void DFSTraversal(graph *p);
void DFS(graph *p, int v);
void BFSTraversal(graph *p);
void BFS(graph *p, int v);


extern void * queue[MAX];
extern int front, rear;

graph *G;
int visited[MAX_NODES_NUM];

int main(int argc, char *argv[]){
	char filename[MAX_FILE_NAME];
	int vertex_num;
	int origin_num;
	char line[MAX_LINE];
	
	FILE *in;
	if(argc != 2){
		printf("Usage: ./%s [filename]\n", argv[0]);
		exit(1);
	}
	strcpy(filename, argv[1]);
	if((in = fopen(filename, "r")) == NULL){
		fprintf(stderr, "failed to open the file\n");
	}
	while(fgets(line, MAX_LINE, in)!=NULL){
		int vertex[MAX_NODES_NUM];
		int matrix[MAX_NODES_NUM][MAX_NODES_NUM];
		int num = parse(line,vertex);
		decode(matrix, vertex, num);
		//print_matrix(matrix, num);
		graph *graph_ptr = create_graph(matrix,num);
		//print_graph(graph_ptr);
		DFSTraversal(graph_ptr);
		BFSTraversal(graph_ptr);
	}
	if(fclose(in)!=0){
		fprintf(stderr, "failed to close the file\n");
	}

}

graph* create_graph(int adj_matrix[MAX_NODES_NUM][MAX_NODES_NUM],int vertex_num){
	int i,j;
	G =(graph*)calloc(1, sizeof(graph));
	G->node_num = vertex_num;
	G->edge_num = 0;
	node nodelist[MAX_NODES_NUM];
	for(i = 0; i < vertex_num; i++){
		nodelist[i].value = i;
	}
	memcpy(G->matrix ,adj_matrix, MAX_NODES_NUM * MAX_NODES_NUM * sizeof(int));
	for(i = 0; i < MAX_NODES_NUM; i++){
		for(j = i; j < MAX_NODES_NUM; j++){
			if(adj_matrix[i][j] == 1){
				G->edge_num++;
			}
		}
	}
	return G;	
}

void print_graph(graph *p){
	printf("Grpah: vertex number = %d\t edge number = %d\n",p->node_num,p->edge_num);
	print_matrix(p->matrix,p->node_num);
	
}

void DFSTraversal(graph *p){
	
	int node_num = p->node_num;
	int i;
	for(i = 0; i < node_num; i++){
		visited[i] = 0;
	}
	for(i = 0; i < node_num; i++){
		if(visited[i]==0){
			DFS(p, i);
		}
	}
	printf("\n");
}

void DFS(graph *p, int v){
	int node_num = p->node_num;
	int i;
	visited[v] = 1;
	printf("%d ",v);
	for(i = 0; i < node_num;i++){
		if(visited[i] == 0 && p->matrix[v][i] == 1){
			DFS(p, i);
		}
	}
}

void BFSTraversal(graph *p){
	int node_num = p->node_num;
	int i;
	for(i = 0; i < node_num; i++){
		visited[i] = 0;
	}
	for(i = 0; i < node_num; i++){
		if(visited[i]==0){
			BFS(p, i);
		}
	}
	printf("\n");
}

void BFS(graph *p, int v){
	int node_num = p->node_num;
	int i, v1;
	initializeQueue();
	enqueue(&v);
	
	visited[v] = 1;
	printf("%d ",v);

	while(!isEmpty()){
		v1 = *(int *)dequeue();
		for(i = 0; i < node_num; i++){
			if(p->matrix[v][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				enqueue(&i);
				printf("%d ",i);
			}
		}
	}
}
