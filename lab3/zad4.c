#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void get_sig(){
    printf("Alarm otrzymany\n");
}

int main(int argc, char* argv[]) {
    char x[20];
    signal(SIGALRM, get_sig);

    alarm(atoi(argv[1]));

    while(1){
        scanf("%s", x);
        if(fork()==0){
            execlp(x, x, NULL);
        }
    }

    pause();

    printf("koniec\n");
}