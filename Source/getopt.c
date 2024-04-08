#include "unistd.h"


void parsearg(int argc, char **argv, char *optstring, char **filename, char **resultname){
    int opt;
    while((opt = getopt(argc, argv, optstring)) != -1){
        switch(opt){
            case 't':
                *filename = optarg;
        }
    }
}
