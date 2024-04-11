#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.h"
#include "valconvert.h"


void compRead(char *filename, graph_t *graf){
    
    FILE *plik = fopen(filename, "r");
     if (plik == NULL) {
        printf("Blad wczytywania pliku.\n");
        return 1;
    }

    char *bufor = malloc(2048 * sizeof(char) + sizeof(NULL));
    int width = 0;
    int height = 0;

    while(fgets(bufor, 2050, plik) != NULL){

    }


}
