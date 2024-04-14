#include "FileList.h"
#include <stdint.h>
void Listappend( list_t **list, int nrkom, uint8_t nrpliku)
{
    list_t *new=malloc(sizeof(list_t));
    new->nrkom = nrkom;
    new->nrpliku=nrpliku;
    list_t *last = *list;
    new->next = NULL;
    if (*list == NULL) {
        *list = new;
        return;
    }
    else{
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new;}
}

void deappend( list_t **list)
{
    list_t *last = *list;
    if (*list == NULL) {
        return;
    }
    else{
    while (last->next != NULL) {
        last = last->next;
    }
    last=NULL;}
}
