#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    // checks if the arg count isnt 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'touch --help' for help!\n");
        return 1;
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