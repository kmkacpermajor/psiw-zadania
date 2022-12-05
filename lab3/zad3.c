#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void comm(){
    printf("Wyświetlam komunikat\n");
}

int main(int argc, char* argv[]) {
    signal(SIGALRM, comm);

    alarm(atoi(argv[1]));

    while(1) ; //pętla nieskończona
}