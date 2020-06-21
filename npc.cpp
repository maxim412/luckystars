#include "npc.h"
NPC::NPC()
{
}
NPC::~NPC()
{
}
NPC::enemy::enemy()
{
}
NPC::enemy::~enemy()
{
}
void NPC::enemy::setPosition(int x,int y)
{
	this->position.X = x;
	this->position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
COORD NPC::enemy::getPosition()
{
	return this->position;
}
void NPC::enemy::setTitle(string title)
{
	this->title = title;
}
string NPC::enemy::getTitle()
{
	return this->title;
}
void NPC::enemy::setAppearance(string app)
{
	this->appearance = app;
}
string NPC::enemy::getAppearance()
{
	return this->appearance;
}


