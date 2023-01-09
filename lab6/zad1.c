#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/sem.h>
#include <stdlib.h>

static struct sembuf buf;

void podnies(int semid, int semnum){
    buf.sem_num = semnum;
    buf.sem_op = 1;
    buf.sem_flg = 0;
    if (semop(semid, &buf, 1) == -1){
        perror("Podnoszenie semafora");
        exit(1);
    }
}

void opusc(int semid, int semnum){
    buf.sem_num = semnum;
    buf.sem_op = -1;
    buf.sem_flg = 0;
    if (semop(semid, &buf, 1) == -1){
        perror("Opuszczenie semafora");
        exit(1);
    }
}



int main(){

    int semid = semget(123, 1, 0666 | IPC_CREAT);

    semctl(semid, 0, SETVAL, 1);

    int shmid = shmget(123, sizeof(char)*8, 0666 | IPC_CREAT);

    int fromfork = fork();
    
    char* shmaddr = (char *)shmat(shmid, NULL, 0);
    

    while(1){
        if(fromfork){
            opusc(semid, 0);
            strcpy(shmaddr, "haaaa");
            podnies(semid, 0);
        }else{
            opusc(semid, 0);
            strcpy(shmaddr, "hoooooo");
            podnies(semid, 0);
        }

        printf("%s\n", shmaddr);
    }
    

    return 0;
}