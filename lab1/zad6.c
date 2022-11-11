#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void pom(int fdr, int fdw, int tryb){
    char buf[1024];
    char a;
    int x;
    int licznik = 0;
    int i=0;

    lseek(fdr, -1, SEEK_END);

    while((x = read(fdr, &a, 1)) > 0){
        buf[i] = a;

        if (tryb == 0){
            licznik++;
        }else if (tryb == 1 || a=='\n' || a==' ') {
            licznik ++;
        }else if (tryb == 2 || a=='\n'){
            licznik++;
        }

        if (licznik == 10){
            for(int j = i; j>=0; j--) 
                write(fdw, &buf[j], 1);
            break;
        }
        lseek(fdr, -2, SEEK_CUR);
        i++;
    }

    lseek(fdr, 0, SEEK_SET);
    write(fdw, "\n", 1);
}

int main(int argc, char* argv[]){
    int fdr = open(argv[1], O_RDONLY);
    int fdw = open(argv[2], O_WRONLY | O_CREAT, 0666);

    pom(fdr, fdw, 0);

    pom(fdr, fdw, 1);

    pom(fdr, fdw, 2);

    return 0;
}