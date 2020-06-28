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
int goodScore;
int badScore;

COORD alreadyTouchedBadStars[5];
COORD alreadyTouchedGoodStars[5];


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

        int randX = rand() % 25 + 2;
        int randY = rand() % 25 + 2;

        points[i].setPosition(randX, randY);
        points[i].setAppearance("*");
        cout << points[i].getAppearance();

        goodNpcPositions[i] = points[i].getPosition();
    }
}
void spawnBadNPC()
{
    NPC::enemy minuses[5];
    for (int i = 0; i < 5; i++)
    {

        int randX = rand() % 25 +2 ;
        int randY = rand() % 25 +2 ;

        minuses[i].setPosition(randX, randY);
        minuses[i].setAppearance("*"); 
        cout << minuses[i].getAppearance();

        badNpcPositions[i] = minuses[i].getPosition();

    }
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
	setCursorPos(50, 30);
	cout << "See if you can collect five lucky stars out of all the 10 stars.";
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
    COORD currentPosition = getCursorPosition();

    for (int i = 0; i < 5; i++)
    {
        if ((currentPosition.X != alreadyTouchedBadStars[i].X && currentPosition.Y != alreadyTouchedBadStars[i].X) && (currentPosition.X == badNpcPositions[i].X && currentPosition.Y == badNpcPositions[i].Y))
        {
            alreadyTouchedBadStars[i] = currentPosition;
            /*cout << alreadyTouchedBadStars[i].X << "," << alreadyTouchedBadStars[i].Y;*/
            badScore++;
            cout << " ";
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if ((currentPosition.X != alreadyTouchedGoodStars[i].X && currentPosition.Y != alreadyTouchedGoodStars[i].X) && (currentPosition.X == goodNpcPositions[i].X && currentPosition.Y == goodNpcPositions[i].Y))
        {
            alreadyTouchedGoodStars[i] = currentPosition;
            /*cout << alreadyTouchedGoodStars[i].X << "," << alreadyTouchedGoodStars[i].Y;*/
            goodScore++;
            cout << " ";

        }
    }
}
int checkIfWin()
{
    if (goodScore == 5)
    {
        system("cls");
        cout << "You win!!" << "\n\n\n";
        cout << "Lucky stars: " << goodScore << "\n";
        cout << "Unlucky stars: " << badScore << "\n\n";
        exit(0);
    }
    else if (badScore == 5)
    {
        system("cls");
        cout << "You lose." << "\n\n\n";
        cout << "Unlucky stars: " << badScore << "\n\n";
        cout << "Lucky stars: " << goodScore << "\n\n";
        exit(0);
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


