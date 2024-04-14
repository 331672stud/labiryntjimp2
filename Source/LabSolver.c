#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "getopt.h"
#include "PathFinder.h"
#include "FileList.h"
#include "pathLocator.h"
#include "pathSolver.h"
#include "writer.h"
#include "adjacencyMatrix.h"
#define optstring ":f:w:h:" //f-przedrostek plików w-plik wynikowy, h help

int main(int argc, char **argv){
	char *filename=malloc(16);
	char *resultname=malloc(16);
	parsearg(argc, argv, optstring, filename, resultname); //getopt.h (getopt), assigns last two
	FILE *metadata=fopen("metadata.txt", "r");
	uint16_t height, width;
	int pocz, kon; 
	uint8_t ilep0;
	fscanf(metadata, "%d %d %d %d %d", height, width, pocz, kon, ilep0);
	fclose(metadata);
    convRead(ilep0, width, height, filename, pocz, kon);
    writePath(resultname);
	return 0;
}