#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    int i;

    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("echo: Prints out text to stdout\n");
        printf("Syntax:\n");
        printf("echo [text]\n");
        return 0;
    }
    if(argv[1] == NULL){
        printf("Invalid Syntax!\n");
        printf("echo [message]\n");
        return 1;
    }

    for(i=1 ; i<argc ; i++)
    {
        printf("%s ",argv[i]);  
    }
    printf("\n");
    return 0;

}
