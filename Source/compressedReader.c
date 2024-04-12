#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.h"
#include "valconvert.h"
#include "Errormsg.h"


void compRead(char *filename, graph_t *graf, cell_t **labirynt){

    FILE *plik = fopen(filename, "rb");
    if(plik==NULL){
        errorcomm(0);
        return EXIT_FAILURE;
    }
    
    unsigned char file_id[4];
    unsigned char escape;
    unsigned short columns, lines, entry_x, entry_y, exit_x, exit_y;
    unsigned char reserved[12];
    unsigned int counter, solution_offset;
    unsigned char separator_id, wall, path, separator, value, count;


    fread(file_id, sizeof(file_id), 1, plik);
    fread(&escape, sizeof(escape), 1, plik);
    fread(&columns, sizeof(columns), 1, plik);
    fread(&lines, sizeof(lines), 1, plik);
    fread(&entry_x, sizeof(entry_x), 1, plik);
    fread(&entry_y, sizeof(entry_y), 1, plik);
    fread(&exit_x, sizeof(exit_x), 1, plik);
    fread(&exit_y, sizeof(exit_y), 1, plik);
    fread(reserved, sizeof(reserved), 1, plik);
    fread(&counter, sizeof(counter), 1, plik);
    fread(&solution_offset, sizeof(solution_offset), 1, plik);
    fread(&separator_id, sizeof(separator_id), 1, plik);
    fread(&wall, sizeof(wall), 1, plik);
    fread(&path, sizeof(path), 1, plik);
    fread(&separator, sizeof(separator), 1, plik);
    fread(&value, sizeof(value), 1, plik);
    fread(&count, sizeof(count), 1, plik);


    fclose(plik);

    int width = trueval(columns);
    int height = trueval(lines);
    labirynt = malloc(height * sizeof(cell_t*));
    for(int i = 0; i < height; i++){
        labirynt[i] = malloc(width * sizeof(cell_t));
    }
    for(int i  =0; i < height; i++){
        for(int j = 0; j < width; j++){
            labirynt[i][j].numer = i * width + j;
            labirynt[i][j].next = NULL;
        }
    }
    

}

