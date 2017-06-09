// Adding If Loop

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// entry point of application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();

	} while (bPlayAgain);

	return 0; // Exit Application
}

//  introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'am thinking of??\n";
	cout << endl;
	return;
}

// Loop for the number of turns asking guesses
void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

// get a guess from player
string GetGuess()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Want to play again? y/n\n";
	string Response = "";
	getline(cin, Response);
	cout << endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}