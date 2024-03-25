#include <stdio>
#include <stdlib>
#include "getopt.h"
#DEFINE const char *optstring="fw" //f-przedrostek plików w-plik wynikowy

int main(int argc, char **argv){
	char *filename=malloc(16);
	char *resultname=malloc(16);
	parsearg(argc, argv, optstring, filename, resultname); //getopt.h (getopt), assigns last two
	
	return 0;
}