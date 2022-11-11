#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];

    pipe(fd);
    
    if(fork()!=0){
        char buf[20];
        close(fd[1]);
        while(read(fd[0], buf, 20)>0)
            printf("%s\n", buf);
        
    }else{
        fork();
        write(fd[1], "Hallo", 5);
    }
}