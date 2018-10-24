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
  
    char str1[80]; 
    while (1) 
    { 
        fd1 = open(namefifo,O_RDONLY); 
        read(fd1, str1, 80); 

        printf("User1: %s\n", str1); 
        char h[8] = "exit\n";
        if( strcmp(str1,h) == 0 )
        {
            close(fd1); 
            return 0;
        }
        close(fd1);
    }
    return 0;
}