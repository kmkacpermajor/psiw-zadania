#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
printf("%d", getpid());

signal(SIGINT, SIG_IGN);

while(1) ; //pętla nieskończona
}