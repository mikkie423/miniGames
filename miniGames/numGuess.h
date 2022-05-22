#include <iostream>
using namespace std;
#pragma once

class HighScore
{
public:
	string name = "NoName";
	int score = 9999;
	int difficulty = 0;
};

class numGuess
{
public:
	int levelPicker();
	int generateNumber(int difficulty);
	void menu();
	void instructions();
	void startGame();
	//void displayHighScores(int difficulty);
	void displayAllHighScores(int difficulty);
	void exitGame();
	void saveHighScore(int gameScore, int difficulty);
	int gameLoop();
	void winScreen();
	void saveFile(int difficulty);
	void readFile(int difficulty);
	int randNum = 0;
	int choice = 0;
	int difficulty = 0;
	int guess = 0;
	int gameScore = 0;//running total in-game
	const char* easyFileName = "SaveFiles/ngEasy.txt";
	const char* medFileName = "SaveFiles/ngMed.txt";
	const char* hardFileName = "SaveFiles/ngHard.txt";
	const char* broFileName = "SaveFiles/ngBro.txt";
	HighScore arrayOfHighScore[61];
};
