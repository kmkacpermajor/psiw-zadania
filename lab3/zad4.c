#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void get_sig(){
    printf("Alarm otrzymany\n");
}

int main(int argc, char* argv[]) {
    signal(SIGALRM, get_sig);

    alarm(atoi(argv[1]));

    pause();

    printf("koniec\n");
}