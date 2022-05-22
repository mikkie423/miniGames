// MiniGames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdlib.h>
#include <string>
#include "numGuess.h"

using namespace std;

int mainMenu()
{
	int TOTAL = 1; //TODO update with each game addition
	string minigames[][5] = { {"Guess the Number"} };// MAX 5 words per name, TODO update with each game addition
	int input;

	cout << "\n\t\t\t\t\tMini Games by Mikkie\n\n\n\t\t\t\tChoose which MiniGame to play:\n\n\n" << endl;

	for (int i = 0; i < TOTAL; i++)
	{
		string fullLine = "";
		string mgName = "";
		string num = to_string(i + 1);
		for (int j = 0; j < 5; j++)
		{
			mgName.append(minigames[i][j]);
		}

		fullLine.append("[");
		fullLine.append(num);
		fullLine.append("] ");
		fullLine.append(mgName);

		cout << "\t" << fullLine << endl;
	}

	cin >> input;

	switch (input)
	{
	case 1:
		numGuess().menu();
		break;
	default:
		break;
	}
	return 0;
}

int main()
{
	mainMenu();
}

