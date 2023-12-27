 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
 
int main() { 
    int fd[2], n; 
    char buffer[100]; 
pid_t p; 
    pipe(fd); 
    p = fork(); 
    if (p > 0) { 
 printf("Parent process pid: %d\n", getppid()); 
 printf("Child process pid: %d\n", p); 
 printf("Passing value child\n"); 
  write(fd[1], "Hello World!\n", 13); 
    } 
    else { 
 printf("Child process pid: %d\n", getpid()); 
 printf("Parent process pid: %d\n", getppid()); 
  n = read(fd[0], buffer, 100); 
 printf("Data received by child process: \n"); 
 write(1, buffer, n); 
    } 
    return 0; 
} 



/*Output 
lab2@lab2-virtual-TW-1/pipe$ gcc TW-1.c 
lab2@lab2-virtual-TW-1/pipe$ ./a.out 
Parent process pid: 7437 
Child process pid: 7618 
Passing value child 
lab2@lab2-virtual-TW-1/pipe$ Child process pid: 7618 
Parent process pid: 1511 
Data received by child process: 
Hello World! */