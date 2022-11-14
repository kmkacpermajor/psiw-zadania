#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
    int fd1[2];
    int fd2[2];
    int buf[100];
    int x;
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);

    pipe(fd1);
    pipe(fd2);

    if(fork()!=0){
        close(fd1[1]);
        close(fd2[1]);

        while(x = (read(fd1[0], &buf, sizeof(int))))
        
    }else{
        int iter=0;
        int fd[2];
        int n;
        if(fork()==0){
            n = n1;
            iter++;
            memcpy(fd, fd1, sizeof(fd));
        }else{
            n = n2;
            memcpy(fd, fd2, sizeof(fd));
        }

        close(fd[0]);
        for (int i=0; i<n; i++){
            write(fd[1], &iter, sizeof(int));
            iter +=2;
        }
        close(fd[1]);
    }


    return 0;
}