#include <stdio.h>
#include <windows.h>


struct Window
{
    int x;
    int y;
    int width;
    int height;
    char name[20];
    int colorCode;
};


void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, Cur);
}


void DrawWindow(struct Window win)
{
    for (int i = 0; i < win.height; i++)
    {
        gotoxy(win.x, win.y + i);
        printf("\033[%dm", win.colorCode);

        if (i == 0 || i == win.height - 1 || i == 2)
        {
            for (int j = 0; j < win.width; j++) printf("*");
        }
        else if (i == 1)
        {
            printf("|");
            printf("%s", win.name);
            for (int j = 1 + strlen(win.name); j < win.width - 1; j++) printf(" ");
            printf("|");
        }
        else
        {
            printf("|");
            for (int j = 1; j < win.width - 1; j++) printf(" ");
            printf("|");
        }

        printf("\033[0m");
    }
}

int main() 
{
    int width, height;

    while (1) 
    {
        printf("가로: ");
        scanf_s("%d", &width);
        printf("세로: ");
        scanf_s("%d", &height);

        if (width >= 2 && height >= 4)
            break;
        printf("최소 2*4부터 출력 가능\n\n");
    }

    system("cls");

    printf("\033[42m");
    for (int y = 0; y < 20; y++) 
    {
        gotoxy(0, y);
        for (int x = 0; x < 120; x++)
        {
            printf(" ");
        }
    }
    printf("\033[0m");

    struct Window win1 = { 10, 3, width, height, "한선우", 42 };
    struct Window win2 = { 15, 5, width, height, "한선우", 44 };

    DrawWindow(win1);
    DrawWindow(win2);

    gotoxy(0, height + 10);
    return 0;
}
