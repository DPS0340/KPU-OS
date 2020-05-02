#include <stdio.h>
#include <windows.h>

int main(void)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // 메모리 할당
    // 메모리를 zero fill
    ZeroMemory(&si, sizeof(si));
    // 메모리 크기 설정
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // 자식 프로세스 생성
    if (!CreateProcess(NULL, // 명령어 라인 사용
                       "C:\\WINDOWS\system32\\mspaint.exe", // 명령어 라인
                       NULL, // 프로세스를 상속하지 말 것
                       NULL, // 스레드 핸들을 상속하지 말 것
                       FALSE, // 행들 상속 디제이블
                       0, // 생성 플래그 없음
                       NULL, // 부모 환경 블록 사용
                       NULL, // 부모 프로세스가 존재하는 디렉터리 사용
                       &si, // si의 주소값에 결과값 할당
                       &pi // pi의 주소값에 결과값 할당))
    {
        // 생성 함수가 0이 아닌 값을 return하였을 시
        // 즉, 생성이 실패되었을 시
        // stderr에 오류 출력
        fprintf(stderr, "Create Process Failed");
        // 0이 아닌 종료 코드 출력
        return -1;
    }
    // 부모 프로세스가 자식 프로세스가 끝나기를 기다림
    // 제한 시간 없음
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child Complete");

    // 프로세스와 스레드 핸들 닫기
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}