#pragma once
#include <string>
using namespace std;

class Human
{
public:
	Human();
	~Human();
	class Male
	{
	private:
		string name;
		int age, height, weight;
		//speech
		string greeting, goodbye, insult, compliment, conversationLineOne, conversationLineTwo;

	public:
		Male();
		~Male();
		void setStats(int age, int height, int weight, string name);
		void printStats();
		void interact(bool greeting, bool goodbye, bool insult, bool compliment, bool conversationLineOne, bool conversationLineTwo);
		void setInteraction(bool greeting, bool goodbye, bool insult, bool compliment, bool conversationLineOne, bool conversationLineTwo, string interaction);
		void outputBody();


	};

	class Female
	{
	private:
		string name;
		int age, height, weight;
		//speech
		string greeting, goodbye, insult, compliment, conversationLineOne, conversationLineTwo;
	public:
		Female();
		~Female();
		void setStats(int age, int height, int weight, string name);
		void printStats();
		void interact(bool greeting, bool goodbye, bool insult, bool compliment, bool conversationLineOne, bool conversationLineTwo);
		void setInteraction(bool greeting, bool goodbye, bool insult, bool compliment, bool conversationLineOne, bool conversationLineTwo, string interaction);
		void outputBody();
	};
};

