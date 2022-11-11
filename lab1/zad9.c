#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char** argv){
    int fd;
    int fd2;
    char a;
    char a2;
    int x;
    int x2;

    fd = open(argv[1], O_RDONLY);  
    fd2 = open(argv[2], O_RDONLY);

    while((x = read(fd, &a, 1)) > 0){
        x2 = read(fd2, &a2, 1);
        if(x2<1 || a!=a2){
            printf("Pliki są różne\n");
            return 1;
        }
    }

    x2 = read(fd2, &a2, 1);
    if(x2>1){
        printf("Pliki są różne\n");
    }else{
        printf("Pliki są takie same\n");
    }

    return 0;
}