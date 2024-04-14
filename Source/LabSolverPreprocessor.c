#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getoptt.h"
#include "compressedReader.h"
#include "textReader.h"
#include "graphDivider.h"
#include "adjacencyMatrix.h"
#define optstring "t:n:h" //t-plik n-jakie maja miec nazwe wynikowe

int main(int argc, char **argv){
	char *filename=malloc(16);
	char *resultname=malloc(16);
	parsearg(argc, argv, optstring, &filename, &resultname); //getopt.h (getopt), assigns last two
	cell_t **labirynt;
	if(strstr(filename, ".bin")!=NULL)
		compRead(filename, labirynt);
	else
		StdRead(filename, labirynt);
	int height, width, pocz, kon;
	FILE *metadata=fopen("metadata.txt", "r");
	if(metadata==NULL){
		printf("sraniewbanie");	
		return EXIT_FAILURE;
	}
	else
	{
		fscanf(metadata, "%d %d %d %d", &height, &width, &pocz, &kon);
		fclose(metadata);
	}
	int firstcount=0;
	cell_t *temp=labirynt[pocz/width][pocz%width].next;
	while(temp!=NULL){
		firstcount++;
		temp=temp->next;
	} //ile resultname0_ .txt
	metadata=fopen("metadata.txt", "a");
	if(metadata==NULL){
		printf("sraniewbanie");	
		return EXIT_FAILURE;
	}
	else
	{
		fscanf(metadata, " %d", &firstcount);
		fclose(metadata);
	}
	divide(labirynt, resultname, height, width, pocz);
	return 0;
}