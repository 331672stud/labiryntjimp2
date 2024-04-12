#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.h"
#include "valconvert.h"


// void compRead(char *filename, graph_t *graf, cell_t **labirynt){

void test(){
    FILE *plik = fopen("maze.bin", "rb");
    
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

    printf("File Id: %c%c%c%c\n", file_id[0], file_id[1], file_id[2], file_id[3]);
    printf("Escape: %02X\n", escape);
    printf("Columns: %d\n", columns);
    printf("Lines: %d\n", lines);
    printf("Entry X: %d\n", entry_x);
    printf("Entry Y: %d\n", entry_y);
    printf("Exit X: %d\n", exit_x);
    printf("Exit Y: %d\n", exit_y);
    printf("Reserved: ");
    for (int i = 0; i < sizeof(reserved); i++) {
        printf("%02X ", reserved[i]);
    }
    printf("\n");
    printf("Counter: %d\n", counter);
    printf("Solution Offset: %d\n", solution_offset);
    printf("Separator Id: %02X\n", separator_id);
    printf("Wall: %02X\n", wall);
    printf("Path: %02X\n", path);
    printf("Separator: %02X\n", separator);
    printf("Value: %02X\n", value);
    printf("Count: %02X\n", count);
}

int main(int argc, char **argv){
    test();
    return 0;
}
