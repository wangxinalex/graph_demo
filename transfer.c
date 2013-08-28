#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

int parse(char[],int[]);
int decode(int[][MAX_NODES_NUM],int[],int);
void print_matrix(int[][MAX_NODES_NUM],int );

//int matrix[MAX_NODES_NUM][MAX_NODES_NUM];

int parse(char* line, int vertex[]){
	int num = 0;
	char *dup  = (char*)calloc(MAX_LINE,sizeof(char));
	strcpy(dup,line);

	char *token;
	
	while((token = strsep(&dup, " "))!=NULL){
		vertex[num++] = atoi(token);
	}
	//the vertex number is one more than the array length for the
	//last ont line is definitely zero(no complex edge)
	return num + 1;
}	

int decode(int matrix[][MAX_NODES_NUM], int vertex_num[], int num){
	int i,j ;
	for(i = 0; i < num; i++){
		for(j = num-1; j > i; j--){
			matrix[i][j] = vertex_num[i]&0x1;
			vertex_num[i] >>= 1;
		}
	}
	for(i =0 ; i< num; i++){
		matrix[i][i] = 0;
		for(j = 0; j<i; j++){
			matrix[i][j] = matrix[j][i];			
		}
	}
	return 0;
	
}

void print_matrix(int adj_matrix[][MAX_NODES_NUM],int num){
	int i,j;
	for(i = 0; i < num; i++){
		for(j = 0; j < num; j++){
			printf("%d ", adj_matrix[i][j]);
		}	
		printf("\n");
	}
}
