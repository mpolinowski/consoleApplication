#pragma once
#include <string>

// make code Unreal coding standard complient
using FString = std::string;
using int32 = int;

//All values initialized to Zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows =  0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor initialize state at BCGame start

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	// counts bulls&cows, and increasing try number MyCurrentTry - assuming valid guess
	FBullCowCount SubmitValidGuess(FString);

private:
	// see FBullCowGame constructor for initialisation
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};
