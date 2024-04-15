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
	char *filename=malloc(64);
	char *resultname=malloc(64);
	int isHelp = 0;
	parsearg(argc, argv, optstring, &filename, &resultname, isHelp); //getopt.h (getopt), assigns last two
	if(isHelp = 1){
		return EXIT_SUCCESS;
	}
	cell_t **labirynt;
	if(strstr(filename, ".bin")!=NULL)
		labirynt=compRead(filename, labirynt);
	else
		labirynt=StdRead(filename, labirynt);
	int height, width, pocz, kon;
	FILE *metadata=fopen("metadata.txt", "r");
	cell_t *temp = malloc(sizeof(cell_t));

	if(metadata==NULL){
		printf("brak pliku");	
		return EXIT_FAILURE;
	}
	else
	{
		fscanf(metadata, "%d %d %d %d", &height, &width, &pocz, &kon);
		fclose(metadata);
		temp=&labirynt[pocz/width][pocz%width];
	}
	int firstcount=0;
	while(temp!=NULL){
		firstcount++;
		temp=temp->next;
	} //ile resultname0_ .txt
	metadata=fopen("metadata.txt", "a");
	if(metadata==NULL){
		printf("nie udalo sie znalezc metadata.txt");	
		return EXIT_FAILURE;
	}
	else
	{
		fprintf(metadata, " %d", firstcount);
		fclose(metadata);
	}
    for(int i=0;i<height;i++){
        printf("\n");
        for(int j=0;j<width;j++){
            printf("\n");
            temp=&labirynt[i][j];
            while(temp!=NULL){
                printf("%d ", temp->numer);
                temp=temp->next;
            }
        }
    }
	divide(labirynt, resultname, height, width, pocz);
	    for(int i=0;i<height;i++){
        printf("\n");
        for(int j=0;j<width;j++){
            printf("\n");
            temp=&labirynt[i][j];
            while(temp!=NULL){
                printf("%d ", temp->numer);
                temp=temp->next;
            }
        }
    }
	return 0;
}