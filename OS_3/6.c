#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>

pid_t pid;
int status;
void main()
{
    int a=0,i;
    for(i=0;i<10;i++)
    {
        pid=fork();
        if(pid==0)
        {
           a++;
           printf("Value = %d. Address = %p. Pid= %d\n",a,&a,getpid()); 
           wait(&status);
        }

        else{
            a+=2;
           printf("Value = %d. Address = %p. Pid= %d\n",a,&a,getpid()); 
            
        }
    }
    return;
}