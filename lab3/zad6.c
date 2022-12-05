#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int dops = 1;

void handler(){
    dops = 0;
    printf("Dostałem");
}

int main(){
    signal(SIGINT, handler);

    while(1){
        if(fork()==0){
            if(fork()==0){
                if(dops == 1)
                    execlp("ps", "ps", NULL);
            }else{
                execlp("ls", "ls", NULL);
            }
        }
    }

    
}