#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Begin\n");

    execl("/bin/ls", "ls", "-l", NULL);

    printf("End\n");

    return 0;
}