#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv){

    // checks if the arg count is not 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'rm -h' for help!\n");
        return 1;
    }

    FILE *target;

    target = fopen(argv[1], "r");


    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("rm: Removes a file\n");
            printf("Syntax:\n");
            printf("rm [file]\n");
            return 0;
        case 'v':     
            printf("rm command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }

 
    // if target file is NULL then it does not exist
    if(target == NULL){
        printf("rm: File '%s' does not exist!\n", argv[1]);
        return 1;
    }
    // removes the target file, if it cant then you dont have permission.
    if(!remove(argv[1])){
        return 0;
    } else {
        printf("rm: Cannot remove file! Do you have permissions?\n");
        return 1;
    }

    return 0;

}
