#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    int fd = open(argv[1], O_RDONLY);

    char a;
    int x;
    int max = 0;
    int i = 0;

    while((x = read(fd, &a, 1)) > 0){
        if(a==10){
            if(i>max) max=i;
            i=0;
        }else{
            i++;
        }
    }

    printf("Najdłuższa linijka ma długość: %d\n", max);
}