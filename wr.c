#include <stdio.h>
#include <string.h>
#include <getopt.h>
int main(int argc, char **argv){

    // checks if the arg count is less than 3
    if(argc < 3){
        printf("Invalid syntax!\n");
        printf("use 'wr -h' for help!\n");
        return 1;
    }

    int i;

    FILE *source;

    source = fopen(argv[1], "w");

    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("wr: Writes text to file\n");
            printf("Syntax:\n");
            printf("wr [file] [text]\n");
            return 0;
        case 'v':     
            printf("wr command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
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