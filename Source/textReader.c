#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adjacencyMatrix.h"
#include "valconvert.h"
#include "Errormsg.h"
#include "matrixGraphConverter.h"


void StdRead(char *filename, cell_t **labirynt){//działa
    FILE *plik=fopen(filename, "r");
    if(plik==NULL){
        errorcomm(0);
        return;
    }
    char *bufor=malloc(2050);//2*1024+1 i jeszcze 1 na null albo pokazujący że labirynt jest za duży
    if(bufor==NULL){
        errorcomm(1);
        return;
    }
    fgets(bufor, 2050, plik);
    int width=strlen(bufor)-1;
    if(width==2050 || width%2==0){
        errorcomm(2);
        return;
    }
    int height=1;
    while(fgets(bufor,2050,plik)!=NULL){
        height++;//liczy ile linijek
        if(width!=strlen(bufor)-1 || height>2049){
            errorcomm(2);
            return;
        }
    }
    width=trueval(width);
    height=trueval(height);
    labirynt=malloc(height*sizeof(cell_t*));
    for(int i=0;i<height;i++){
        labirynt[i]=malloc(width*sizeof(cell_t));
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            labirynt[i][j].numer=i*width+j; //cell number
            labirynt[i][j].next=NULL;
        }
    }//wyzerowana lista
    rewind(plik);
    int numerstart;
    int numerkoniec;
    cell_t *temp = malloc(sizeof(cell_t));
    temp->numer=0;
    temp->next=NULL;
    for(int i=0;i<posval(height);i++)
    {
        fgets(bufor,posval(width)+2,plik);
        for(int j=0;j<posval(width);j++)
        {
            if(bufor[j]=='P' || bufor[j]=='K'){
                if(bufor[j]=='P'){
                    if(i==0){
                        numerstart=trueval(j);
                    }
                    else{
                        numerstart=trueval(i+1);
                    }
                }
                else{
                    if(i==posval(height)){
                        numerkoniec=trueval(i-1)*width+trueval(j);
                    }
                    else{
                        numerkoniec=trueval(i)*width+trueval(j-1);
                    }
                }
            } else if (i%2==0)
            {
                if (j%2==0)
                {
                //always a wall 
                    if(bufor[j]!='X'){
                        errorcomm(2);
                        return;
                    }
                }
                else{             
                    if(bufor[j]==' '){
                        temp->numer=trueval(i+1)*width+trueval(j);
                        temp->next=labirynt[trueval(i-1)][trueval(j)].next;
                        labirynt[trueval(i-1)][trueval(j)].next=temp;
                        temp->numer-=width;
                        temp->next=labirynt[trueval(i+1)][trueval(j)].next;
                        labirynt[trueval(i+1)][trueval(j)].next=temp; 
                    } //up down pass
                } 
            }else
            {
                if (j%2==0)
                {
                    if(bufor[j]==' '){
                        temp->numer=trueval(i)*width+trueval(j+1);
                        temp->next=labirynt[trueval(i)][trueval(j-1)].next;
                        labirynt[trueval(i)][trueval(j-1)].next=temp;
                        temp->numer-=1;
                        temp->next=labirynt[trueval(i)][trueval(j+1)].next;
                        labirynt[trueval(i)][trueval(j+1)].next=temp;
                    } //left right pass                
                } else
                {
                    if(bufor[j]!=' '){//always cell
                        errorcomm(2);
                        return;
                    }
                }
            }
        }
    }
    conv2graph(labirynt, width, height, numerstart);
    FILE *metadata=fopen("metadata.txt", "w");
    fprintf(metadata, "%d %d %d %d", height, width, numerstart, numerkoniec);
    fclose(metadata);
}