#include <stdio.h>

void errorcom(int code){
    switch (code)
    {
    case 0:
        fprintf(stdout, "Error 0: Nie udalo sie otworzyc pliku.");
        break;
    
    default:
        break;
    }
}

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