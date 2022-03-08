#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char ch;
  
    FILE *source, *target;
    


    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("mv: Moves a file to target file\n");
        printf("Syntax:\n");
        printf("mv [file] [target]\n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("mv command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }

    // checks if the arg count isnt exactly 3
    if(argc != 3){
        printf("Invalid syntax!");
        printf("use 'mv --help' for help!");
        return 1;
    }
    // open source file
    source = fopen(argv[1], "r");

    // checks if source file exists
    if(source == NULL){
        printf("File '%s' does not exist!", argv[1]);
        return 1;
    }
    // moves source file to target file, if it errors out then you dont have permission.
    if(!rename(argv[1], argv[2])){
        return 0;
    }else{
        printf("Unable to write target file, do you have permissions?\n");
        return 1;
    }

    fclose(source);

    return 0;
}