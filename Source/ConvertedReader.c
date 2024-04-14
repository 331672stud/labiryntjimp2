#include "adjacencyMatrix.h"
#include <stdio.h>
#include <stdbool.h>

int FileRead(char *filename, bool tryb){
    
}

bool checkend(char *resultname){
    FILE *plik=fopen(resultname, "r");
    char *bufor=malloc(32);
    char *numb=malloc(2);
    while(fgets(bufor, 32, plik)!=NULL)
        if(strstr(bufor, "_")!=NULL)
            numb=strstr(bufor,"_");
    if(numb[1]=="0")
        return 1;
    else return 0;
}