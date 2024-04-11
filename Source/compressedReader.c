#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.h"
#include "valconvert.h"


void compRead(char *filename, graph_t *graf, cell_t **labirynt){
    
    FILE *plik = fopen(filename, "rb");
     if (plik == NULL) {
        printf("Blad wczytywania pliku.\n");
        return 1;
    }
    
    int file_id;
    int escape;
    int columns;
    int entry_x;
    int entry_y;
    int exit_x;
    int exit_y;
    int reserved;
    int counter;
    int solution_offset;
    int separator;
    int wall;
    int path;

}
