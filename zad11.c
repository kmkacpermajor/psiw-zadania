#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char** argv){
    int fd = 0;

    if (argc > 1){
        fd = open(argv[1], O_RDWR);
    }
    

    char a;
    int x;
    int licznik = 0;
    
    
    while(x = read(fd, &a, 1) > 0){
        if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == '_')){
            licznik++;
        }
        if(argc>1 || a == '\n'){
            break;
        }
    }

    printf("Ilość słów: %d\n", licznik);

    return 0;
}