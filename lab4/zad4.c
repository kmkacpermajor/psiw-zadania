#include <stdio.h>
#include <unistd.h>

int main(){
    int fd1[2];
    int fd2[2];
    int fd3[2];
    int buf[4];

    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    
    if(fork()!=0){
        close(fd1[0]);
        for(int i=0; i<4; i++){
            buf[i] = i+1;
            printf("%d ", buf[i]);
        }
        printf("\n");
        write(fd1[1], buf, sizeof(buf));
        close(fd1[1]);
    }else{
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], buf, sizeof(buf));
        close(fd1[0]);
        for(int i=0; i<4; i++){
            buf[i]++;
        }
        write(fd2[1], buf, sizeof(buf));
        close(fd2[1]);
        if(fork()==0){
            close(fd3[0]);
            close(fd2[1]);
            read(fd2[0], buf, sizeof(buf));
            close(fd2[0]);
            for(int i=0; i<4; i++){
                buf[i]++;
            }
            write(fd3[1], buf, sizeof(buf));
            close(fd3[1]);
        }else{
            close(fd3[1]);
            read(fd3[0], buf, sizeof(buf));
            close(fd3[0]);
            for(int i=0; i<4; i++){
                buf[i]++;
                printf("%d ", buf[i]);
            }
            printf("\n");
        }
    }
}