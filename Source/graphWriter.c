#include "adjacencyMatrix.h"
#include "errormsg.h"
#include <stdio.h>
#include <stdlib.h>


void partWrite(int nr_komorki, int nr_pliku, cell_t *branch, char *resultname){
    
    char *filename = malloc(64); 
    
    snprintf(filename, 64, "%s%d_%d.txt", resultname, nr_komorki, nr_pliku);

    FILE *plik = fopen(filename, "w");
    if (plik == NULL) {
        errorcomm(0);
        return;
    }
    
    while(branch!=NULL){
        fprintf(plik, "%d", branch->numer);
        branch = branch->next;
    }
}
