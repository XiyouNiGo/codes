#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    while (1) {
        printf("Hello nohup\n");
        sleep(2);
    }
    return 0;
}

