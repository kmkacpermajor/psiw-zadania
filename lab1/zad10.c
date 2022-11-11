#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char** argv){
    int fdr;
    int fdw;
    char a;
    int x;

    fdw = open(argv[argc-1], O_WRONLY | O_CREAT, 0666);

    for(int i=1; i<argc-1; i++){
        fdr = open(argv[i], O_RDONLY); 

        while((x = read(fdr, &a, 1)) > 0){
            write(fdw, &a, 1);
        }
    }
    
    return 0;
}