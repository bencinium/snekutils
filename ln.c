#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv){

    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("ln: Symbolically links two files\n");
            printf("Syntax:\n");
            printf("ln [source file] [target file]\n");
            return 0;
        case 'v':     
            printf("ln command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }

    errno = 0;
    int ret = symlink(argv[1], argv[2]);
    if(ret == -1){
        fprintf(stderr, "ln: %s\n", strerror(errno));
        return 2;
    }

}