#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include "npc.h"
#include "time.h"
#include <stdlib.h>  
using namespace std;

COORD badNpcPositions[5];
COORD goodNpcPositions[5];
int score = 0;

int goodScore;
int badScore;



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

        int randX = rand() % 40 + 1;
        int randY = rand() % 20 + 1;

        points[i].setPosition(randX, randY);
        points[i].setAppearance("*");
        cout << points[i].getAppearance();

        goodNpcPositions[i] = points[i].getPosition();
    }



    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";


}
void spawnBadNPC()
{
    NPC::enemy minuses[5];
    for (int i = 0; i < 5; i++)
    {

        int randX = rand() % 40 +1 ;
        int randY = rand() % 20 +1 ;

        minuses[i].setPosition(randX, randY);
        minuses[i].setAppearance("*"); 
        cout << minuses[i].getAppearance();

        badNpcPositions[i] = minuses[i].getPosition();

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

void printInstructions()
{
	setCursorPos(35, 10);
	cout << "See if you can collect five lucky stars!!";
	Sleep(3000);
	system("cls");
	return;
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
            goodScore++;
        }
    }

    for (int i = 0; i < 5; i++)
    {

        if (z == badNpcPositions[i].X && j == badNpcPositions[i].Y)
        {
            badScore++;
        }
    }

}
int checkIfWin()
{
    if (goodScore == 5)
    {
        system("cls");
        cout << "You win!!" << "\n";
        cout << "Lucky stars: " << goodScore << "\n";
        cout << "Unlucky stars: " << badScore << "\n";
        return 0;
    }
    else if (badScore == 5)
    {
        system("cls");
        cout << "You lose." << "\n";
        cout << "Lucky stars: " << goodScore << "\n";
        cout << "Unlucky stars: " << badScore << "\n";
        return 0;
    }
}
int move()
{
    setCursorPos(0, 0);
    while (true)
    {
        checkForWalls();
        checkForNPC();
        checkIfWin();
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
			system("cls");
            return 0;
        }
    }
}


