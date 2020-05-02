#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid t pid;

    // 새 프로세스를 생성한다(fork)
    pid = fork();
    if (pid < 0)
    { // 에러가 발생 했음
        // stderr에 에러 메시지 출력
        fprintf(stderr, "Fork Failed");
        // non-zero return code
        // 프로그램에 에러가 발생
        return 1;
    }
    else if (pid == 0)
    {
        // 다른 프로세스를 실행
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        // 자식 프로세스가 종료될때까지 대기
        wait(NULL);
        // 자식 프로세스 종료됨
        printf("Child Complete");
        // 프로그램 종료로 넘어감
    }
    return 0;
}