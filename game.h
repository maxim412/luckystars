#pragma once
#include "player.h"
#include "world.h"
#include <stdlib.h>
void game()
{
	printInstructions();
	printWorld();
	move();
}
string lower_string(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')    //checking for uppercase characters
			str[i] = str[i] + 32;         //converting uppercase to lowercase
	}
	return str;
}
void newmalePlayer()
{
	Human::Male newPlayer;
	printf("\nNew male player created\n");

	system("cls");

	int age, height, weight;
	string name;
	cout << "Enter age: ";
	cin >> age;
	cout << "\n";
	cout << "Enter height: (inches) ";
	cin >> height;
	cout << "\n";
	cout << "Enter weight: (lbs) ";
	cin >> weight;
	cout << "\n";
	cout << "Enter name: ";
	cin >> name;
	cout << "\n";
	newPlayer.setStats(age, height, weight, name);
	system("cls");
	//newPlayer.printStats(); TODO: add to cursor

}
void newfemalePlayer()
{
	Human::Female newPlayer;
	printf("\nNew female player created\n");

	system("cls");

	int age, height, weight;
	string name;
	cout << "Enter age: ";
	cin >> age;
	cout << "\n";
	cout << "Enter height: (inches) ";
	cin >> height;
	cout << "\n";
	cout << "Enter weight: (lbs) ";
	cin >> weight;
	cout << "\n";
	cout << "Enter name: ";
	cin >> name;
	cout << "\n";
	newPlayer.setStats(age, height, weight, name);
	system("cls");
	/*newPlayer.printStats();*/

}
void createPlayer()
{
	while (true)
	{
		string player;
		cout << "Create your character. Male or female?" << "\n\n";
		cin >> player;

		if (lower_string(player) == "male")
		{
			newmalePlayer();
			break;
		}
		else if (lower_string(player) == "female")
		{
			newfemalePlayer();
			break;
		}
		else
		{
			cout << endl << "Enter Male or Female. \n\n";
		}
	}

}
int quit()
{
	while (true)
	{
		string quitReq;
		cout << "\nQuit?\n" << endl;
		cin >> quitReq;

		if (lower_string(quitReq) == "no")
		{
			cout << "\nOk.\n" << endl;
			{
				while (true)
				{
					string play;
					printf("\nPlay game?\n\n");
					cin >> play;

					if (lower_string(play) == "yes")
					{
						cout << endl;
						system("cls"); // clear console
						/*createPlayer();*/
						game();
						break;
					}
					else if (lower_string(play) == "no")
					{
						quit();
						break;
					}
					else
					{
						cout << "Enter yes or no.\n" << endl;
					}
				}
				break;
			}
		}
		else if (lower_string(quitReq) == "yes")
		{
			break;
		}
		else
		{
			cout << endl << "\nEnter yes or no.\n" << endl;
		}
	}
	return 0;
}

void play()
{
	while (true)
	{
		string play;
		printf("Play game?\n\n");
		cin >> play;

		if (lower_string(play) == "yes")
		{
			
			cout << endl;
			system("cls"); // clear console
			//createPlayer(); implement after adding label to player of this in game world
			game();
			break;
		}
		else if (lower_string(play) == "no")
		{
			quit();
			break;
		}
		else
		{
			cout << endl << "Enter yes or no.\n" << endl;
		}
	}
}






