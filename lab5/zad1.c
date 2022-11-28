#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    
    int fifo;
    mkfifo("kol_fifo", 0644);

    if(fork()==0){
        char buf[6] = "HALLO!";
        fifo = open("kol_fifo", O_WRONLY);
        
        write(fifo, buf, sizeof(buf));
    }else{
        char buf[500];
        fifo = open("kol_fifo", O_RDONLY);
        while(read(fifo, buf, sizeof(buf))){
            printf("%s\n", buf);
        }
    }
}