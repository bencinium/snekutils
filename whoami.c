#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(){

 

    errno = 0;
    int ret = printf("%s\n", getlogin());

    if(ret == -1){
        fprintf(stderr, "whoami: %s\n", strerror(errno));
        return 1;
    }
}