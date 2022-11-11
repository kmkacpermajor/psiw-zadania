#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];

    pipe(fd);
    
    if(fork()!=0){
        close(fd[0]);
        for(int i=1; i<=4; i++){
            write(fd[1], i, sizeof(int));
        }
        close(fd[1]);
    }else{
        fork();
        
    }
}