#ifndef ADJMATRIX_H
#define ADJMATRIX_H

typedef struct cell{
    int numer; //numer komorki polaczonej
    struct cell *next; //kolejna komorka w ciagu
} cell_t;

#endif