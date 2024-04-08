#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include "adjacencyMatrix.h"

void compRead(char *filename, graph_t *graf);



typedef struct cell{
    int numer; //numer komorki polaczonej
    struct komorka next; //kolejna komorka w ciagu
} cell_t; 

typedef struct graph{
    int numer;
    struct graph *next;
} graph_t

#endif