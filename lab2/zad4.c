#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("Begin\n");

    if (fork() == 0)
        execlp("ls", "ls", "-l", NULL);
    else
        wait(NULL);

    printf("End\n");

}