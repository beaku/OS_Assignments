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

    char arr2[80]; 
    while (1) 
    { 
        fd = open(namefifo, O_WRONLY); 

        printf("give input\n");
        fgets(arr2, 80, stdin); 

        write(fd, arr2, strlen(arr2)+1); 
        char h[8] = "exit\n";
        if( strcmp(arr2,h) == 0 )
        {
            close(fd);
            return 0;
        }
        close(fd); 
    } 
    return 0; 
} 