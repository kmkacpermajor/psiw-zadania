#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fifo_serwer;
    int fifo_klient;
    char buf[500]="";
    mkfifo("fifo_klient", 0644);
    
    fifo_serwer = open("fifo_serwer", O_WRONLY);
    write(fifo_serwer, "fifo_klient", sizeof("fifo_klient"));

    fifo_klient = open("fifo_klient", O_RDONLY);

    scanf(&buf);
    while(strstr(buf, "exit") != NULL){
        write(fifo_serwer, buf, sizeof(buf));
        read(fifo_klient, buf, sizeof(buf));
    }
    close(fifo_klient);
    close(fifo_serwer);
}