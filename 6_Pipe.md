#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int pd, n;
    char msg[] = "Hello. world";

    printf("Server =====\n");

    if (mkfifo("./NAMED-FIFO", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    if ((pd = open("./NAMED-FIFO", O_WRONLY)) == -1) {
        perror("open");
        exit(1);
    }

    printf("To Client : %s\n", msg);

    n = write(pd, msg, strlen(msg)+1);
    if (n == -1) {
        perror("write");
        exit(1);
    }
    close(pd);
}
~                                                                                                                    ~                                                                                                                    ~                                                                                                                    ~                                                                                                                    ~                                                                                                                    ~                                                                                                                    ~                                                                                                                    ~                 
