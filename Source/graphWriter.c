#include "adjacencyMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include "Errormsg.h"


void PartWrite(int nr_komorki, int nr_pliku, cell_t *branch, char *resultname, int ileplikow){
    
    char *filename = malloc(64); 
    
    snprintf(filename, 64, "%s%d_%d.txt", resultname, nr_komorki, nr_pliku);

    FILE *plik = fopen(filename, "w");
    if (plik == NULL) {
        errorcomm(0);
        return;
    }
    
    while(branch!=NULL){
        fprintf(plik, "n %d ", branch->numer);
        branch = branch->next;
    }
    fprintf(plik, "_ %d", ileplikow);
    fclose(plik);
}