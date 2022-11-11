#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    int fd = open(argv[1], O_RDONLY);

    char a;
    int x;
    int max = 0;
    int i = 0;

    int size = lseek(fd, 0, SEEK_END);

    lseek(fd, -2, SEEK_CUR);

    for(int i=size-1; i>0; i--){
        read(fd, &a, 1);
        printf("%c", a);
        lseek(fd, -2, SEEK_CUR);
    }
    printf("\n");
}