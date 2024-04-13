#include "adjacencyMatrix.h"
#include <stdio.h>
#include <stdlib.h>

void append( cell_t branch){


}

void findbranch(cell_t **labirynt, int width, int height, int start){
    int startheight=start/width;
    int startwidth=start%width;
    cell_t branch=labirynt[startheight][startwidth];
    cell_t *branchstarts=branch.next;
    branch.next=NULL;
    cell_t *tempbranch;
    cell_t *currentcell;
    cell_t *nextbranch;
    while(branchstarts!=NULL){
        currentcell=branchstarts;
        currentcell->next=NULL;
        nextbranch=currentcell;
        while(labirynt[currentcell->numer/width][currentcell->numer%width].next->next==NULL){
            tempbranch=labirynt[currentcell->numer/width][currentcell->numer%width].next;
            currentcell->next=tempbranch;
        }
            /*dopisz labirynt.next na koniec listy*/
        branchstarts=branchstarts->next;
    }
}

void divide(cell_t **labirynt, char  *resultname, int height, int width, int pocz){
    findbranch(labirynt, width, height, pocz);
}
