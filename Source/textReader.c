
int trueval(int posval){ //numer komorki
    int trueval=posval-1;
    trueval/=2;
    return trueval;
}

int posval(int trueval){ //wartosc pozycyjna dla calego pliku
    int posval=trueval*=2;
    posval-=1;
    return posval;
}

void StdRead(char *filename, cell_t *graf){
    FILE *plik=fopen(filename, "r");
    //if null return error
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
    cell_t labirynt[height][width];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            labirynt[i][j].kierunek=-1; //basically NULL
            labirynt[i][j].next=NULL;
        }
    }//wyzerowana lista
    rewind(plik);
    for(int i=0;i<posval(height);i++){
        for(int j=0;j<posval(width);j++){
            if(i%2==0)
                if(j%2==0) //always a wall
                    if(bufor[j]!="X")
                        //error
                else{

                } //up down pass
            else if(j%2==0){

            } //left right pass
            else //cell
                if(bufor[j]!=" ")
                    //error
        /*assigns adjacency to labirynt*/
        }
    }
    conv2graph(labirynt, graf);
    //done
}