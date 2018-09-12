#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

void main(void)
{
    pid_t pid;
    int status;
    char operator[2], operand1[10] ,operand2[10];
    printf(">");
    scanf("%s %s %s",operand1,operator,operand2);
    pid = fork();

    if (pid == 0)
    {
        execl("./server",operand1,operator,operand2,NULL);
    }
    else if (pid>0)
    {
        waitpid(pid, &status, 0);
        printf("Result of given operation is %d\n", WEXITSTATUS(status));

    }

exit(0);
}
