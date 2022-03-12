#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv){


    // checks if the arg count isnt 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'cat -h' for help!\n");
        return 1;
    }

    char ch;

    FILE *source;

    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("cat: Prints out the content of files\n");
            printf("Syntax:\n");
            printf("cat [file]\n");
            return 0;
        case 'v':     
            printf("cat command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }


    source = fopen(argv[1], "r");

    if (source == NULL){
        printf("cat: File '%s' does not exist!\n", argv[1]);
        return 1;
    }

    while((ch = fgetc(source)) != EOF){
      putchar(ch);
      
    }
    printf("\n");
    fclose(source);
    return 0;
}