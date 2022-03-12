#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv){

    // checks if the arg count isnt less than 2
    if(argc < 2){
        printf("Invalid syntax!\n");
        printf("use 'echo -h' for help!\n");
        return 1;
    }

    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("echo: Prints out text\n");
            printf("Syntax:\n");
            printf("echo [text]\n");
            return 0;
        case 'v':     
            printf("echo command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }

    // for every arg, print out the arg
    for(int i=1 ; i<argc ; i++)
    {
      fputs(argv[i], stdout);
      printf(" ");
    }
    printf("\n");
    return 0;
}