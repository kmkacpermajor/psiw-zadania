#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void obsluga(int signo) {
printf("\nOdebrano sygnał %d\n", signo);
}

int main() {
printf("%d", getpid());

for(int i=1; i<=64; i++)
    signal(i, obsluga);

while(1) ; //pętla nieskończona
}