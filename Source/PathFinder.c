#include "adjacencyMatrix.h"
#include <stdint.h>
#include "FileList.h"
#include "ConvertedReader.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t countnext(char *resultname){
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
        FILE *plik=fopen(filename, "r");
        char *bufor=malloc(64);
        do{
            fgets(bufor, 64, plik);
        }while(strstr(bufor, "_")==NULL);
        do{
            bufor=strstr(bufor,";");
        }while(strstr(bufor,";"!=NULL));
        bufor[strlen(bufor)-2]='\0';
        cellnumber=atoi(bufor);
    return cellnumber;
}

bool isEnd(list_t *lista, int kon, char *filename){
    char *resultname = malloc(64);
    list_t *kopia=lista;
    char *konstr=malloc(16);
    while(kopia!=NULL){            
        snprintf(resultname, 64, "%s%d_%d.txt", filename, kopia->nrkom, kopia->nrpliku);
        sprintf(konstr, "%c%d%c", kon);

        kopia=kopia->next;
    }
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
            recursiveRead(height, width, lastcell(resultname), kon, branchcount, filename, lista);
        }
        else{
            czydoprintu=isEnd(lista, kon, filename);
            if(czydoprintu)
                printList(lista, kon);
        }
    } else for(int i=0;i<ilep0;i++){
        Listappend(&lista, pocz, i);
        snprintf(resultname, 64, "%s%d_%d.txt", filename, pocz, i);
        branchcount=countnext(resultname);
        if(branchcount!=0){
            recursiveRead(height, width, lastcell(resultname), kon, branchcount, filename, lista);
        }
        else{
            czydoprintu=isEnd(lista, kon, filename);
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