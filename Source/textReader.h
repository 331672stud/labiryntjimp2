typedef struct cell{
    int kierunek;
    struct komorka *next;
} celltype;


void StdRead(FILE *plik, char *filename, celltype *graf);