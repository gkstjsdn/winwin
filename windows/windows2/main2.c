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

    return 0;
}