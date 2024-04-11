#ifndef CONVERT_H
#define CONVERT_H
#include "adjacencyMatrix.h"

void zalewanielabiryntu(cell_t **labirynt, graph_t *graf, int komorka, int width, int height);

void conv2graph(cell_t **labirynt, graph_t *graf, int width, int height);

#endif