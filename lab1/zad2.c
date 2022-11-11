#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    for(int i = 1; i<argc; i++){
        int fd = open(argv[i], O_RDONLY);

        int size = lseek(fd, 0, SEEK_END);

        printf("size of %s: %d\n", argv[i], size);
    }
}