#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>


int main( int argc, char *arguments[])
{
int a;
int b;
int result=0;

//a = atoi(arguments[0]);
//b = atoi(arguments[2]);

printf("%s %s",arguments[0],arguments[2]);

/*if ( *arguments[1] == '+')
result = a+b;
else result = a-b;
*/
return 10; 
}