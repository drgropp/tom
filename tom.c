//cat rewrite 

#include <stdio.h>

int main(int argc, char *argv[]){

    if (argc < 2) {
        fprintf(stderr, "usage: tom <file>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){
        fprintf(stderr, "tom: cannot open %s\n", argv[1]);
        return 1;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
    return 0;
}