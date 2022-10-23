#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char** argv){
    int fdr = 0;
    int fdw = 1;

    if (argc > 1){
        fdr = open(argv[1], O_RDWR);
        fdw = fdr;
    }
    

    char buf[1024];
    int x;
    
    
    x = read(fdr, buf, 1024);
    lseek(fdr, 0, SEEK_SET);
    
    for(int i=0; i<x; i++){
        if(buf[i] >= 'a' && buf[i] <= 'z'){
            buf[i] -= 32;
        }
    }

    write(fdw, buf, x);

    return 0;
}