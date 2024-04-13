#include "adjacencyMatrix.h"
#include <stdio.h>
#include <stdlib.h>


void PartWrite(int n, cell_t *branch, char *resultname){
    char *fileend=malloc(7);
    fileend[0]="_";
    fileend[1]=n+"0";
    char *txttype=".txt";
    strcat(fileend, txttype);
    char fullresultname=malloc(32);
    fullresultname=resultname;
    strcat(fullresultname, fileend);
    FILE *zapis=fopen(fullresultname, "w");
    while(branch!=NULL){
        fprintf(zapis,"placeholder" , txttype);
    }
}