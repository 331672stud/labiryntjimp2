#include "valconvert.h"

void zalewanielabiryntu(cell_t **labirynt, graph_t *graf, int komorka){
    //zaczynajac od startu, zgodnie z komorkami cell_t budowac graph_t
        //graf skierowany, wiec po dodaniu przejscia z jednej komorki usuwany adres tej na ktorej jestesmy z tej drugiej
        //jesli wiecej niz jedna alokacja pamieci na wskaznik next
        //rekurencyjnie poruszac sie po cell_t zgodnie z komorkami ktore dodajemy do graph_t
}

void conv2graph(cell_t **labirynt, graph_t *graf, int width, int height){
    //trzeba dodac zaczynanie od startu nie od 0
    int komorka; //adres startu
    zalewanielabiryntu(labirynt, graf, komorka);
}

