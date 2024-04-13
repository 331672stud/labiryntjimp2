#ifndef ADJMATRIX_H
#define ADJMATRIX_H

typedef struct cell{
    int numer; //numer komorki polaczonej
    struct cell *next; //kolejna komorka w ciagu
    int visited; //czy komorka zostala odwiedzona (0 lub 1)
} cell_t;

#endif