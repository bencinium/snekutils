#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    // checks if the arg count isnt less than 2
    if(argc < 2){
        printf("Invalid syntax!\n");
        printf("use 'echo --help' for help!\n");
        return 1;
    }


    // for every arg, print out the arg
    for(int i=1 ; i<argc ; i++)
    {
        printf("%s ",argv[i]);  
    }
    printf("\n");
    return 0;

}
