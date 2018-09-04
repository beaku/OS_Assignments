#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void main(void)
{
    int i;
    for(i=1;i<10;i++)
    {
        fork();
        printf("The process with the PID=%d\n",getpid());
    }
}