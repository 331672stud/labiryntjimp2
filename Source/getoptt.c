#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "Errormsg.h"



void parsearg(int argc, char **argv, char *optstring, char **filename, char **resultname){
    int opt;
    while((opt = getopt(argc, argv, optstring)) != -1){
        switch(opt){
            case 't':
                *filename = optarg;
                break;
            case 'n':
                *resultname = optarg;
                break;
            case 'f':
                *filename = optarg;
                break;
            case 'w':
                *resultname = optarg;
                break;
            case 'h':
                printf("\n");
                printf("Sposób użycia: solver -t [nazwa pliku z labiryntem] -n [nazwa plików wyjściowych preprocessora] -f [nazwa plików wyjściowych preprocessora] -w [nazwa pliku wyjściowego programu]\n\n");
                printf("-t: Nazwa pliku wejściowego:\n");
                printf("    - Plik wejściowy może być tylko w formacie [nazwa].txt lub [nazwa].bin.\n");
                printf("    - Plik wejściowy musi znajdować się w folderze Source.\n");
                printf("    - Plik wejściowy nie może nazywać się metadata.txt, ponieważ w działaniu programu w folderze tworzony jest plik o takiej nazwie.\n");
                printf("    - Plik wejściowy musi zawierać poprawnie zapisany labirynt o rozmiarze maksymalnie 1024x1024.\n");
                printf("    - Musi być krótszy niż 64 znaki.\n\n");
                printf("-n: Przedrostek plików zawierających połączenia między komórkami, zapisywanych w folderze Source:\n");
                printf("    - Musi być krótszy niż 64 znaki.\n\n");
                printf("-f: To samo co w -n. Stąd Solver bierze nazwy plików utworzonych w preprocessorze.\n\n");
                printf("-w: Nazwa pliku wyjściowego:\n");
                printf("    - Musi być krótsza niż 64 znaki.\n\n");
                break;
            default:
                fprintf(stderr, "Nieznana flaga: %s, -h for help\n", argv[0]);
                return; 
        }
    }
}
