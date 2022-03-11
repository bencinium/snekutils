#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo s_info;
    int ret = sysinfo(&s_info);
    if(ret != 0)
    {
        printf("uptime: %d\n", ret);
        return 1;
    }

    printf("%ld minutes\n", s_info.uptime * 60);
    return 0;
    
}