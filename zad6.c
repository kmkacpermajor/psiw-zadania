#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    int fd = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);

    char a;
    int x;
    int licznik = 0;

    lseek(fd, 0, SEEK_SET);

    while(x = read(fd, &a, 1)>0){
        read(fd, &a, 1);
        write(fd2, &a, 1);
        licznik++;
        if (licznik == 10) break;
    }

    licznik = 0;

    lseek(fd, 0, SEEK_SET);

    write(fd2, "\n", 1);
    while(x = read(fd, &a, 1)>0){
        write(fd2, &a, 1);
        if(a=='\n' || a==' '){
            licznik += 1;
        }
        if(licznik==10) break;
    }

    licznik = 0;

    lseek(fd, 0, SEEK_SET);

    write(fd2, "\n", 1);
    while(x = read(fd, &a, 1)>0){
        write(fd2, &a, 1);
        if(a=='\n'){
            licznik += 1;
        }
        if(licznik==10) break;
    }
}