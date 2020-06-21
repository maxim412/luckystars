#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;



class NPC
{
public:
	NPC();
	~NPC();
	class enemy
	{
	private:
		COORD position;
		string title;
		string appearance;
	public:
		enemy();
		~enemy();
		void setPosition(int x, int y);
		COORD getPosition();
		void setTitle(string title);
		string getTitle();
		void setAppearance(string app);
		string getAppearance();
	};
};
