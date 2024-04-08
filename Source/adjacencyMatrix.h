


typedef struct cell{
    int kierunek; //last-current cell (+/- 1/m)
    struct komorka *next; //kolejna komorka w ciagu
} cell_t; 