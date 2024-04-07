


void StdRead(char *filename, celltype *graf){
    FILE *plik=fopen(filename, "r");
    //if null return error
    char *bufor=malloc(2050);//2*1024+1 i jeszcze 1 na null albo pokazujący że labirynt jest za duży
    //tak samo
    fgets(bufor, 2050, plik);
    int width=strlen(bufor);
    //if strlen()>2049 or strlen()/2!=1 error
    width-=1;
    width/=2;
    int height=1;
    while(fgets(bufor,2050,plik)!=NULL)
        height++;//liczy ile linijek
    //if height()>2049 or height/2!=1 error
    height=(height-1)/2;
    celltype labirynt[height][width];
    rewind(plik);
    for(int i=0;i<height*2+1;i++){
        for(int j=0;j<width*2+1;j++){
            if(i%2==0)
                if(j%2==0) //always a wall
                    if(bufor[j]!="X")
                        //error
                else //up down pass
            else if(j%2==0) //left right pass

            else //cell
                if(bufor[j]!=" ")
                    //error
        /*assigns adjacency to labirynt*/
        }
    }
    conv2graph(labirynt, graf);
    //done
}