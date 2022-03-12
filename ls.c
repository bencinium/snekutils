#include <dirent.h> 
#include <stdio.h> 
#include <getopt.h>

int main(int argc, char **argv) {

    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("ls: Prints out files in a directory\n");
            printf("Syntax:\n");
            printf("ls [directory]\n");
            return 0;
        case 'v':     
            printf("ls command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }

    // checks if the arg count isnt over 2
    if(argc > 2){
        printf("Invalid syntax!\n");
        printf("use 'ls -h' for help!\n");
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