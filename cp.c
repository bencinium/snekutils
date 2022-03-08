#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
   char ch;
  
   FILE *source, *target;

    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("Syntax:\n");
        printf("cp [file] [target]\n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("cp command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }

    // checks if the arg count isnt 3
    if(argc != 3){
        printf("Invalid syntax!");
        printf("use 'cp --help' for help!");
        return 1;
    }

    // reads the source file
    source = fopen(argv[1], "r");

    // if source is null, the file doesn't exist.
    if (source == NULL){
        printf("File '%s' does not exist.\n", argv[1]);
        return 1;
    }

    // checks if target file already exists
    if ((target = fopen(argv[2], "r"))) {
      fclose(target);
      printf("File '%s' already exists!\n", argv[2]);
      return 1;
    } 
    // writes the target file
    target = fopen(argv[2], "w");

    // if target is null, the user forgot to input the target file.
    if (target == NULL){
        fclose(source);
        printf("Invalid Syntax! Use the --help flag for help.\n");
        return 1;
    }

    while ((ch = fgetc(source)) != EOF){
        fputc(ch, target);
    }

    fclose(source);
    fclose(target);

    return 0;
}