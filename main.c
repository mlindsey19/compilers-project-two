#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <getopt.h>
#include "scanner.h"
#include "parser.h"

FILE * file;

int main (int argc, char **argv){

    FILE * fp;
    char infile[32];
    char *ext = ".input1";

    if (argc == 1)
        fp = stdin;
    else {
        strcpy(infile, argv[1]);
        char *pos = strstr(infile, ext);
        if(pos == NULL)
            strcat(infile,ext);
        strcat(infile, "\0");
        fp = fopen(infile, "r");
    }
    file = fp;
    parser();
    fclose(fp);

    return 0;
}