#include <windows.h>
#include <stdio.h>

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
            printf("\n프로그램 종료\n");
            break;
        }

   
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            GetCursorPos(&mousePos);
            letterX = mousePos.x / 9;   
            letterY = mousePos.y / 21; 
        }

     
        system("cls");
        printf("알파벳 '%c'을 마우스로 드래그하세요 (ESC 종료)\n", letter);
        printf("현재 알파벳 위치: (%d, %d)\n", letterX, letterY);

    
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        Sleep(100); 
    }

    return 0;
}