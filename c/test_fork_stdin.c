#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{
    char ch;
    while((ch=getchar())!='\n'&&ch!=EOF) {
        write(1, &ch, 1);
    } 
    write(1, "\n", 1);
    // make two process which run same 
    // program after this instruction 
    pid_t p = fork(); 
    if(p<0){ 
      perror("fork fail"); 
      exit(1); 
    } else if (p == 0) {
        while((ch=getchar())!='\n'&&ch!=EOF) {
            write(1, &ch, 1);
        } 
        write(1, "\n", 1);
    }
    printf("Hello world!, process_id(pid) = %d \n",getpid()); 
    return 0; 
} 