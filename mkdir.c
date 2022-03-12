
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char **argv){

    // checks if the arg count isnt exactly 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'mkdir -h' for help!\n");
        return 1;
    }


    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("mkdir: Prints out files in a directory\n");
            printf("Syntax:\n");
            printf("mkdir [directory]\n");
            return 0;
        case 'v':     
            printf("mkdir command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
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