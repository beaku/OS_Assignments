#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void main(void)
{
    pid_t pid,pid1;
    int status;
    
    pid = fork();
    if(pid>0)
    {
        printf("This is Process=%d with Parent process=%d\n",getpid(),getppid());
        pid1=fork();
        if(pid1>0)
        pid1=wait(&status);
        else
        {
            printf("This is Process=%d with Parent process=%d\n",getpid(),getppid());
            exit(0);
        }
    }
    else if(pid==0)
    {
        printf("This is Process=%d with Parent process=%d\n",getpid(),getppid());
        pid1=fork();
        if(pid1>0)
        pid1=wait(&status);
        else
        {
            printf("This is Process=%d with Parent process=%d\n",getpid(),getppid());
            exit(0);
        } 
    }

}