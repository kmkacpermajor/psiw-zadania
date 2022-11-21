#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd[2];
    pipe(fd);

    if(fork()==0){
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("finger", "finger", NULL); 
        close(fd[1]);
    }else{
        close(fd[1]);
        dup2(fd[0], 0);
        const char* args[] = {"cut", "-d", " ", "-f1", NULL};
        execvp("cut", args);
        close(fd[0]);
    }

    return 0;
}