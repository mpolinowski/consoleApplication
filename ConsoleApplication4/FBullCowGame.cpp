#include "stdafx.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() // constructor initialize state of BCGame on runtime start
{
	Reset();
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 5;

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
