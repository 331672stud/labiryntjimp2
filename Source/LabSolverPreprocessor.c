#include <stdio.h>
#include <stdlib.h>
#include "getopt.h"
#include "compressedReader.h"
#include "textReader.h"
#include "graphDivider.h"
#include "adjacencyMatrix.h"
#define optstring ":t:n:h:" //t-plik n-jakie maja miec nazwe wynikowe

int main(int argc, char **argv){
	char *filename=malloc(16);
	char *resultname=malloc(16);
	parsearg(argc, argv, optstring, filename, resultname); //getopt.h (getopt), assigns last two
	graph_t *graf;
	cell_t **labirynt
	if(/*filename .bin*/)
		compRead(filename, graf, labirynt);
	else
		StdRead(filename, graf, labirynt);
	divide(graf, resultname);
	return 0;
}