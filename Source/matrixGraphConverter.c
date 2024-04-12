#include "adjacencyMatrix.h"
#include "valconvert.h"
#include <stdio.h>


void usuwaniewagonika(cell_t *wagoniki, int numerwagonika){

}

void zalewanielabiryntu(cell_t **labirynt, int width, int height, int start){
    int startheight=start/width;
    int startwidth=start%width;
    cell_t currentcell=labirynt[startheight][startwidth];
    cell_t *connections=currentcell.next;
    while(connections!=NULL){
        usuwaniewagonika(labirynt[][].next, connections->numer);
        zalewanielabiryntu(labirynt, width, height, connections->numer);
        connections=connections->next;
    }
}

void conv2graph(cell_t **labirynt, int width, int height, int start, int koniec){
    removecopies(labirynt, width, height, start);
}

