#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv){

    errno = 0;
    int ret = symlink(argv[1], argv[2]);
    if(ret == -1){
        fprintf(stderr, "ln: %s\n", strerror(errno));
        return 2;
    }

}