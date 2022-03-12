#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char **argv){

   int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("pwd: Prints out working directory\n");
            return 0;
        case 'v':     
            printf("pwd command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }


    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
       puts(cwd);
    }else{
       printf("pwd: error");
       return 1;
    }

}