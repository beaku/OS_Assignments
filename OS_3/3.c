#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

void main(void)
{
    int pid;
    int status;
    pid=fork();

    if(pid>0)
    {
        pid=wait(status);
        printf("Value of this parent process = %d and child of this process is %d\n",getpid(),pid);
    }
    else if(pid==0)
    {
        printf("This is from Child Process\n");
      exit(0);
    }

}