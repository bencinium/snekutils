#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    // checks if the arg count is lower than 2 or higher than 3
    if(argc < 2 || argc > 3){
        printf("Invalid syntax!\n");
        printf("use 'cp -h' for help!\n");
        return 1;
    }

   char ch;
  
   FILE *source, *target;

    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("cp: Copies a file to another file\n");
            printf("Syntax:\n");
            printf("cp [source file] [target file]\n");
            return 0;
        case 'v':     
            printf("cp command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }



    // reads the source file
    source = fopen(argv[1], "r");

    // if source is null, the file doesn't exist.
    if (source == NULL){
        printf("cp: File '%s' does not exist.\n", argv[1]);
        return 1;
    }

    // checks if target file already exists
    if ((target = fopen(argv[2], "r"))) {
      fclose(target);
      printf("cp: File '%s' already exists!\n", argv[2]);
      return 1;
    } 
    // writes the target file
    target = fopen(argv[2], "w");

    // if target is null, the user forgot to input the target file.
    if (target == NULL){
        fclose(source);
        printf("cp: Invalid Syntax! Use the --help flag for help.\n");
        return 1;
    }

    while ((ch = fgetc(source)) != EOF){
        fputc(ch, target);
    }

    fclose(source);
    fclose(target);

    return 0;
}