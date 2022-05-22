//this is a testing change
//Testing round two

#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>
#include <cstring>
#include "numGuess.h"
using namespace std;

void numGuess::menu()
{
	choice = 0;
	difficulty = 0;
	guess = 0;

	system("CLS");

	cout << "\n\t\t\t\t\tGuess The Number\n" << endl;
	cout << "\t[1] Start New Game" << endl;
	cout << "\t[2] Instructions" << endl;
	cout << "\t[3] High Score Board" << endl;
	cout << "\t[4] Exit Game" << endl;

	cin >> choice;

	switch (choice)
	{
	case 1:
		startGame();
		break;
	case 2:
		instructions();
		break;
	case 3:
		difficulty = 1;
		displayAllHighScores(difficulty);
		break;
	case 4:
		exitGame();
		break;
	}
}

void numGuess::instructions()
{
	system("CLS");

	cout << "The computer will pick a random number between either:\n\n\tEASY: 1 - 10\n\tMEDIUM: 1 - 50\n\tHARD: 1 - 100\n\tIMPOSSIBRO: 1 - 10,000\n" << endl;
	cout << "You must input your guess for what the number might be." << endl;
	cout << "The computer will tell you if you need to go higher or lower, and will give you the chance to guess again until you get the number right." << endl;
	cout << "High Scores are calculated by the number of guesses it takes you to figure out the secret number." << endl;
	system("PAUSE");
	numGuess().menu();
}

void numGuess::startGame()
{
	gameScore = 0;
	levelPicker();
	generateNumber(choice);
	gameLoop();
}

int numGuess::levelPicker()
{
	system("CLS");
	cout << "\n\t\t\t\t\tPick a level of difficulty:" << endl;
	cout << "\t[1] Easy 1 - 10" << endl;
	cout << "\t[2] Medium 1 - 50" << endl;
	cout << "\t[3] Hard 1 - 100" << endl;
	cout << "\t[4] ImpossiBro! 1 - 10,000" << endl;

	cin >> choice;
	difficulty = choice;
	return difficulty;
}

int numGuess::generateNumber(int difficulty)
{
	srand(time(NULL)); //intialize random seed

	switch (difficulty)
	{
	case 1:
		randNum = rand() % 10 + 1;
		break;
	case 2:
		randNum = rand() % 50 + 1;
		break;
	case 3:
		randNum = rand() % 100 + 1;
		break;
	case 4:
		randNum = rand() % 10000 + 1;
		break;
	}
	return randNum;
}

int numGuess::gameLoop()
{
	system("CLS");
	do
	{
		cout << "Enter your guess: " << endl;
		cin >> guess;
		gameScore++;
		if (guess > randNum)
		{
			cout << "The number I'm thinking of is lower than " << guess << ". Try again.\n" << endl;
		}
		else if (guess < randNum)
		{
			cout << "The number I'm thinking of is higher than " << guess << ". Try again.\n" << endl;

		}
	} while (guess != randNum);
	if (guess == randNum)
	{
		winScreen();
	}
	return gameScore;
}

void numGuess::winScreen()
{
	system("CLS");
	cout << "\n\nCongratulations you WON!!!!!!!\n\n" << endl;
	cout << "Your score is: " << gameScore << "\n\n" << endl;
	system("PAUSE");
	saveHighScore(gameScore, difficulty);
	saveFile(difficulty);
	displayAllHighScores(difficulty);
	system("PAUSE");
	menu();
}

void numGuess::saveHighScore(int gameScore, int difficulty)
{
	int tempS, tempD;
	string tempN;
	string name;

	for (int i = 0; i < 61; i++)
	{
		if (arrayOfHighScore[i].score > gameScore)
		{
			system("CLS");
			cout << "\n\n\t\t\t\t\tNEW HIGH SCORE!!!!\n\n\t\tPlease enter name:\n\n";
			cin >> name;
			arrayOfHighScore[60].score = gameScore;
			arrayOfHighScore[60].name = name;
			arrayOfHighScore[60].difficulty = difficulty;
			break;
		}
	}

	for (int i = 0; i < 61; i++)
	{
		for (int j = i + 1; j < 61; j++)
		{

			if (arrayOfHighScore[i].score > arrayOfHighScore[j].score)
			{
				tempS = arrayOfHighScore[i].score;
				tempN = arrayOfHighScore[i].name;
				tempD = arrayOfHighScore[i].difficulty;
				arrayOfHighScore[i].score = arrayOfHighScore[j].score;
				arrayOfHighScore[i].name = arrayOfHighScore[j].name;
				arrayOfHighScore[i].difficulty = arrayOfHighScore[j].difficulty;
				arrayOfHighScore[j].score = tempS;
				arrayOfHighScore[j].name = tempN;
				arrayOfHighScore[j].difficulty = tempD;
			}

		}
	}
}

