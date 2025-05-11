#include <windows.h>
#include <stdio.h>
#include "mywin.h"

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return -1;  // 실패 시
}

// 콘솔 높이 (줄 수)를 구하는 함수
int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    return -1;  // 실패 시
}

// 커서 이동 함수: \033[row;colH
void move_cursor(int row, int col) {
    printf("\033[%d;%dH", row, col);
}


void fillBackgroundWithBlue() {
    int width = getConsoleWidth();
    int height = getConsoleHeight();

    int left = 5, right = 5, top = 1, bottom = 3;
    int startRow = top + 1;
    int endRow = height - bottom;
    int startCol = left + 1;
    int endCol = width - right;

    // 파란색 배경 시작
    printf("\033[44m");

    for (int row = startRow; row <= endRow; row++) {
        move_cursor(row, startCol);
        for (int col = startCol; col <= endCol; col++) {
            printf(" ");
        }
    }

    // 색상 초기화
    printf("\033[0m");

    // 커서를 하단으로 옮김
    move_cursor(endRow + 2, 1);
}


void DrawWin(MyWin a) {
    if (a.isMax) {
        a.x = 0;
        a.y = 0;
        a.width = getConsoleWidth();
        a.height = getConsoleHeight();
    }

    // 배경 색
    if (a.color == 1) printf("\033[46m"); // cyan
    else if (a.color == 2) printf("\033[45m"); // magenta
    else if (a.color == 3) printf("\033[43m"); // brown

    printf("\033[37m"); // 흰 텍스트

    // 윗 테두리
    move_cursor(a.y, a.x);
    printf("┌");
    for (int i = 0; i < a.width - 2; i++) printf("─");
    printf("┐");

    // 내부
    for (int i = 1; i < a.height - 1; i++) {
        move_cursor(a.y + i, a.x);
        printf("│");
        for (int j = 0; j < a.width - 2; j++) printf(" ");
        printf("│");
    }

    // 아래 테두리
    move_cursor(a.y + a.height - 1, a.x);
    printf("└");
    for (int i = 0; i < a.width - 2; i++) printf("─");
    printf("┘");

    // 우측 상단 버튼 ● ● ● (빨, 노, 초)
    move_cursor(a.y, a.x + a.width - 10);
    printf("\033[31m● \033[33m● \033[32m●");

    // 창 이름
    move_cursor(a.y + 2, a.x + 4);
    printf("\033[37m%s", a.name);

    // 초기화
    printf("\033[0m");
}