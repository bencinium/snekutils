#include <asm-generic/errno-base.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char **argv){

    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("mkdir: Makes a directory\n");
        printf("no spaces in directory names (the way its meant to be)\n");
        printf("Syntax:\n");
        printf("mkdir [directory]\n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("mkdir command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }

    // checks if the arg count isnt exactly 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'mkdir --help' for help!\n");
        return 1;
    }
    // makes a directory, checks if mkdir returns an error code.
    errno = 0;
    int ret = mkdir(argv[1], S_IRWXU);

    if(ret == -1){
        fprintf(stderr, "mkdir %s: %s\n", argv[1], strerror(errno));
        return 2;
    }

    return 0;
}