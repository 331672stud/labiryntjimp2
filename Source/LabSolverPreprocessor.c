#include <stdio>
#include <stdlib>
#include "getopt.h"
#include "compressedReader.h"
#include "textReader.h"
#include "graphDivider.h"
#DEFINE const char *optstring="tn" //t-plik n-jakie maja miec nazwe wynikowe

int main(int argc, **char argv){
	*char filename=malloc(16);
	*char resultname=malloc(16);
	parsearg(argc, argv, optstring, filename, resultname); //getopt.h (getopt), assigns last two
	if(/*filename .bin*/)
		compRead(plik, filename);
	else
		StdRead(plik, filename);
	return 0;
}