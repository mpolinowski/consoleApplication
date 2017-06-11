#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // constructor initialize state at BCGame start

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO add return value
	bool CheckGuessValidity(std::string);

private:
	// see FBullCowGame constructor for initialisation
	int MyCurrentTry;
	int MyMaxTries;
};