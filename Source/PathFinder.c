#include "adjacencyMatrix.h"
#include <stdint.h>
#include "FileList.h"
#include "ConvertedReader.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t countnext(resultname){
    uint8_t count=0;
    FILE *plik=fopen(resultname, "r");
    char *bufor=malloc(32);
    char *numb=malloc(2);
    while(fgets(bufor, 32, plik)!=NULL)
        if(strstr(bufor, "_")!=NULL)
            numb=strstr(bufor,"_");
    count=numb[1]-'0';
    return count;
}

int lastcell(char *filename){
    int cellnumber;
    return cellnumber;
}

void recursiveRead(uint16_t height, uint16_t width, int pocz, int kon, uint8_t ilep0, char *filename, list_t *lista){
    char *resultname = malloc(64);
    uint8_t branchcount;
    bool czydoprintu;
    if(ilep0==0){
        Listappend(&lista, pocz, ilep0);
        snprintf(resultname, 64, "%s%d_%d.txt", filename, pocz, ilep0);
        branchcount=countnext(resultname);
        if(branchcount!=0){
            recursiveRead(height, width, lastcell(filename), kon, branchcount, filename, lista);
        }
        else{
            czydoprintu=isEnd(lista, kon);
            if(czydoprintu)
                printList(lista, kon);
        }
    } else for(int i=0;i<ilep0;i++){
        Listappend(&lista, pocz, i);
        snprintf(resultname, 64, "%s%d_%d.txt", filename, pocz, i);
        branchcount=countnext(resultname);
        if(branchcount!=0){
            recursiveRead(height, width, lastcell(filename), kon, branchcount, filename, lista);
        }
        else{
            czydoprintu=isEnd(lista, kon);
            if(czydoprintu)
                printList(lista, kon);
        }
        deappend(&lista);
    }
}

void convRead(uint16_t height, uint16_t width, int pocz, int kon, uint8_t ilep0, char *filename){
    list_t *lista=malloc(sizeof(list_t));
    recursiveRead(height, width, pocz, kon, ilep0, filename, lista);
    
}