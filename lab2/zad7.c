#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    // adoptowane sieroty

    int pid = getpid();

    for(int i=1; i<=3; i++)
        if(fork()==0)
            sleep(30);
            
    if(getpid()==pid){
        exit(0);
    }


    return 0;
}