#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv){

    // checks if the arg count isnt 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'touch -h' for help!\n");
        return 1;
    }

    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("touch: Creates a file\n");
            printf("Syntax:\n");
            printf("touch [file]\n");
            return 0;
        case 'v':     
            printf("touch command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }


    FILE *target;

    // checks if target file already exists
    if ((target = fopen(argv[1], "r"))) {
      fclose(target);
      printf("touch: File '%s' already exists!\n", argv[1]);
      return 1;
    } 
    // writes the target file, if it cant then it errors out
    if((target = fopen(argv[1], "w"))){
        return 0;
    }else{
        printf("touch: Cannot write file! Do you have permissions?\n");
        return 1;
    }

    fclose(target);
    return 0;
}