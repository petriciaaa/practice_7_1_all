#include <iomanip>
#include <windows.h> 
#include <ctime> 
#include <iostream>


using namespace std;


struct Time {
    int hour;
    int min;
    int sec;
};

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

void print(Time currTime) {

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdout, &csbi);

    const int  WINDOW_WIDTH = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    const int  WINDOW_HEIGH = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    COORD point = { (WINDOW_WIDTH - 4) / 2 ,(WINDOW_HEIGH - 1) / 2 };

    SetConsoleCursorPosition(hStdout, point);
    SetConsoleTextAttribute(hStdout, rand() %7+1);
   
    cout << setw(2) << setfill('0')<< currTime.hour << ":" << setw(2) << setfill('0') << currTime.min << ":" << setw(2) <<setfill('0') << currTime.sec  << endl;

}

void times(Time currTime) {

    while (true)
    {
        print(currTime);

        Sleep(1000);

        currTime.sec++;

        //spaghetti 
        if (currTime.sec == 60) {
            currTime.sec = 0;
            currTime.min++;
            if (currTime.min == 60) {
                currTime.min = 0;
                currTime.hour++;
                if (currTime.hour == 24) {
                    currTime.hour = 0;
                }
            }
        }
    }
}


int main() {

    system("color F");
  
    Time currentTime = { 12, 9, 57 };

    times(currentTime);
    return 0;
}