#ifndef CONVERT_H
#define CONVERT_H
#include "adjacencyMatrix.h"


void usuwaniewagonika(cell_t **labirynt, int komorkah, int komorkaw, int numerwagonika);

void removecopies(cell_t **labirynt, int width, int height, int start);

void conv2graph(cell_t **labirynt, int width, int height, int start);

#endif
