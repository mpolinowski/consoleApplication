#pragma once

#include "stdafx.h"
#include "FBullCowGame.h"
#include <map>

// make code Unreal coding standard complient
#define TMap std::map

FBullCowGame::FBullCowGame() // constructor initialize state of BCGame on runtime start
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} }; // Set how many tries depending on hidden word length
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "plane"; // this MUST be an isogram with 3-7 lower case letters
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) // if the guess isn't all lower case
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else // otherwise
	{
		return EGuessStatus::OK;
	}
}

// receives valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// increment try number
	MyCurrentTry++;

	FBullCowCount BullCowCount;
	int32 WordLength = GetHiddenWordLength(); // assuming hidden word length == guess word length

	// loop through all letters in HiddenWord
	for (int32 i = 0; i < WordLength; i++)
	{
		// loop through all letters in Guess and compare against the HiddenWord
		for (int32 j = 0; j < WordLength; j++)
		{
		
			// if they match then
			if (Guess[j] == MyHiddenWord[i])
			{
				// if they are in the same place
				if (i == j)
				{
					BullCowCount.Bulls++; // increment bulls
				}
				else
				{
					BullCowCount.Cows++; // increment cows
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter word as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // setup a map to check if letters are used more then once inside the word
	for (auto Letter : Word) // for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case
		
		if (LetterSeen[Letter]) { // if the letter is in the map
			return false; // we DONT have an isogram
		}
		else // otherwise
		{
			LetterSeen[Letter] = true; // add letter to map
		}
	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	// treat 0 and 1 letter word as lowercase
	if (Word.length() <= 1) { return true; }

	for (auto Letter : Word) // for all letters of the word
	{
		if (!islower(Letter)) // if not a lowercase letter

		return false;
	}

	return true;
}
