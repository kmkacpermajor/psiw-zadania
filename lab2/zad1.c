#include <stdio.h>
#include <unistd.h>

int main(){

    if (fork()!=0){
        fork();
    }
    printf("PID:%d PPID:%d\n", getpid(), getppid());

    return 0;
}