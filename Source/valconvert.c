#include "adjacencyMatrix.h"


int trueval(int posval){ //numer komorki
    int trueval=posval-1;
    trueval/=2;
    return trueval;
}

int posval(int trueval){ //wartosc pozycyjna dla calego pliku
    int posval=trueval*=2;
    posval+=1;
    return posval;
}

void append( cell_t **list, int val)
{
    cell_t *new=malloc(sizeof(cell_t));
    new->numer = val;
    cell_t *last = *list;
    new->next = NULL;
    if (*list == NULL) {
        *list = new;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new;
}