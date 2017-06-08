// Adding If Loop

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void PrintIntro();
string GetGuessAndPrint();

// entry point of application
int main()
{
	PrintIntro();

	// Loop for the number of turns asking guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		GetGuessAndPrint();
		cout << endl;
	}

	return 0;
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

// get a guess from player
string GetGuessAndPrint()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	cout << "Your guess was: " << Guess << endl;
	cout << endl;

	return Guess;
}