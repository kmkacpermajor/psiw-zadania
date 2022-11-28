#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    
    int fiford;
    int fifowr;
    mkfifo("kol_fifo1", 0644);
    mkfifo("kol_fifo2", 0644);
    mkfifo("kol_fifo3", 0644);
    mkfifo("kol_fifo4", 0644);
    mkfifo("kol_fifo5", 0644);

    if(fork()==0){
        if(fork()==0){
            fifowr = open("kol_fifo1", O_WRONLY);
            dup2(fifowr, 1);
            execlp("ps", "ps", "-ef", NULL);
        }

        if(fork()==0){
            fiford = open("kol_fifo1", O_RDONLY);
            fifowr = open("kol_fifo2", O_WRONLY);
            dup2(fifowr, 1);
            dup2(fiford, 0);
            execlp("tr", "-s", " ", ":", NULL);
        }else{
            fiford = open("kol_fifo2", O_RDONLY);
            fifowr = open("kol_fifo3", O_WRONLY);
            dup2(fifowr, 1);
            dup2(fiford, 0);
            execlp("cut", "cut", "-d:", "-f1", NULL);
        }

    }else{

        if(fork()==0){
            fiford = open("kol_fifo3", O_RDONLY);
            fifowr = open("kol_fifo4", O_WRONLY);
            dup2(fifowr, 1);
            dup2(fiford, 0);
            execlp("sort", "sort", NULL);
        }

        if(fork()==0){
            fiford = open("kol_fifo4", O_RDONLY);
            fifowr = open("kol_fifo5", O_WRONLY);
            dup2(fifowr, 1);
            dup2(fiford, 0);
            execlp("uniq", "uniq", "-c", NULL);
        }else{
            fiford = open("kol_fifo5", O_RDONLY);
            dup2(fiford, 0);
            execlp("sort", "sort", "-n", NULL);
        }
        
    }

}