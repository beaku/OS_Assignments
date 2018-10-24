#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
    int fd1; 

    char * namefifo = "/tmp/namefifo"; 
  
    mkfifo(namefifo, 0666);
  
    char str[100]; 
    while (1) 
    { 
        fd1 = open(namefifo,O_RDONLY); 
        read(fd1, str, 100); 

        printf("Waiting for input....Got it: %s\n", str); 
        char exit_str[6] = "exit\n";
        if( strcmp(str,exit_str) == 0 )
        {
            printf("Exiting\n");
            close(fd1); 
            return 0;
        }
        close(fd1);
    }
    return 0;
}