#include <iostream>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

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

    const int WindowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1, WindowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    srand(time(NULL));

    const char symbol = '*';
    int directionX = 1; 
    int directionY = 1; 
    int pounceCounter = 0;

    COORD start = { rand() % (WindowWidth - 1) ,rand() % (WindowHeight - 1) };
    
    COORD prevStart = start;
    int speed = 120;
    while (true)
    {
        SetConsoleCursorPosition(hStdout, prevStart);
        std::cout << " ";
        SetConsoleCursorPosition(hStdout, start);
        std::cout << symbol;
        

     
        int x = start.X;
        int y = start.Y;
        x += directionX;
        y += directionY;
        if (x == 0 && y == 0 || x == 0 && y == WindowHeight - 1 ||
            x == WindowWidth - 1 && y == 0 || x == WindowWidth - 1 && y == WindowHeight - 1)
        {
            std::cout << char(32);
            directionX = -directionX;
            directionY = -directionY;
            speed -= 10;
            PlaySound(TEXT(R"(assets\boing2.wav)"), NULL, SND_ASYNC);

        }
        else if (x<= 0 || x >= WindowWidth - 1)
        {
            std::cout << char(32);
            directionX = -directionX;
            speed -= 10;
            PlaySound(TEXT(R"(assets\boing2.wav)"), NULL, SND_ASYNC);
          
        }
        else if (y <= 0 || y >= WindowHeight - 1) {
            std::cout << char(32);
            directionY = -directionY; 
            speed -= 10; 
            PlaySound(TEXT(R"(assets\floop2_x.wav)"), NULL, SND_ASYNC);
           
        }
        prevStart = start;

        start = {short(x),short(y) };
        pounceCounter++;
       
        Sleep(speed >=0? speed: 1);
        
        
 
    }



    std::getchar();
}