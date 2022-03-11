#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
    
    // checks if the arg count isnt exactly 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'rmdir --help' for help!\n");
        return 1;
    }


    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("rmdir: Removes a directory\n");
        printf("cannot handle spaces in directory names\n");
        printf("Syntax:\n");
        printf("rmdir [directory]\n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("rmdir command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }


    // checks if rmdir returns error
    errno = 0;
    int ret = rmdir(argv[1]);

    if(ret == -1){
        fprintf(stderr, "rmdir %s: %s\n", argv[1], strerror(errno));
        return 2;
    }

    return 0;
}