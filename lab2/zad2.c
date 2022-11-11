#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Begin\n");

    fork();

    printf("End\n");

    return 0;
}