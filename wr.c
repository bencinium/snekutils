#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    int i;

    FILE *source;

    source = fopen(argv[1], "w");

    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("wr: Writes text to files\n");
        printf("Syntax:\n");
        printf("wr [file] [text]\n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("wr command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }

    // checks if the arg count is less than 4
    if(argc < 4){
        printf("Invalid syntax!\n");
        printf("use 'wr --help' for help!\n");
        return 1;
    }
    // if source is null then the file does not exist
    if(source == NULL){
        printf("wr: File '%s' does not exist!", argv[1]);
        return 1;
    }

    // for each arg, print the args in specified file
    for(i=2 ; i<argc ; i++)
    {
        fprintf(source, "%s ", argv[i]);
    }

    fclose(source);
    return 0;

}