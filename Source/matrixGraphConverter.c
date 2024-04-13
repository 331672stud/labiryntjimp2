#include "adjacencyMatrix.h"
#include "valconvert.h"
#include <stdio.h>

void usuwaniewagonika(cell_t **labirynt, int komorkah, int komorkaw, int numerwagonika){
    cell_t *curwagon=labirynt[komorkah][komorkaw].next;
    cell_t *replacewagon=NULL;
    cell_t *tempwagon=NULL;
    while (curwagon!=NULL)
    {
        if(curwagon->numer!=numerwagonika){
            tempwagon=curwagon;
            tempwagon->next=replacewagon;
            replacewagon=tempwagon;
        }
    }
    labirynt[komorkah][komorkaw].next=replacewagon;
}

void removecopies(cell_t **labirynt, int width, int height, int start){
    int startheight=start/width;
    int startwidth=start%width;
    cell_t currentcell=labirynt[startheight][startwidth];
    cell_t *connections=currentcell.next;
    while(connections!=NULL){
        usuwaniewagonika(labirynt, connections->numer/width, connections->numer%width, start);
        removecopies(labirynt, width, height, connections->numer);
        connections=connections->next;
    }
}

void conv2graph(cell_t **labirynt, int width, int height, int start){
    removecopies(labirynt, width, height, start);
}

