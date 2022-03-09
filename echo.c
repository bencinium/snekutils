#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){



    // if argv[1] is NULL then the user didn't input anything to echo
    if(argv[1] == NULL){
        printf("Invalid Syntax!\n");
        printf("echo [message]\n");
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
