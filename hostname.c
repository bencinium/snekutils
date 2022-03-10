#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {

    char hostname[HOST_NAME_MAX + 1];
    gethostname(hostname, HOST_NAME_MAX + 1);
    int ret = printf("%s\n", hostname);

    if(ret == -1){
        fprintf(stderr, "hostname: error");
        return 1;
    }

}