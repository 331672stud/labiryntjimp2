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
    
    unsigned char file_id[(32 / 8)];
    unsigned char escape[(8 / 8)];
    unsigned char columns[(16 / 8)];
    unsigned char entry_x[(16 / 8)];
    unsigned char entry_y[(16 / 8)];
    unsigned char exit_x[(16 / 8)];
    unsigned char exit_y[(16 / 8)];
    unsigned char reserved[(96 / 8)];
    unsigned char counter[(32 / 8)];
    unsigned char solution_offset[(32 / 8)];
    unsigned char separator_id[(8 / 8)];
    unsigned char wall[(8 / 8)];
    unsigned char path[(8 / 8)];
    unsigned char separator[(8 / 8)];
    unsigned char value[(8 / 8)];
    unsigned char count[(8 / 8)];


    fread(file_id, sizeof(file_id), 1, plik);
    fread(escape, sizeof(escape), 1, plik);
    fread(columns, sizeof(columns), 1, plik);
    fread(entry_x, sizeof(entry_x), 1, plik);
    fread(entry_y, sizeof(entry_y), 1, plik);
    fread(exit_x, sizeof(exit_x), 1, plik);
    fread(exit_y, sizeof(exit_y), 1, plik);
    fread(reserved, sizeof(reserved), 1, plik);
    fread(counter, sizeof(counter), 1, plik);
    fread(solution_offset, sizeof(solution_offset), 1, plik);
    fread(separator_id, sizeof(separator_id), 1, plik);
    fread(wall, sizeof(wall), 1, plik);
    fread(path, sizeof(path), 1, plik);
    fread(separator, sizeof(separator), 1, plik);
    fread(value, sizeof(value), 1, plik);
    fread(count, sizeof(count), 1, plik);

    fclose(plik);

}
