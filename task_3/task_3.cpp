#include <iostream>
#include <windows.h>

using namespace std;
int main()
{

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(hStdout, &cursor);
    cursor.bVisible = FALSE;

    SetConsoleCursorInfo(hStdout, &cursor);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdout, &csbi);


    SetConsoleTextAttribute(hStdout, BACKGROUND_BLUE + BACKGROUND_INTENSITY
        + FOREGROUND_BLUE
        +FOREGROUND_GREEN 
        +FOREGROUND_GREEN
        +FOREGROUND_INTENSITY
    );

    // const char Snow =  15, Space = 32;
    const char Snow =  '*', Space = 32;
    const int WindowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top+1, WindowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
 

   
    for (int i = 0; i < WindowHeight * WindowWidth; i++)
    {
        cout << Space;
    }

    COORD start = { 0,0 };
    SetConsoleCursorPosition(hStdout, start);

    //There changes (120 width of my pc , 80 - in classes) 
     COORD Snowflakes[120] = {};
    for (int i = 0; i < (sizeof(Snowflakes) / sizeof(Snowflakes[0])); i++)
    {
         COORD flake = Snowflakes[i];

         flake.X = i;
         flake.Y = rand()% WindowHeight;

         Snowflakes[i] = flake;
    }
    
    while (true)
    {
        for (int i = 0; i < (sizeof(Snowflakes) /sizeof(Snowflakes[0]) ); i++)
        {
            SetConsoleCursorPosition(hStdout, Snowflakes[i]);
            cout << Space;
            Snowflakes[i].Y++;
            if (Snowflakes[i].Y == WindowHeight)
            {
                Snowflakes[i].Y = 0;
            }
            SetConsoleCursorPosition(hStdout, Snowflakes[i]);
            cout << Snow;
        
           
        }
        Sleep(300);
    }
}
