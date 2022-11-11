#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];

    pipe(fd);
    
    if(fork()!=0){
        if(fork()==0){
            write(fd[1], "Hallo", 5);
        }else{
            char buf[5];
            read(fd[0], buf, 6);
            printf("%s\n", buf);
        }
    }
}