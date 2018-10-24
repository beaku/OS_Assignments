#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>

int main() 
{ 
    int fd; 

    char * namefifo = "/tmp/namefifo"; 

    char str[100]; 
    while (1) 
    { 
        fd = open(namefifo, O_WRONLY); 

        printf("Enter input: \n");
        fgets(str, 100, stdin); 

        write(fd, str, strlen(str)+1); 
        char exit_str[6] = "exit\n";
        if( strcmp(str,exit_str) == 0 )
        {
            printf("Exiting\n");
            close(fd);
            return 0;
        }
        close(fd); 
    } 
    return 0; 
} 