void numGuess::saveFile(int difficulty)
{
	for (int i = 0; i < 61; i++)
	{
		if (arrayOfHighScore[i].difficulty == 1)
		{
			ofstream myFile(easyFileName, std::fstream::app);
			if (myFile.is_open())
			{

				myFile << arrayOfHighScore[i].name << "\t" << arrayOfHighScore[i].score << endl;

				myFile.close();
			}
			else
			{
				cout << "Unable to open file";
			}
		}
		else if (arrayOfHighScore[i].difficulty == 2)
		{
			ofstream myFile(medFileName, std::fstream::app);
			if (myFile.is_open())
			{

				myFile << arrayOfHighScore[i].name << "\t" << arrayOfHighScore[i].score << endl;

				myFile.close();
			}
			else
			{
				cout << "Unable to open file";
			}
		}
		else if (arrayOfHighScore[i].difficulty == 3)
		{
			ofstream myFile(hardFileName, std::fstream::app);
			if (myFile.is_open())
			{

				myFile << arrayOfHighScore[i].name << "\t" << arrayOfHighScore[i].score << endl;

				myFile.close();
			}
			else
			{
				cout << "Unable to open file";
			}
		}
		else if (arrayOfHighScore[i].difficulty == 4)
		{
			ofstream myFile(broFileName, std::fstream::app);
			if (myFile.is_open())
			{

				myFile << arrayOfHighScore[i].name << "\t" << arrayOfHighScore[i].score << endl;

				myFile.close();
			}
			else
			{
				cout << "Unable to open file";
			}
		}
	}
}

