#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    int fd = open(argv[1], O_RDWR);

    char a;
    int x;
    char pom[256];
    int i = 0;

    while( (x = read(fd, &a, 1)) > 0){
        if(a==10){
            int size = i;
            for (int j=0; j<=size; j++)  printf("%c", pom[j]);
            lseek(fd, -size-1, SEEK_CUR);
            for (int j=size-1; j>=0; j--){
                write(fd, &pom[j], 1);
            }
            i=0;
            write(fd, "\n", 1);
        }else{
            pom[i] = a;
            i++;
        }
    }
}