#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

typedef struct lista{
    int nrkom;
    int nrpliku;
    struct lista *next;
    
}list_t;

void Listappend( list_t **list, int nrkom, int nrpliku);

void deappend( list_t **list);

#endif