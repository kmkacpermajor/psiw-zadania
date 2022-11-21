#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int fd1[2];
    int fd2[2];
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);

    pipe(fd1);
    pipe(fd2);

    if(fork()!=0){
        close(fd1[1]);
        close(fd2[1]);

        int sum=0;
        int a;
        int a2;
        int x;
        int x2;

        while((x = (read(fd1[0], &a, sizeof(int))) > 0) || (x2 = (read(fd2[0], &a2, sizeof(int))) > 0)){
            printf("Suma: %d, a: %d, a2: %d\n", sum, a, a2);
            sum += a+a2;
            a=0;
            a2=0;
        }

        printf("%d\n", sum);
        
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