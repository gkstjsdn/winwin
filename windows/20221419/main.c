#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "mywin.h"


int main() {
    char letter = 'O';
    POINT mousePos;
    int letterX = 10;
    int letterY = 5;

    system("cls");

    while (1)
    {

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            printf("\n���α׷� ����\n");
            break;
        }


        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            GetCursorPos(&mousePos);
            letterX = mousePos.x / 9;
            letterY = mousePos.y / 21;
        }


        system("cls");
        printf("���ĺ� '%c'�� ���콺�� �巡���ϼ��� (ESC ����)\n", letter);
        printf("���� ���ĺ� ��ġ: (%d, %d)\n", letterX, letterY);


        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        Sleep(100);
    }


    MyWin win1 = { 10, 3, 50, 12, "â 1 - CYAN", 1, 0 };
    MyWin win2 = { 30, 10, 50, 12, "â 2 - MAGENTA", 2, 0 };
    MyWin win3 = { 50, 13, 50, 12, "â 3 - BROWN", 3, 0 };

     int show1 = 1, show2 = 1, show3 = 1;
    int topWindow = 3;

    fillBackgroundWithBlue();

    DrawWin(win1);
    DrawWin(win2);
    DrawWin(win3);
   

    move_cursor(getConsoleHeight(), 1);
    printf("ESC�� ������ ����˴ϴ�.\n");

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
        Sleep(100);
    }

    system("cls");

    return 0;
}