void numGuess::readFile(int difficulty)
{
	system("CLS");

	string tab = "\t";
	string line;


	if (difficulty == 1)
	{
		ifstream myFile(easyFileName);
		if (myFile.is_open())
		{
			for (int i = 0; i < 15; i++)
			{
				getline(myFile, line);
				if (line != "" && i < 15)
				{
					std::size_t pos = line.find(tab);
					string str1 = line.substr(0, (pos));
					string str2 = line.substr(pos);

					arrayOfHighScore[i].name = str1;
					arrayOfHighScore[i].score = stoi(str2);
					arrayOfHighScore[i].difficulty = difficulty;
				}
				else
				{
					arrayOfHighScore[i].name = "NoName";
					arrayOfHighScore[i].score = 99999;
					arrayOfHighScore[i].difficulty = difficulty;
				}

			}
			myFile.close();
		}
		else { cout << "Unable to open easy save file"; }

		cout << "HighScores (EASY)\n" << endl;
		for (int i = 0; i < 15; i++)
		{
			if (arrayOfHighScore[i].difficulty == difficulty)
			{
				if (arrayOfHighScore[i].name == "NoName")
				{
					cout << i + 1 << ") No Entry Here" << endl;
				}
				else
				{
					cout << i + 1 << ") " << arrayOfHighScore[i].name << " - " << arrayOfHighScore[i].score << endl;
				}
			}
		}
	}
	else if (difficulty == 2)
	{
		ifstream myFile(medFileName);
		if (myFile.is_open())
		{
			for (int i = 0; i < 15; i++)
			{
				getline(myFile, line);
				if (line != "" && i < 15)
				{
					std::size_t pos = line.find(tab);
					string str1 = line.substr(0, (pos));
					string str2 = line.substr(pos);

					arrayOfHighScore[i].name = str1;
					arrayOfHighScore[i].score = stoi(str2);
					arrayOfHighScore[i].difficulty = difficulty;
				}
				else
				{
					arrayOfHighScore[i].name = "NoName";
					arrayOfHighScore[i].score = 99999;
					arrayOfHighScore[i].difficulty = difficulty;
				}
			}
			myFile.close();
		}
		else { cout << "Unable to open med save file"; }

		cout << "HighScores (MEDIUM)\n" << endl;
		for (int i = 0; i < 15; i++)
		{
			if (arrayOfHighScore[i].difficulty == difficulty)
			{
				if (arrayOfHighScore[i].name == "NoName")
				{
					cout << i + 1 << ") No Entry Here" << endl;
				}
				else
				{
					cout << i + 1 << ") " << arrayOfHighScore[i].name << " - " << arrayOfHighScore[i].score << endl;
				}
			}
		}
	}
	else if (difficulty == 3)
	{
		ifstream myFile(hardFileName);
		if (myFile.is_open())
		{
			for (int i = 0; i < 15; i++)
			{
				getline(myFile, line);
				if (line != "" && i < 15)
				{
					std::size_t pos = line.find(tab);
					string str1 = line.substr(0, (pos));
					string str2 = line.substr(pos);

					arrayOfHighScore[i].name = str1;
					arrayOfHighScore[i].score = stoi(str2);
					arrayOfHighScore[i].difficulty = difficulty;
				}
				else
				{
					arrayOfHighScore[i].name = "NoName";
					arrayOfHighScore[i].score = 99999;
					arrayOfHighScore[i].difficulty = difficulty;
				}
			}
			myFile.close();
		}
		else { cout << "Unable to open hard save file"; }
		cout << "HighScores (HARD)\n" << endl;
		for (int i = 0; i < 15; i++)
		{
			if (arrayOfHighScore[i].difficulty == difficulty)
			{
				if (arrayOfHighScore[i].name == "NoName")
				{
					cout << i + 1 << ") No Entry Here" << endl;
				}
				else
				{
					cout << i + 1 << ") " << arrayOfHighScore[i].name << " - " << arrayOfHighScore[i].score << endl;
				}
			}
		}
	}
	else if (difficulty == 4)
	{
		ifstream myFile(broFileName);
		if (myFile.is_open())
		{
			for (int i = 0; i < 15; i++)
			{
				getline(myFile, line);
				if (line != "" && i < 15)
				{
					std::size_t pos = line.find(tab);
					string str1 = line.substr(0, (pos));
					string str2 = line.substr(pos);

					arrayOfHighScore[i].name = str1;
					arrayOfHighScore[i].score = stoi(str2);
					arrayOfHighScore[i].difficulty = difficulty;
				}
				else
				{
					arrayOfHighScore[i].name = "NoName";
					arrayOfHighScore[i].score = 99999;
					arrayOfHighScore[i].difficulty = difficulty;
				}
			}
			myFile.close();
		}
		else { cout << "Unable to open impossibro save file"; }
		cout << "HighScores (IMPOSSIBRO)\n" << endl;
		for (int i = 0; i < 15; i++)
		{
			if (arrayOfHighScore[i].difficulty == difficulty)
			{
				if (arrayOfHighScore[i].name == "NoName")
				{
					cout << i + 1 << ") No Entry Here" << endl;
				}
				else
				{
					cout << i + 1 << ") " << arrayOfHighScore[i].name << " - " << arrayOfHighScore[i].score << endl;
				}
			}
		}
	}
}

void numGuess::displayAllHighScores(int difficulty)
{
	int c = 0;
	while (1)
	{
		readFile(difficulty);
		cout << "\n\n\nLEFT and RIGHT ARROW keys to navigate to different Difficulty HighScores\nDOWN ARROW key to go back to the Menu." << endl;
		int c = 0;
		switch ((c = _getch())) {
		case 75: // LEFT ARROW
			readFile(difficulty);
			cout << "\n\n\nLEFT and RIGHT ARROW keys to navigate to different Difficulty HighScores\nDOWN ARROW key to go back to the Menu." << endl;
			if (difficulty > 1)
			{
				difficulty--;
			}
			break;
		case 77: // RIGHT ARROW
			readFile(difficulty);
			cout << "\n\n\nLEFT and RIGHT ARROW keys to navigate to different Difficulty HighScores\nDOWN ARROW key to go back to the Menu." << endl;
			if (difficulty < 4)
			{
				difficulty++;
			}
			break;
		case 80:
			menu();
			break;
		}
	}
}

void numGuess::exitGame()
{
	system("CLS");

	cout << "Are you sure you want to EXIT the game?\n1 to EXIT, 0 to STAY" << endl;
	cin >> choice;
	if (choice == 1)
	{
		exit(1);
	}
	else
	{
		menu();
	}
}
