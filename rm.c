#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    // checks if the arg count is not 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'rm --help' for help!\n");
        return 1;
    }

    FILE *target;

    target = fopen(argv[1], "r");


    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("rm: Removes specified file\n");
        printf("Syntax:\n");
        printf("rm [file]\n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("rm command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }

 
    // if target file is NULL then it does not exist
    if(target == NULL){
        printf("rm: File '%s' does not exist!\n", argv[1]);
        return 1;
    }
    // removes the target file, if it cant then you dont have permission.
    if(!remove(argv[1])){
        return 0;
    } else {
        printf("rm: Cannot remove file! Do you have permissions?\n");
        return 1;
    }

    return 0;

}
