


void PartWrite(int n, celltype *branch, char *resultname){
    char *fileend=malloc(7);
    fileend[0]="_";
    fileend[1]=n+"0";
    char *txttype=".txt";
    strcat(fileend, txttype);
    char fullresultname=malloc(32);
    fullresultname=resultname;
    strcat(fullresultname, fileend);
    FILE *zapis=fopen(fullresultname, "w");
    while(branch!=NULL){
        fprintf();
    }
    FILE *metadata=fopen("metadata.txt","w"); //tu zapisujemy metadane o labiryncie: wymiary, ile plikow wynikowych cokolwiek
}