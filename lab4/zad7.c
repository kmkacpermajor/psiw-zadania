#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(){
    int fd[2];
    pipe(fd);

    if(fork()==0){
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("ls", "ls", NULL); 
        close(fd[1]);
    }else{
        char buf[500];
        close(fd[1]);
        read(fd[0], &buf, 500);
        
        for(int i=0; i<500; i++){
            buf[i] = toupper(buf[i]);
        }

        printf("%s", buf);
    }

    return 0;
}
