/* This is the console executeable that makes use of the BullCow class
This acts as the view in a MVC pattern and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

// Console Application Game - Training for Unreal Engine Coding Standards

#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// make code Unreal coding standard complient
using FText = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSumary();

// Instantiate a new Game
FBullCowGame BCGame;

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
	std::cout << "\n\n Welcome to Bulls and Cows\n";
	std::cout << " Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter lower case isogram I'am thinking of??\n";
	std::cout << std::endl;
	return;
}

// Plays a game instance to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking guesses while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// submit only valid guesses to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << " Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	
	PrintGameSumary();
	return;
}

// loop continually until user gives valid guess
FText GetValidGuess()
{
	FText Guess = ""; // initialize guess variable
	EGuessStatus Status = EGuessStatus::Invalid; // Default set validity to invalid
	do
	{
		// get a guess from player
		int32 CurrentTry = BCGame.GetCurrentTry();
		int32 MaxTries = BCGame.GetMaxTries();
		std::cout << " Try " << CurrentTry << " / " << MaxTries << ": Enter your guess: ";
		std::getline(std::cin, Guess); // change value of Guess to user input

		// check validity
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << " Please only enter " << BCGame.GetHiddenWordLength() << " letter words.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << " Please only enter words without repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << " Please only use lower case character.\n\n";
			break;
		default:
			// assume guess is valid if not caught by EGuessStatus exception
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until guess is valid

	return Guess;
}

void PrintGameSumary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << " Well done! You are a Princess!";
	}
	else {
		std::cout << " Rotten Luck!";
	}
}

bool AskToPlayAgain()
{
	std::cout << " Want to try again? y/n \n";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
