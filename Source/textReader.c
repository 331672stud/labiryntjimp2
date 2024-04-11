#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMatrix.h"
#include "valconvert.h"



char switchcase(int cheight, int cwidth, char *bufor){


}

void StdRead(char *filename, graph_t *graf, cell_t **labirynt){
    FILE *plik=fopen(filename, "r");
    if(plik==NULL){
        errorcomm(0);
        return EXIT_FAILURE;
    }
    char *bufor=malloc(2050);//2*1024+1 i jeszcze 1 na null albo pokazujący że labirynt jest za duży
    //tak samo
    fgets(bufor, 2050, plik);
    int width=strlen(bufor);
    //if strlen()>2049 or strlen()/2!=1 error
    width=trueval(width);
    int height=1;
    while(fgets(bufor,2050,plik)!=NULL)
        height++;//liczy ile linijek
    //if height()>2049 or height/2!=1 error
    height=trueval(height);
    labirynt=malloc(height*sizeof(*char));
    for(int i=0;i<height;i++){
        labirynt[i]=malloc(width*sizeof(char));
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            labirynt[i][j].numer=i*width+j; //cell number
            labirynt[i][j].next=NULL;
        }
    }//wyzerowana lista
    rewind(plik);
    cell_t temp{0, NULL};
    for(int i=0;i<posval(height);i++){
        for(int j=0;j<posval(width);j++){
            if(bufor[j]=="P" or bufor[j]=="K")
                //mark nearest as
            else if(i%2==0)
                if(j%2==0) //always a wall
                    if(bufor[j]!="X")
                        //error
                else{
                    temp.numer=trueval(i+1)*width+trueval(j);
                    labirynt[trueval(i-1)][trueval(j)].next=temp;
                    temp.numer-=width;
                    labirynt[trueval(i+1)][trueval(j)].next=temp;                    
                } //up down pass
            else if(j%2==0){
                temp.numer=trueval(i)*width+trueval(j+1);
                labirynt[trueval(i)][trueval(j-1)].next=temp;
                temp.numer-=1;
                labirynt[trueval(i)][trueval(j+1)].next=temp;
            } //left right pass
            else //cell
                if(bufor[j]!=" ")
                    //error
        }
    }
    conv2graph(labirynt, graf, width, height);
}