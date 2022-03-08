#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    char ch;

    FILE *source;

      // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("cat: Prints out file contents to stdout\n");
        printf("Syntax:\n");
        printf("cat [file] \n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("cat command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }

    // checks if the arg count isnt 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'cat --help' for help!\n");
        return 1;
    }

    source = fopen(argv[1], "r");

    if (source == NULL){
        printf("File '%s' does not exist!", argv[1]);
        return 1;
    }

    while((ch = fgetc(source)) != EOF){
      printf("%c", ch);
      
    }
    printf("\n");
    fclose(source);
    return 0;
}