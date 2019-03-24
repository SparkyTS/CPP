#include "windows.h"
//#include<iostream>
void gotoxy(int x , int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

main()
{
    gotoxy(30,12);
    printf("hello");
    //std::cout<<"Hello";
}
