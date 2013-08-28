#include <stdio.h>
#include <stdlib.h>

#define UPPER 2048

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Usage: %s [lines] [max vertex number]\n", argv[0]);
		exit(-1);
	}	
	int line_num = atoi(argv[1]);
	int max_vertex = atoi(argv[2]);
	FILE* out;
	if((out = fopen("graphfile", "w")) == NULL){
		fprintf(stderr, "Error: cannot open the file\n");
		exit(1);
	}
	int line , vertex;
	for(line = 0; line < line_num; line++){
		for(vertex = 0; vertex < max_vertex; vertex++){
			fprintf(out, "%i ", rand()%UPPER+1);
		}
		fprintf(out,"\n");
	}
	if(fclose(out) != 0){
		fprintf(stderr, "Error: cannot close the file\n");
		exit(1);
	}
	return 0;
	
	
}
