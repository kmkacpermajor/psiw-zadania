#include <stdio.h>
#include <unistd.h>

int main(){
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);

    if(fork()==0){
        if(fork()==0){
            close(fd2[0]);
            close(fd2[1]);
            close(fd1[0]);

            dup2(fd1[1], 1);
            execlp("ls", "ls", "-l", NULL); 

            close(fd1[1]);
        }else{
            close(fd1[1]);
            close(fd2[0]);

            dup2(fd1[0], 0);
            dup2(fd2[1], 1);
            execlp("grep", "grep", "^d", NULL); 

            close(fd2[1]);
            close(fd1[0]);
        }
        
    }else{
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[1]);
        
        dup2(fd2[0], 0);
        execlp("more", "more", NULL);
        close(fd2[0]);
    }

    return 0;
}