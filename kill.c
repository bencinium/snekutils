#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, char **argv){

    // checks if the arg count isnt equal 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'kill -h' for help!\n");
        return 1;
    }


    int c;
    while ((c = getopt (argc, argv, "hv")) != -1){
    switch (c)
      {
        case 'h':
            printf("kill: Kills a program\n");
            printf("Syntax:\n");
            printf("kill [PID]\n");
            return 0;
        case 'v':     
            printf("kill command, part of snekutils\n");
            printf("version 1.0\n");
            return 0;
        default:
            return 0;
    
      }
    }

    char *p;
    int num;

    errno = 0;
    long conv = strtol(argv[1], &p, 10);

    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
        printf("kill: Invalid PID!\n");
        return 2;
    } else {
        num = conv;
        pid_t pid = num;

        int ret = kill(pid, SIGSEGV);
        if(ret == -1){
            fprintf(stderr, "kill %d: %s\n", num, strerror(errno));
            return 3;
        }
    }
}