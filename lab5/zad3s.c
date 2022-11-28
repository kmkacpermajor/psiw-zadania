#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fifo_do_nazwy;
    int fifo_do_polecenia;
    char buf[500]="";
    mkfifo("fifo_do_nazwy", 0644);
    
    fifo_do_nazwy = open("fifo_do_nazwy", O_RDONLY);
    read(fifo_do_nazwy, buf, sizeof(buf));
    close(fifo_do_nazwy);
    printf("%s\n", buf);

    fifo_do_polecenia = open(buf, O_WRONLY);
    dup2(fifo_do_polecenia, 1);
    execlp("ls", "ls", NULL);
    close(fifo_do_polecenia);
}