#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char** argv){
    int fd = open(argv[1], O_RDONLY);
    char a;

    while((read(fd, &a, 1)) > 0){
        if(!isascii(a)){
            printf("Plik nie jest tekstowy\n");
            return 1;
        }
    }
    printf("Plik jest tekstowy\n");
    

    return 0;
}