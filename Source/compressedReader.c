#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.h"
#include "valconvert.h"
#include "Errormsg.h"
#include "matrixGraphConverter.h"


cell_t **compRead(char *filename, cell_t **labirynt){
    
    FILE *plik = fopen(filename, "rb");
    if(plik==NULL){
        errorcomm(0);
        return NULL;
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

    int height = trueval(lines);
    labirynt = malloc(height * sizeof(cell_t*));
    if (labirynt == NULL) {
        errorcomm(3);
        return NULL;
    }
    int width = trueval(columns);
    for(int i = 0; i < height; i++){
        labirynt[i] = malloc(width * sizeof(cell_t));
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            labirynt[i][j].numer = i * width + j;
            labirynt[i][j].next = NULL;
        }
    }
    int nrstart = (trueval(entry_y - 1) * trueval(columns) + trueval(entry_x));
    int nrkoniec = (trueval(exit_y - 1) * trueval(columns) + trueval(exit_x)) - 1;
    printf("stx: %d sty: %d kox: %d koy: %d ", entry_x, entry_y, exit_x, exit_y);

    int current_height = 0;
    int current_width = 0;
    while(current_height != lines && current_width != columns){
        fread(&separator, sizeof(separator_id), 1, plik);
        fread(&value, sizeof(wall), 1, plik);
        fread(&count, sizeof(path), 1, plik);
        for(int i=0;i <= count;i++){
            if(current_height%2==0)
            {
                if(current_width%2==0 ) //always a wall
                {
                    if(value!=wall)
                    {
                        errorcomm(2);
                        return NULL;
                    }
                }else if(value==path && current_height!=0 &&current_height!=lines-1 ){
                    append(&labirynt[trueval(current_height-1)][trueval(current_width)].next, trueval(current_height+1)*width+trueval(current_width));
                    append(&labirynt[trueval(current_height+1)][trueval(current_width)].next, trueval(current_height-1)*width+trueval(current_width)); 
                } //up down pass
            }else if(current_width%2==0){
                if(value==path && current_width!=0 &&current_width!=columns-1){
                    append(&labirynt[trueval(current_height)][trueval(current_width+1)].next, trueval(current_height)*width+trueval(current_width-1));
                    append(&labirynt[trueval(current_height)][trueval(current_width-1)].next, trueval(current_height)*width+trueval(current_width+1));
                }
            } //left right pass
            else if(value!=path){
                errorcomm(2);
                return NULL;
            }//zawsze komorka
            current_width++;
            if(current_width==columns){
                current_height++;
                current_width=0;
            }    
        }
    }
    conv2graph(labirynt, width, height, nrstart);
    FILE *metadata=fopen("metadata.txt", "w");
    fprintf(metadata, "%d %d %d %d", height, width, nrstart, nrkoniec);
    fclose(metadata);
    return labirynt;
}
