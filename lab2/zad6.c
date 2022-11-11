#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    // 3 zombie
            
    if(fork()==0 || fork()==0 || fork()==0){
        exit(0);
    }else{
        sleep(30);
        wait(NULL);
    }

    return 0;
}