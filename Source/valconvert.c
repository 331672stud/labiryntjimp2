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
