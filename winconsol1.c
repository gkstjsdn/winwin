#include <windows.h>
#include <stdio.h>

int main() {
    char letter = 'O';          // ����� ����
    POINT mousePos;             // ���콺 ��ġ ���� ����ü
    int letterX = 10;           // O�� �ʱ� X��ǥ
    int letterY = 5;            // O�� �ʱ� Y��ǥ

    system("cls"); // �ʱ� ȭ�� ����

    while (1) {
        // ESC Ű ������ ����
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("\n���α׷� ����\n");
            break;
        }

        // ���콺 ��Ŭ�� ���� ���� ��ġ ����
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            GetCursorPos(&mousePos);
            letterX = mousePos.x / 9;   // ���� �� ���� X��ǥ ��ȯ
            letterY = mousePos.y / 19;  // ���� ���� ���� Y��ǥ ��ȯ
        }

        // �ܼ� ȭ�� ����
        system("cls");
        printf("���ĺ� '%c'�� ���콺�� �巡���ϼ��� (ESC ����)\n", letter);
        printf("���� ���ĺ� ��ġ: (%d, %d)\n", letterX, letterY);

        // Ŀ�� ��ġ �̵� �� ���
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        Sleep(10); // CPU ��� ���̱� ���� ���
    }

    return 0;
}