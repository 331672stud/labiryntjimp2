#include <stdio.h>
#include <stdlib.h>
#include "getoptt.h"
#include "PathFinder.h"
#include "FileList.h"
#include "writer.h"
#define optstring "f:w:h" //f-przedrostek plików w-plik wynikowy, h help

int main(int argc, char **argv){
	char *filename=malloc(16);
	char *resultname=malloc(16);
	int ishelp;
	ishelp=parsearg(argc, argv, optstring, &filename, &resultname, ishelp); //getopt.h (getopt), assigns last two
	if(ishelp==1)
		return EXIT_SUCCESS;
	FILE *metadata=fopen("metadata.txt", "r");
	int height, width;
	int pocz, kon; 
	int ilep0;
	fscanf(metadata, "%d %d %d %d %d", &height, &width, &pocz, &kon, &ilep0);
	fclose(metadata);
    convRead(pocz, kon, ilep0, filename, resultname);
	return EXIT_SUCCESS;
}