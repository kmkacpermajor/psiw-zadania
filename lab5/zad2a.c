#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    
    int fifo;
    mkfifo("kol_fifo", 0644);

    if(fork()==0){
        fifo = open("kol_fifo", O_WRONLY);
        dup2(fifo, 1);
        execlp("ls", "ls", NULL);
        close(fifo);
    }else{
        fifo = open("kol_fifo", O_RDONLY);
        dup2(fifo, 0);
        execlp("wc", "wc", NULL);
        close(fifo);
    }

}