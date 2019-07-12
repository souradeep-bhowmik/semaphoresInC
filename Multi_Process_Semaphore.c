/*
Author          :       Souradeep Bhowmik
Date            :       September 2018
Environment     :       Fedora 28
Compiler        :       GNU Compiler Collection (gcc)
Desc            :       A multi-process program that updates a variable shared among all threads using semaphore synchronization
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>

typedef struct{		        //	Structure containing shared semaphore and variable
int shared_var;
sem_t sem;
}mem_t;

int main()
{
    int number_of_processes, inc=1;	//n = User input for number of processes;	inc = loop counter
    int shared_memory = shmget(IPC_PRIVATE, sizeof(mem_t), S_IRUSR|S_IWUSR);	//	Creating a shared memory segment
    mem_t *p = (mem_t *)shmat(shared_memory, NULL,0);	//	Attaching to shared memory segment
    sem_init(&p->sem, 0, 1);        //	Initializing the shared semaphore to 1 for mutual exclusive acces

    printf("Enter a value for number of processes: ");
    scanf("%d", &number_of_processes);

    printf("You entered : %d\n\n", number_of_processes);
    printf("----------------------------------------------------------------------------\n\n");

    while(inc<=number_of_processes)
    {
        if(fork()==0)	        //	Forking a process and accessing the child process
        {
            sem_wait(&p->sem);	//	Locking the semaphore
            p->shared_var = p->shared_var + inc;
            printf("\nThis is process number p%d, and the value of shared shared_var =%d\n", inc, p->shared_var);
            sem_post(&p->sem);	//	Unlocking the semaphore
        }
        else			//	The parent process
        {
            wait(NULL);	        //	Parent process waits for child to complete
            break;
        }
        inc++;	        //	Counter variable increase
    }
    return 0;
}