#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>

char buf[100];

void main(void)
{
    int i;
    int fd = open("Process Managment.txt",O_RDWR|O_CREAT);
    for(i=1;i<10;i++)
    {
        fork();
        sprintf(buf,"The process with the PID=%d\n",getpid());
        write(fd,buf,strlen(buf));
    }
    close(fd);
}