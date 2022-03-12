
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
    
    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("rmdir: Removes a directory\n");
            printf("Syntax:\n");
            printf("rmdir [directory]\n");
            return 0;
        case 'v':     
            printf("mkdir command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }


    // checks if the arg count isnt exactly 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'rmdir -h' for help!\n");
        return 1;
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