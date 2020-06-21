#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include "npc.h"
#include "time.h"
using namespace std;

COORD badNpcPositions[5];
COORD goodNpcPositions[5];
int score = 0;


void setCursorPos(int XPos, int YPos) {
    COORD coord;
    coord.X = XPos; coord.Y = YPos;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
COORD getCursorPosition() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(h, &bufferInfo);
    return bufferInfo.dwCursorPosition;
}
void spawnGoodNPC()
{
    srand(time(NULL));
    NPC::enemy points[5];
    for (int i = 0; i < 5; i++)
    {

        int randX = rand() % 40;
        int randY = rand() % 20;

        points[i].setPosition(randX, randY);
        points[i].setAppearance("X");
        cout << points[i].getAppearance();

        goodNpcPositions[i] = points[i].getPosition();

        COORD x = getCursorPosition();

        int xInt = x.X;
        int yInt = x.Y;
        setCursorPos(xInt - 3, yInt + 1);
        cout << points[i].getPosition().X << "," << points[i].getPosition().Y;
    }



    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";



}
void spawnBadNPC()
{
    NPC::enemy minuses[5];
    for (int i = 0; i < 5; i++)
    {

        int randX = rand() % 40;
        int randY = rand() % 20;

        minuses[i].setPosition(randX, randY);
        minuses[i].setAppearance("Y"); // change back to x to trick user 
        cout << minuses[i].getAppearance();

        badNpcPositions[i] = minuses[i].getPosition();

        COORD y = getCursorPosition();

        int xInt = y.X;
        int yInt = y.Y;
        setCursorPos(xInt - 3, yInt + 1);
        cout << minuses[i].getPosition().X << "," << minuses[i].getPosition().Y;
    }


    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
void printWorld()
{
    int walloneXMax = 100;
    int walloneYMax = 100;
    int walltwoXMax = 100; //starts at 0,100
    int walltwoYMax = 100; //starts at 100,0

    for (int i = 0; i < walloneXMax; i++) // first row , x only affected
    {
        setCursorPos(i, 0);
        cout << 0;
    }
    for (int i = 0; i < walltwoXMax; i++) // first row y
    {
        setCursorPos(100, i);
        cout << 0;
    }
    for (int i = 0; i < walloneYMax; i++) // first row y 
    {
        setCursorPos(0, i);
        cout << endl << 0;
    }

    for (int i = 0; i <= walltwoXMax; i++) // first row x
    {
        setCursorPos(i, 100);
        cout << 0;
    }

    spawnGoodNPC();
    spawnBadNPC();
}
void checkForWalls()
{
    int x = getCursorPosition().X;
    int y = getCursorPosition().Y;

    if (x == 0)
    {
        x = 1;
        setCursorPos(x, y);
    }
    if (x == 100)
    {
        x = 99;
        setCursorPos(x, y);
    }
    if (y == 0)
    {
        y = 1;
        setCursorPos(x, y);
    }
    if (y == 100)
    {
        y = 99;
        setCursorPos(x, y);
    }
    
    
}
void checkForNPC()
{
    
    int z = getCursorPosition().X;
    int j = getCursorPosition().Y;

    for (int x = 0; x < 5; x++)
    {

        if (z == goodNpcPositions[x].X && j == goodNpcPositions[x].Y)
        {
            score++;
        }
    }

    for (int i = 0; i < 5; i++)
    {

        if (z == badNpcPositions[i].X && j == badNpcPositions[i].Y)
        {
            score--;
        }
    }

}
int move()
{
    setCursorPos(0, 0);
    while (true)
    {
        checkForWalls();
        checkForNPC();
        int x = getCursorPosition().X;
        int y = getCursorPosition().Y;
        int f;
        f = _getch();
        if (f == 224)
        {
            f = _getch();
            switch (f)
            {
            case 72: //up
                setCursorPos(x, y - 1);
                break;
            case 75: //left
                setCursorPos(x - 1, y);
                break;
            case 77: // right
                setCursorPos(x + 1, y);
                break;
            case 80: // down
                setCursorPos(x, y + 1);
                break;
            case 27:
                return 0;
            }
        }
        else if (f == 27) 
        {
            printf("\033c");
            cout << score;
            return 0;
        }
    }
}


