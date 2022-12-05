#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    if(fork()==0){
        exit(0);
    }else{
        sleep(5);
        wait(NULL);

        printf("Teraz z ignorowaniem\n");

        if(fork()==0){
            exit(0);
        }else{
            signal(SIGCLD, SIG_IGN);
            sleep(30);
            wait(NULL);
        }
        
    }

    
}