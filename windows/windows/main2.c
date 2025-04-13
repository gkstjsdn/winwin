#include <windows.h>
#include <stdio.h>

int main() {
    char letter = 'O';          // 출력할 문자
    POINT mousePos;             // 마우스 위치 저장 구조체
    int letterX = 10;           // O의 초기 X좌표
    int letterY = 5;            // O의 초기 Y좌표

    system("cls"); // 초기 화면 정리

    while (1) {
        // ESC 키 누르면 종료
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("\n프로그램 종료\n");
            break;
        }

        // 마우스 좌클릭 중일 때만 위치 갱신
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            GetCursorPos(&mousePos);
            letterX = mousePos.x / 9;   // 문자 폭 기준 X좌표 변환
            letterY = mousePos.y / 19;  // 문자 높이 기준 Y좌표 변환
        }

        // 콘솔 화면 갱신
        system("cls");
        printf("알파벳 '%c'을 마우스로 드래그하세요 (ESC 종료)\n", letter);
        printf("현재 알파벳 위치: (%d, %d)\n", letterX, letterY);

        // 커서 위치 이동 후 출력
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        Sleep(10); // CPU 사용 줄이기 위한 대기
    }

    return 0;
}