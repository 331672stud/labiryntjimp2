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
    int separator_id;
    int wall;
    int path;
    int separator;
    int value;
    int count;

    fread(file_id, (32 / 8), 1, plik);
    fread(escape, (8 / 8), 1, plik);
    fread(columns, (16 / 8), 1, plik);
    fread(entry_x, (16 / 8), 1, plik);
    fread(entry_y, (16 / 8), 1, plik);
    fread(exit_x, (16 / 8), 1, plik);
    fread(exit_y, (16 / 8), 1, plik);
    fread(reserved, (96 / 8), 1, plik);
    fread(counter, (32 / 8), 1, plik);
    fread(solution_offset, (32 / 8), 1, plik);
    fread(separator_id, (32 / 8), 1, plik);
    fread(wall, (8 / 8), 1, plik);
    fread(path, (8 / 8), 1, plik);
    fread(separator, (8 / 8), 1, plik);
    fread(value, (8 / 8), 1, plik);
    fread(count, (8 / 8), 1, plik);

    fclose(plik);

}
