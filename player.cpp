#include "player.h"
#include <iostream>

Human::Human(){}
Human::~Human(){}

Human::Male::Male(){}
Human::Male::~Male(){}

void Human::Male::setStats(int a, int h, int w, string n)
{
	this->age = a;
	this->height = h;
	this->weight = w;
	this->name = n;
}
void Human::Male::printStats()
{
	cout << "Name: " << name << ".";
	cout << "\n\n";
	cout << "Age: " << age << " years old.";
	cout << "\n\n";
	cout << "Height: " << height << " inches tall.";
	cout << "\n\n";
	cout << "Weight: " << weight << " pounds.";
	cout << "\n";
}
void Human::Male::interact(bool greeting, bool goodbye, bool insult, bool compliment, bool conversationLineOne, bool conversationLineTwo)
{
	if (greeting == true)
	{
		cout << this->greeting << endl;
	}
	else if (goodbye == true)
	{
		cout << this->goodbye << endl;
	}
	else if (insult == true)
	{
		cout << this->insult << endl;
	}
	else if (compliment == true)
	{
		cout << this->compliment << endl;
	}
	else if (conversationLineOne == true)
	{
		cout << this->conversationLineOne << endl;
	}
	else if (conversationLineTwo == true)
	{
		cout << this->conversationLineTwo << endl;
	}
	else
	{
		return;
	}

}
void Human::Male::setInteraction(bool greeting, bool goodbye, bool insult, bool compliment, bool conversationLineOne, bool conversationLineTwo, string interaction)
{
	if (greeting == true)
	{
		this->greeting = interaction;
	}
	else if (goodbye == true)
	{
		this->goodbye = interaction;
	}
	else if (insult == true)
	{
		this->insult = interaction;
	}
	else if (conversationLineOne == true)
	{
		this->conversationLineOne = interaction;
	}
	else if (conversationLineTwo == true)
	{
		this->conversationLineTwo = interaction;
	}
	else if (compliment == true)
	{
		this->compliment = interaction;
	}
	else
	{
		return;
	}
}
void Human::Male::outputBody()
{
	cout << endl;
	cout << "    " << "\n";
	cout << " _|_ " << "\n";
	cout << "| | |  " << "\n";
	cout << "| | |  " << "\n";
	cout << " / \\" << "\n";
	cout << "/   \\" << "\n";
	cout << endl;
}

Human::Female::Female()
{

}
Human::Female::~Female()
{

}
void Human::Female::setStats(int age, int height, int weight, string name)
{
	this->age = age;
	this->height = height;
	this->weight = weight;
	this->name = name;
}
void Human::Female::printStats()
{
	cout << "Name: " << name << ".";
	cout << "\n\n";
	cout << "Age: " << age << " years old.";
	cout << "\n\n";
	cout << "Height: " << height << " inches tall.";
	cout << "\n\n";
	cout << "Weight: " << weight << " pounds.";
	cout << "\n";
}
void Human::Female::interact(bool greeting, bool goodbye, bool insult, bool compliment, bool conversationLineOne, bool conversationLineTwo)
{
	if (greeting == true)
	{
		cout << this->greeting << endl;
	}
	else if (goodbye == true)
	{
		cout << this->goodbye << endl;
	}
	else if (insult == true)
	{
		cout << this->insult << endl;
	}
	else if (compliment == true)
	{
		cout << this->compliment << endl;
	}
	else if (conversationLineOne == true)
	{
		cout << this->conversationLineOne << endl;
	}
	else if (conversationLineTwo == true)
	{
		cout << this->conversationLineTwo << endl;
	}
	else
	{
		return;
	}
}
void Human::Female::setInteraction(bool greeting, bool goodbye, bool insult, bool compliment, bool conversationLineOne, bool conversationLineTwo, string interaction)
{
	if (greeting == true)
	{
		this->greeting = interaction;
	}
	else if (goodbye == true)
	{
		this->goodbye = interaction;
	}
	else if (insult == true)
	{
		this->insult = interaction;
	}
	else if (conversationLineOne == true)
	{
		this->conversationLineOne = interaction;
	}
	else if (conversationLineTwo == true)
	{
		this->conversationLineTwo = interaction;
	}
	else if (compliment == true)
	{
		this->compliment = interaction;
	}
	else
	{
		return;
	}
}
void Human::Female::outputBody()
{
	cout << endl;
	cout << "    " << "\n";
	cout << " _|_ " << "\n";
	cout << "| | |  " << "\n";
	cout << "| | |  " << "\n";
	cout << " / \\" << "\n";
	cout << "/   \\" << "\n";
	cout << endl;
}
