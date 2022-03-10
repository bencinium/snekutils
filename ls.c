#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

int main(int argc, char **argv) {


    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("Syntax:\n");
        printf("ls [directory]\n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("ls command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }

    // checks if the arg count isnt over 2
    if(argc > 2){
        printf("Invalid syntax!\n");
        printf("use 'ls --help' for help!\n");
        return 1;
    }

    DIR *d;
    struct dirent *dir;


    if(argv[1] != NULL){
        d = opendir(argv[1]);
        if(d == NULL){
            printf("ls: No such directory!\n");
            return 2;
        }
    } else {
        d = opendir(".");
    }

    if (d) {
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_type == DT_REG){ 
            printf("%s  ", dir->d_name);
        }
    }
    closedir(d);
  }
  printf("\n");
  return 0;
}