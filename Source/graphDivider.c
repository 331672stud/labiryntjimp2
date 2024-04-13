#include "adjacencyMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include "graphWriter.h"

void append( cell_t **branch, int val)
{
    cell_t *new=malloc(sizeof(cell_t));
    new->numer = val;
    cell_t *last = *branch;
    new->next = NULL;
    if (*branch == NULL) {
        *branch = new;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new;
}

void findbranch(cell_t **labirynt, int width, int height, int start, char *resultname){
    int startheight=start/width;
    int startwidth=start%width;
    cell_t *branch=malloc(sizeof(cell_t));
    branch->numer=labirynt[startheight][startwidth].numer;
    branch->next=labirynt[startheight][startwidth].next;
    cell_t *branchstarts=branch->next;
    int numerkomorki;
    int numerpliku=0;
    branch->next=NULL;
    while(branchstarts!=NULL){
        numerkomorki=branchstarts->numer;
        while(labirynt[numerkomorki/width][numerkomorki%width].next!=NULL){
            if(labirynt[numerkomorki/width][numerkomorki%width].next->next==NULL){
                append(&branch, numerkomorki);
                numerkomorki=labirynt[numerkomorki/width][numerkomorki%width].next->numer;
                }
                else{
                    append(&branch, numerkomorki);
                    break;
                }
        }
        if(labirynt[numerkomorki/width][numerkomorki%width].next==NULL){
            append(&branch, numerkomorki);
            PartWrite(branch->numer, numerpliku, branch, resultname, 0);  
        }
        else{
            int ileplikow=0;
            cell_t *temp=labirynt[numerkomorki/width][numerkomorki%width].next;
            while(temp!=NULL){
                ileplikow++;
                temp=temp->next;
            }
            PartWrite(branch->numer, numerpliku, branch, resultname, ileplikow); 
        } 
        numerpliku++;
        findbranch(labirynt, width, height, labirynt[numerkomorki/width][numerkomorki%width].numer, resultname);
        branchstarts=branchstarts->next;
    }
}

void divide(cell_t **labirynt, char  *resultname, int height, int width, int pocz){
    findbranch(labirynt, width, height, pocz, resultname);
}
