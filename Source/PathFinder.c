#include "adjacencyMatrix.h"
#include <stdint.h>
#include "FileList.h"
#include "ConvertedReader.h"

list_t recursiveread(){
    
    fileread();
    recursiveread();
}

void convRead(uint16_t height, uint16_t width, int pocz, int kon, uint8_t ilep0, char *filename){
    char *resultname = malloc(64);
    if(ilep0==0){
        snprintf(resultname, 64, "%s%d_%d.txt", filename, pocz, ilep0);
    }
    else
        for(int i=0;i<ilep0;i++){
                    snprintf(resultname, 64, "%s%d_%d.txt", filename, pocz, i);
        }

    /*
    Chcemy znaleźć wszystkie ścieżki od pocz do kon
    nie wiemy ile ich jest wiec zatrzymujemy sie gdy sprawdzimy wszystkie mozliwe sciezki metoda dfs
    tworzymy liste plikow dla kazdej sciezki
    if ends in kon
    fprintf sciezkan
    else
    free
    i w kolko
    */
}


/*void removecopies(cell_t **labirynt, int width, int height, int start){
    int startheight=start/width;
    int startwidth=start%width;
    cell_t currentcell=labirynt[startheight][startwidth];
    cell_t *connections=currentcell.next;
    while(connections!=NULL){
        usuwaniewagonika(labirynt, connections->numer/width, connections->numer%width, start);
        removecopies(labirynt, width, height, connections->numer);
        connections=connections->next;
    }
}

void conv2graph(cell_t **labirynt, int width, int height, int start){
    removecopies(labirynt, width, height, start);
}*/