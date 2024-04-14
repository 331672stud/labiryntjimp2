#include <stdio.h>


void errorcomm(int code){
    switch (code)
    {
        case 0:
            fprintf(stdout, "Error 0: Nie udalo sie otworzyc pliku.");
            break;
        case 1:
            fprintf(stdout, "Error 1: Nie udalo sie zaalokowac bufora.");
            break;
        case 2:
            fprintf(stdout, "Error 2: Labirynt jest w niezgodnym formacie.");
            break;
        case 3:
            fprintf(stdout, "Error 3: Blad alokacji pamieci.");
            break;
        case 4:
            fprintf(stdout, "Error 4: Kolejka jest pusta gdy próbujemy usunąć element");
        default:
            break;
    }
}