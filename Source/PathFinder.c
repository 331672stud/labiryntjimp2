#include "adjacencyMatrix.h"
#include "FileList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "writer.h"

int countnext(char *resultname){ //zwraca liczbe plikow wychodzacych z branch
    FILE *plik=fopen(resultname, "r");
    if(plik==NULL)
        return 0;
    int komorka;
    char flag;
    while(flag!='_')
        fscanf(plik, "%c %d", &flag, &komorka);
    fclose(plik);
    return komorka;
}

int lastcell(char *resultname){ //zwraca ostatnia komorke w pliku
    FILE *plik=fopen(resultname, "r");
    if(plik==NULL)
        return 0;
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

void recursiveRead(int pocz, int kon, int curnum, char *filename, list_t *lista, char *zapis){
    char *resultname = malloc(64);
    int branchcount;
    bool czydoprintu;
    snprintf(resultname, 64, "%s%d_%d.txt", filename, pocz, curnum);
    branchcount=countnext(resultname);
    if(branchcount!=0){
        for(int i=0;i<=branchcount;i++)
        {
            Listappend(&lista, pocz, curnum);
            recursiveRead(lastcell(resultname), kon, i, filename, lista, zapis);
        }
    }
    else
    {
        czydoprintu=isEnd(lista, kon, filename);
        if(czydoprintu){
            Listappend(&lista, pocz, curnum);
            writePath(lista, kon, filename, zapis);
            }
    }
}

void convRead(int pocz, int kon, int ilep0, char *filename, char *zapis){
    list_t *lista=malloc(sizeof(list_t));
    for(int i=0;i<=ilep0;i++)
    {
        lista=NULL;
        recursiveRead(pocz, kon, i, filename, lista, zapis);
    } 
}