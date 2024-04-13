#ifndef DIVIDE_H
#define DIVIDE_H
#include "adjacencyMatrix.h"

cell_t push();

void findbranch(cell_t **labirynt, int width, int height, int start, char *resultname);

void divide(cell_t **labirynt, char *resultname, int height, int width, int pocz);

#endif