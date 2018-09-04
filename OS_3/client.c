#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

void main(void)
{
    pid_t pid;
    int status;
    char operand1,operand2,operator;
    printf(">");
    scanf("%c%c%c",&operand1,&operand2,&operator);
    pid = fork();

    if (pid == 0)
    {
        execl("./server", &operand1, &operand2, &operator, NULL);
    }
    else if (pid>0)
    {
        waitpid(pid, &status, 0);
        printf("Result of given operation is %d\n", WEXITSTATUS(status));

    }

exit(0);
}
