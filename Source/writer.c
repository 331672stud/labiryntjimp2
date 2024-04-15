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

void writePath(list_t *lista, int kon, char *resultname, char *zapis){
    char *filename=malloc(64);
    snprintf(filename, 64, "%s%d.txt", zapis, nrsciezki);
    nrsciezki++;
    FILE *plik_wyn=fopen(filename, "w");
    if(plik_wyn==NULL){
        printf("nie udalo sie otworzyc pliku wynikowego");
        return;
    }
    int nrkom;
    char flag;
    int nrkoml;
    char lflag='?';
    char dir;
    int czyrun=0;
    while(lista!=NULL){
        snprintf(filename, 64, "%s%d_%d.txt", resultname, lista->nrkom, lista->nrpliku);
        FILE *plik_read=fopen(filename, "r");
        if(plik_read==NULL){
            printf("nie udalo sie otworzyc pliku read %s", filename);
            return;    
        }
        fscanf(plik_read, "%c %d", &flag, &nrkom);
        czyrun=0;
        while(flag!='_' && czyrun==0)
        {
            switch (lflag)
            {
            case '?':
                fprintf(plik_wyn, "START\n");
                nrkoml=nrkom;
                lflag=flag;
                break;
            case '_':
                nrkoml=nrkom;
                lflag=flag;
                break;
            default:
                if(nrkom!=kon){
                    fprintf(plik_wyn, "GO %c\n", returndir(nrkoml-nrkom));
                    nrkoml=nrkom;
                    lflag=flag;
                } else{
                    fprintf(plik_wyn, "GO %c\n", returndir(nrkoml-nrkom));
                    czyrun=1;
                }
                break;
            }
            fscanf(plik_read, "%c %d", &flag, &nrkom);
        }
        fclose(plik_read);
        lista=lista->next;
    }
    fprintf(plik_wyn, "STOP");
    fclose(plik_wyn);
}