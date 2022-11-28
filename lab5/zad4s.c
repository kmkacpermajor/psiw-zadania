#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fifo_serwer;
    int fifo_klient;
    char buf[500]="";
    mkfifo("fifo_serwer", 0644);

    fifo_serwer = open("fifo_serwer", O_RDONLY);
    read(fifo_serwer, buf, sizeof(buf));

    fifo_klient = open(buf, O_WRONLY);
    

    while(read(fifo_serwer, buf, sizeof(buf)) > 0){
        if(fork()==0){
            dup2(fifo_klient, 1);
            execlp(buf, buf, NULL);
        }
    }

    close(fifo_klient);
    close(fifo_serwer);

}