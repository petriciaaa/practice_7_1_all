#include <iostream>
#include "struct.h"
#include "printRect.h"

int main(){  

    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(hStdout, &cursor);
    cursor.bVisible = FALSE;

    SetConsoleCursorInfo(hStdout, &cursor);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdout, &csbi);
   
    const short WINDOW_WIDTH =1100;
    const short WINDOW_HEIGH = 600;

   //csbi.srWindow.Bottom - csbi.srWindow.Top + 1

    const Rect arr[] = {
        {{0,0},{WINDOW_WIDTH / 2,WINDOW_HEIGH /2},'R'},
        {{WINDOW_WIDTH / 2,0},{WINDOW_WIDTH ,WINDOW_HEIGH / 2},'G'},
        {{0,WINDOW_HEIGH / 2},{WINDOW_WIDTH / 2,WINDOW_HEIGH },'B'},
        {{WINDOW_WIDTH / 2,WINDOW_HEIGH / 2},{WINDOW_WIDTH ,WINDOW_HEIGH },'J'} 
    };
   
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printRect(arr[i]);
    }
    
    std::getchar();
   

    return 0;
}

