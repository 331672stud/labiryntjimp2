


typedef struct cell{
    int kierunek; //last-current cell (+/- 1/m)
    struct komorka *next; //kolejna komorka w ciagu
    bool czycross; //czy istnieje wiecej niz jedna sciezka stad
} celltype;