#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
    

    // if arg 1 is --help, prints out the help message
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0 ){
        printf("rmdir: Removes a directory\n");
        printf("cannot handle spaces in directory names\n");
        printf("Syntax:\n");
        printf("rmdir [directory]\n");
        return 0;

    // if arg 1 is --version, prints out version message
    } else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "--v") == 0 || strcmp(argv[1], "--ver") == 0){
        printf("rmdir command, part of snekutils\n");
        printf("version 1.0\n");
        return 0;
    }

    // checks if the arg count isnt exactly 2
    if(argc != 2){
        printf("Invalid syntax!\n");
        printf("use 'rmdir --help' for help!\n");
        return 1;
    }

    // checks if rmdir returns error
    errno = 0;
    int ret = rmdir(argv[1]);
    if (ret == -1){
        switch (errno) {
            case EACCES :
                printf("No permission to write!\n");
                return 1;
            case ENOENT:
                printf("Directory does not exist!\n");
                return 2;
            case ENAMETOOLONG:
                printf("Directory name too long!\n");
                return 3;
            case ENOTEMPTY:
                printf("Directory is not empty!\n");
                return 4;
            case ENOTDIR:
                printf("Specified file is not a directory!\n");
                return 5;
            case EROFS:
                printf("Read only filesystem!\n");
                return 6;
            case EBUSY:
                printf("Directory is currently in use!\n");
                return 7;
            case EIO:
                printf("An I/0 error has occured!\n");
                return 8;
            default:
                perror("mkdir\n");
                return 9;
        }
    }
    return 0;
}