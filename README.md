# semaphoresInC
__Date of Project:__ September 2018

This project was undertaken as an assignment for Advanced Operating Systems course for my Masters degree where I have written two programs for achieving synchronization among __threads__ and __processes__.

__Synchronization:__ It is a means of making shared resources available in a shared system in such a way that concurrent access to shared resources are controlled. The part of code that makes a shared resource access is called as _Critical Section_. Synchronization ensures that only a single entity enters its critical section at a time so that there are no conflicts during access. A solution to this classic problem requires the following properties be satisfied:
* mutual exclusion
* progress
* bounded wait

_Semaphores_ are a synchronization tool that uses integer values to indicate a critical section access and this value is only reset when the entity in critical section exits form it, ensuring that other processes cannot enter critical section in the meanwhile.

Source and more information: https://www.csitquestions.com/operating-system/process-synchronization-operating-system

Both the programs are written in the __C__ language. _Multi_Thread_Semaphore.c_ creates multiple threads based on user input and uses a semaphore to control access of a shared resource, which is updated by each __i<sup>th</sup>__ thread by adding the value of __i__ to the variable. _Multi_Process_Semaphore.c_ does everything the same and the only difference is that this program forks multiple processes (instead of creating threads). This makes it a bit tricky to code because you first have to define a structure and then share this among the processes.

# Instructions for environment setup:
* Install any C compiler of your choice into your system

# Execution instructions:
A thing to remember is that my compiler is GNU CC and the command for compilation of _C_ programs for my case is `gcc`, in your case it may differ and thus remember to change the compiler command before you start execution.
* Compile Multi_Thread_Semaphore.c using `gcc -o multi_thread Multi_Thread_Semaphore.c -lpthread`
* Compile Multi_Process_Semaphore.c using `gcc -o multi_process Multi_Process_Semaphore.c -lpthread`
* Execute Multi_Thread_Semaphore.c using `./multi_thread`
* Execute Multi_Process_Semaphore.c `./multi_process`
