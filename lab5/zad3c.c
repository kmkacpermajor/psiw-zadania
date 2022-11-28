#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fifo_do_nazwy;
    int fifo_do_polecenia;
    char buf[500];
    mkfifo("fifo_do_polecenia", 0644);
    
    fifo_do_nazwy = open("fifo_do_nazwy", O_WRONLY);
    write(fifo_do_nazwy, "fifo_do_polecenia", sizeof(buf));
    close(fifo_do_nazwy);

    fifo_do_polecenia = open("fifo_do_polecenia", O_RDONLY);
    read(fifo_do_polecenia, buf, sizeof(buf));
    printf("%s\n", buf);
    close(fifo_do_polecenia);
}