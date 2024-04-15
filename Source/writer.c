#include "FileList.h"
#include <stdio.h>
#include <stdlib.h>

int nrsciezki=0;

char returndir(int roznica){
    switch (roznica)
    {
    case 1:
        return '<';
        break;
    case -1:
        return '>';
        break;
    default:
        if(roznica>1){
            return '^';
        } else if(roznica<-1){
            return 'v';
        }else{
            printf("\n ERROR roznica komorek %d \n", roznica);
            return '!';
        }
        break;
    }
    return '!';
}

void printfile(char *filename, FILE **wynik, int kon){
    int nrkom;
    char flag='n';
    int lastkom=0;
    char lflag='?';//first
    char dir;
    int czyrun=0;
    FILE *plik_read=fopen(filename, "r");
    if(plik_read==NULL){
        printf("nie udalo sie otworzyc pliku read %s", filename);
        return; 
    }
    fscanf(plik_read, "%c %d ", &flag, &nrkom);
    while(flag=='n' && czyrun==0)
    {
        switch (lflag)
        {
            case '?':
                lastkom=nrkom;
                lflag=flag;
                break;
            case 'n':
                if(nrkom!=kon){
                    fprintf(*wynik, "GO %c\n", returndir(lastkom-nrkom));
                    lastkom=nrkom;
                    lflag=flag;
                } else{
                    fprintf(*wynik, "GO %c\n", returndir(lastkom-nrkom));
                    lastkom=nrkom;
                    lflag=flag;
                    czyrun=1;
                }
                break;
        }
        fscanf(plik_read, "%c %d ", &flag, &nrkom);
    }
    fclose(plik_read);
}

void writePath(list_t *lista, int kon, char *resultname, char *zapis){
    char *filename=malloc(64); 
    snprintf(filename, 64, "%s%d.txt", zapis, nrsciezki);
    nrsciezki++;
    FILE *plik_wyn=fopen(filename, "w");
    if(plik_wyn==NULL){
        printf("nie udalo sie otworzyc pliku wynikowego");
        return;
    }
    fprintf(plik_wyn, "START\n");
    while(lista!=NULL){
        snprintf(filename, 64, "%s%d_%d.txt", resultname, lista->nrkom, lista->nrpliku);
        printfile(filename, &plik_wyn, kon);      
        lista=lista->next;
    }
    fprintf(plik_wyn, "STOP");
    fclose(plik_wyn);
}