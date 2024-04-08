#include <stdio.h>
#include <stdlib.h>
#include "getopt.h"
#include "convertedReader.h"
#include "connectionLister.h"
#include "pathLocator.h"
#include "pathSolver.h"
#include "writer.h"
#include "adjacencyMatrix.h"
#define optstring "fw" //f-przedrostek plików w-plik wynikowy

int main(int argc, char **argv){
	char *filename=malloc(16);
	char *resultname=malloc(16);
	parsearg(argc, argv, optstring, filename, resultname); //getopt.h (getopt), assigns last two
	FILE *metadane=fopen("metadata.txt","r");
    int ileplikow, szer, wys;
    convRead(ileplikow, szer, wys, filename);
    writePath(resultname);
	return 0;
}