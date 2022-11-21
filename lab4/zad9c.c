#include <stdio.h>
#include <unistd.h>

// ps –ef| tr -s ' ' :| cut -d: -f1 |sort| uniq -c |sort -n

int main(){
    int fd1[2];
    pipe(fd1);

    int fd2[2];
    pipe(fd2);

    int fd3[2];
    pipe(fd3);

    int fd4[2];
    pipe(fd4);

    int fd5[2];
    pipe(fd5);

    if(fork()==0){
        if(fork()==0){

        }else{

        }
    }else{
        if(fork()==0){

        }else{
            
        }
    }

    execlp("ps", "ps", "-ef", NULL);
    execlp("tr", "-s", " ", ":", NULL);
    execlp("cut", "cut", "-d:", "-f1", NULL);
    execlp("sort", "sort", NULL);
    execlp("uniq", "uniq", "-c", NULL);
    execlp("sort", "sort", "-n", NULL);

    return 0;
}