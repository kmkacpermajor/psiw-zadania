#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    char* varread = argv[1];
    char* varwrite = argv[2];

    int fdr = open(varread, O_RDONLY);
    int fdw = open(varwrite, O_WRONLY | O_CREAT, 0777);

    char buf[10];
    int x;

    while (x=read(fdr, buf, 10)){
        write(fdw, buf, x);
    }
}