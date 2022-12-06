# system-programming-test


## 1. 프로세서의 메모리 구조에 대하여 기술하세요.


#### 프로그램을 실행하면 프로세스가 생성되는데, 메모리에 적재된 프로세스는 기본적으로 스택,빈 공간, 힙, 데이터, 텍스트로 메모리가 할당됩니다.
#### 텍스트 영역 : 실행코드를 저장한다. 텍스트 영역은 프로세스 실행 중에 크기가 변하지 않는 고정 영역에 속한다.
#### 데이터 영역 : 프로그램에서 정의한 전역 변수를 저장한다. 전역 변수는 프로그램을 작성할 때 크기가 고정되므로 고정 영역에 할당된다. 
#### 힙 영역 : 프로그램 실행 중에 동적으로 메모리를 요청하는 경우에 할당되는 영역으로, 빈 영역 - 할당  - 할당 해제처럼 상태가 변하는 가변 영역이다.
#### 스택 영역 : 프로그램에서 정의한 지역 변수를 저장하는 메모리 영역으로, 지역 변수를 정의한 부분에서 할당해 사용한다. 
#### 빈 공간 : 스택이나 힙과 같이 가변적인 메모리 할당을 위해 유지하고 있는 빈 매모리 영역이다. 프로세스에 할당된 빈 메모리 영역이 모두 소진되면 메모리 부족으로 프로그램 실행이 중단될 수도 있다. 


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
