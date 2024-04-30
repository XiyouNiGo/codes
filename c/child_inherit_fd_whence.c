#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // int fd = open("file.txt", O_RDONLY);
    // if (fd == -1) {
    //     // Handle error
    // }
    // char buffer[5];
    // ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    // if (bytesRead == -1) {
    //     // Handle error
    // }
    // Process the read data
    // printf("%s", buffer);
    // ssize_t n = write(0, "12345", 5);
    // if (n == -1) {
    //     perror("write failed");
    // }

    pid_t p;
    p = fork();
    if(p<0)
    {
      perror("fork fail");
      exit(1);
    }
    // child process because return value zero
    else if ( p == 0) {
        // printf("Hello from Child!\n");
        // char new_buffer[5];
        // read(fd, new_buffer, sizeof(new_buffer));
        // printf("%s\n", new_buffer); 
        char *args[3] = {"/bin/cat", "/dev/stdin", NULL};
        execvp("/bin/cat", args);
        perror("exec fail");
    }
 
    // parent process because return value non-zero.
    // else
    //     printf("Hello from Parent!\n");

    // close(fd);
    return 0;
}