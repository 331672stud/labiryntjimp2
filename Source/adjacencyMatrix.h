#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include "adjacencyMatrix.h"

void compRead(char *filename, graph_t *graf);



typedef struct cell{
    int numer; //numer komorki polaczonej
    struct komorka next; //kolejna komorka w ciagu
} cell_t; 

typedef struct graph{
    int dirs; //w pierwszej komorce numer, dla kazdej kolejnej direction od niej: 0,1,2,3,4(wskazowki zegara od prawej)
    int countbranch; //ile galezi z tego punktu grafu, do iterowania po next 
    struct graph *next;
} graph_t

#endif