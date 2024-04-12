#ifndef CONVERT_H
#define CONVERT_H
#include "adjacencyMatrix.h"

void usuwaniewagonika(cell_t *wagoniki, int numerwagonika);

void zalewanielabiryntu(cell_t **labirynt, int width, int height, int start);

void conv2graph(cell_t **labirynt, graph_t *graf, int width, int height, int start, int koniec);

#endif