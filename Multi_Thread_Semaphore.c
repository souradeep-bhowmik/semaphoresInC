/*
Author          :       Souradeep Bhowmik
Date            :       September 2018
Environment     :       Fedora 28
Compiler        :       GNU Compiler Collection (gcc)
Desc            :       A multi-thread program that updates a shared variable among all threads using semaphore synchronization
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

//      Declaring shared variable and semaphore
int shared_Var = 0;
sem_t sem;

void* count(void* args)		//	Function to perform count
{
        int inc = *((int *)args) + 1;
        sem_wait(&sem);         //	Locking the semaphore
        shared_Var = shared_Var + inc;        //      Increment the shared variable
        printf("\nThis is thread number t%d, and the value of shared variable =%d\n", inc, shared_Var);
        sem_post(&sem);	        //	Unlocking the semaphore
}


int main()                      //      Main module
{
        sem_init(&sem, 0, 1);	//	Initializing the shared semaphore to 1 for mutual exclusive acces
        int number_of_threads;		        //      number_of_threads = User input for number of threads

        printf( "Enter a value for number of threads:");
        scanf("%d", &number_of_threads);

        printf("You entered : %d\n\n", number_of_threads);
        printf("----------------------------------------------------------------------------\n\n");

        pthread_t t[number_of_threads];		//	Declaring the number of threads to be created based on user input

        for(int k=0;k<number_of_threads;k++)
        {
                pthread_create(&t[k], NULL, count, (void *)&k);		//	Creating a thread and calling the counting function
                pthread_join(t[k], NULL);       //      Synchronization
        }

        sem_destroy(&sem);		//	Destroying the semaphore

        return 0;
}