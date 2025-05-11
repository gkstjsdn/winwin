int getConsoleWidth();

int getConsoleHeight();

void move_cursor();

void fillBackgroundWithBlue();

typedef struct {
    int x;              
    int y;             
    int width;          
    int height;         
    char name[100];      
    int color;           
    int isMax;          
} MyWin;

void DrawWin(MyWin a);
