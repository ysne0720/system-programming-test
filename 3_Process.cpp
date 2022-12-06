# 10초 동안 잠드는(sleep) 프로세스를 생성하고, 새로 생성된 프로세스가 종료되는지 확인후 종료하는 프로그램을 작성하시오. 


#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main{
           sleep 10
}

int main() {

    pid_t pid;

    switch (pid = fork()) {
        case -1 : /* fork failed */
            perror("fork");
            exit(1);
            break;
        case 0 : /* child process */
            printf("Child Process - My PID:%d, My Parent's PID:%d\n",
               (int)getpid(), (int)getppid());
            break;
        default : /* parent process */
            printf("Parent process - My PID:%d, My Parent's PID:%d, My Child's PID:%d\n", (int)getpid(), (int)getppid(), (int)pid);
            break;
    }

int main(){
    atexit (Child Process);
    on _exit(Parent process, (void *) 20);


    exit(0)
 }

    printf("End of fork\n");
}
~                                                                                                                                                                                                                                            ~                                                                                                                                                                                                                                            ~                                                                                                                                                                                                                                            ~           
