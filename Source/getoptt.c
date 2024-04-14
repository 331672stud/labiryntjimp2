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
            default:
                fprintf(stderr, "Nieznana flaga: %s\n", argv[0]);
                return; 
        }
    }
}