#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>


int main( int argc, char **arguments)
{
int a;
int b;
int result=0;

a = *arguments[0] - 48;
b = *arguments[2] - 48;

if ( *arguments[1] == '+')
result = a+b;
else result = a-b;

return result; 
}