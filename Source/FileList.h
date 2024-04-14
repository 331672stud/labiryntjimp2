#include <stdint.h>
#include <stdlib.h>

typedef struct lista{
    int nrkom;
    uint8_t nrpliku;
    list_t *next;
    
}list_t;

void Listappend( list_t **list, int nrkom, uint8_t nrpliku);
