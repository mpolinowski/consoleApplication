#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // constructor initialize state at BCGame start

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO add return value
	bool CheckGuessValidity(std::string); //TODO provide method to count bulls&cows, and increasing turn number MyCurrentTry

private:
	// see FBullCowGame constructor for initialisation
	int MyCurrentTry;
	int MyMaxTries;
};
