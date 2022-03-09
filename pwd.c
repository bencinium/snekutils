#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char **argv){


    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("%s\n", cwd);
    }else{
       printf("pwd: error");
       return 1;
    }

}