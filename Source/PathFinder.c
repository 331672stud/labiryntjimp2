#include "adjacencyMatrix.h"
#include "FileList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int countnext(char *filename){ //zwraca liczbe plikow wychodzacych z branch
    int count;
    FILE *plik=fopen(filename, "r");
    int komorka;
    char flag;
    fscanf(plik, "%c", &flag);
    while(flag!='_')
        fscanf(plik, "%d %c", &komorka, &flag);
    fscanf(plik, "%d", &count);
    fclose(plik);
    return count;
}

int lastcell(char *filename){ //zwraca ostatnia komorke w pliku
    FILE *plik=fopen(filename, "r");
    int komorka;
    char flag;
    fscanf(plik, "%c", &flag);
    while(flag!='_')
        fscanf(plik, "%d %c", &komorka, &flag);
    fclose(plik);
    return komorka;
}

list_t *getlast( list_t **list)
{
    list_t *last = *list;
    if (*list == NULL) {
        return NULL;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
}

bool isEnd(list_t *lista, int kon, char *filename){ //sprawdza czy w ostatnim pliku na list znajduje sie koniec(bo i tak sprawdzamy co append wiec musi byc na koncu)
    char *resultname = malloc(64);
    list_t *lastelem=getlast(&lista);      
    snprintf(resultname, 64, "%s%d_%d.txt", filename, lastelem->nrkom, lastelem->nrpliku);
    FILE *plik=fopen(resultname, "r");
    char flag;
    int nrkom;
    fscanf(plik, "%c %d", &flag, &nrkom);
    while(flag!='_'){
        if(nrkom==kon){
            fclose(plik);
            return true;
        }
        fscanf(plik, "%c %d", &flag, &nrkom);
    }
    fclose(plik);
    return false;
}

void recursiveRead(int pocz, int kon, int ilep0, char *filename, list_t *lista, char *zapis){
    char *resultname = malloc(64);
    int branchcount;
    bool czydoprintu;
    if(ilep0==0){
        Listappend(&lista, pocz, ilep0);
        snprintf(resultname, 64, "%s%d_%d.txt", filename, pocz, ilep0);
        branchcount=countnext(resultname);
        if(branchcount!=0){
            recursiveRead(lastcell(resultname), kon, branchcount, filename, lista, zapis);
        }
        else{
            czydoprintu=isEnd(lista, kon, filename);
            if(czydoprintu)
                writePath(lista, kon, resultname, zapis);
        }
    } else for(int i=0;i<ilep0;i++){
        Listappend(&lista, pocz, i);
        snprintf(resultname, 64, "%s%d_%d.txt", filename, pocz, i);
        branchcount=countnext(resultname);
        if(branchcount!=0){
            recursiveRead(lastcell(resultname), kon, branchcount, filename, lista, zapis);
        }
        else{
            czydoprintu=isEnd(lista, kon, filename);
            if(czydoprintu)
                writePath(lista, kon, resultname ,zapis);
        }
        deappend(&lista);
    }
}

void convRead(int pocz, int kon, int ilep0, char *filename, char *zapis){
    list_t *lista=malloc(sizeof(list_t));
    recursiveRead(pocz, kon, ilep0, filename, lista, zapis);
    
}