# Unreal Engine Coding Standards

This is a fork of the first section of the [Unreal Course](https://github.com/UnrealCourse) teaching C++ coding standards for the Unreal Game Engine.

The Source Code can be found in [consoleApplication](https://github.com/mpolinowski/consoleApplication)

The following is the commented Course Journal:


### Intro, Notes & Section 2 Assets ###

+ Welcome to the first actual coding video.
+ Why we’re doing this in the IDE only.
+ What you’ll be building, see resources.
+ You’ll learn types, loops, routines, classes.
+ We’ll follow Unreal’s coding style, and re-use.
+ Notes and resources are attached.

### S02 Game Design Document (GDD) ###

+ How much planning should we do?
+ Define the emotional problem the game solves\*
+ Chose concept, rules & requirements.
+ Start to think about the architecture.
+ _Copy_ as much as possible into the code!
+ Document now what may change later.

**Useful Links**
+ \* [McConnell, Steve. _Code Complete._ Microsoft Press 2004. Chapter 3.3](https://www.amazon.com/gp/product/0735619670/)

### How Solutions & Projects Relate ###

+ How projects and solutions relate.
+ Setting up a new command line project.
+ An overview of the structure of our solution.
+ (Adding main.cpp to our project).

### C++ Function Syntax ###

+ The difference between an engine and a library.
+ How this relates to this console application.
+ What is building / compiling code?
+ How the console knows where to find our code.
+ The syntax of a function in C++.
+ Write the minimal C++ program to remove error.
+ Testing our application runs without error.

```cpp
// Standard C++ library automatically included by Visual Studio
#include "stdafx.h"

int main() {
  return 0;
}
```

Created a C++ function "main" in a file "main.cpp" that can be run CTRL+F5 without errors and returns integer 0.

### Using, #include and Namespaces ###

+ **#** represents a “preprocessor directive”.
+ **#include** copies-and-pastes other code.
+ The idea of using library code.
+ Use <> for standard libraries.
+ Use “ “ for files you have created yourself.
+ Notice the namespace icon in autocomplete.
+ Import **iostream** library and use **std** namespace
+ Clean up your code by removing **std::** that is no longer needed

```cpp
#include "stdafx.h"
#include <iostream>

int main()
{
  std::cout << "Welcome to Bulls and Cows" << std::endl;
  return 0;
}
```

By defining the std namespace we can simplify our code:

```cpp
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
  cout << "Welcome to Bulls and Cows" << endl;
  return 0;
}
```

### Magic Numbers and Constants ###

+ What a “magic number” is.
+ Why it’s a good idea to avoid them.
+ **constexpr** means “evaluated at compile time”.
+ Introduce coding standards\*.
+ Use a constant expression for the word length.

```cpp
int main()
{
  // introduce the game
  constexpr int WORD_LENGTH = 9;
  cout << "Welcome to Bulls and Cows" << endl;
  cout << "Can you guess the << WORD_LENGTH;
  cout << " letter isogram I'm thinking of?/n";

  cout << endl;
  return 0;
}
```

There are 2 ways to break to a new line - "endl" and "/n". The latter does not flush the output buffer - otherwise identical.

**Useful Links**
+ \* [Unreal Engine - Coding Standard](https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/index.html)

### Variables and cin for Input ###

+ Introducing pseudocode programming - add a comment to describe the function before you start programming
+ Why we need to **#import \<string\>**
+ Getting input using **cin**
+ cin breaks consuming input at space - you cannot input more then 1 word

```cpp
// string library is needed for the ">>" operator
#include <string>

int main()
{
  // introduce the game
  // ...

  // get a guess from player
  cout << "Enter your guess: ";
  string Guess = "";
  cin >> Guess;

  // return guess to player
  cout << "Your guess was: " << Guess << endl;

  cout << endl;
  return 0;
}
```

### Using getline() ###

+ Solve the problem that you cannot enter a guess with more then one word
+ **getline()** reads through spaces and discards input stream @endl
+ Where to find C++ documentation => www.cplusplus.com

```cpp
int main()
{
  // introduce the game
  // ...

  // get a guess from player
  cout << "Enter your guess: ";
  string Guess = "";
  getline (cin,Guess);

  // return guess to player
  cout << "Your guess was: " << Guess << endl;

  cout << endl;
  return 0;
}
```

### Simplifying With Functions ###

+ Programming is all about managing complexity.
+ We want to think about a few things at a time.
+ The idea of abstraction and encapsulation -> the scope of the constexpr WORD_LENGTH is now limited to the PrintIntro function.
+ Always use **return** at the end of your functions.

+ Wrap the code Intro code into function to make our code more readable.
+ The PrintIntro() then be called from within main()

*PrintIntro* function:

```cpp
void PrintIntro()
  {
    // introduce the game
    constexpr int WORD_LENGTH = 9;
    cout << "Welcome to Bulls and Cows" << endl;
    cout << "Can you guess the << WORD_LENGTH;
    cout << " letter isogram I'm thinking of?/n";
    cout << endl;
    return;
  }

  //Entry point of application
  int main()
  {
    // introduce the game
    PrintIntro ();

    // get a guess from player
    // ...

    // return guess to player
    // ...

    return 0;
  }
```

The collection of functions used by main() should be at the end of the document. We have to put the identifier for the function PrintIntro() on top of the document. This way we can put the body PrintIntro(){} below main()

```cpp
void PrintIntro():

//Entry point of application
int main()
{
  // introduce the game
  PrintIntro ();

  // get a guess from player
  // ...

  // return guess to player
  // ...

  return 0;
}

void PrintIntro()
  {
    // introduce the game
    constexpr int WORD_LENGTH = 9;
    cout << "Welcome to Bulls and Cows" << endl;
    cout << "Can you guess the << WORD_LENGTH;
    cout << " letter isogram I'm thinking of?/n";
    cout << endl;
    return;
  }
```

This makes it easy to spot main() inside the document. Descriptive identifier for each function inside main() make our code readable / **self-documenting**

Repeat this process with all other functions inside main():

```cpp
void PrintIntro():
string GetGuessAndPrintBack();

//Entry point of application
int main()
{
  PrintIntro ();
  GetGuessAndPrintBack ();
  return 0;
}

// introduce the game
void PrintIntro() {...}

// get a guess from player and print back
string GetGuessAndPrintBack()
{
  cout << "Enter your guess: ";
  string Guess = "";
  getline(cin, Guess);
  //print guess back to player
  cout << "Your guess was: " << Guess << endl;
  return Guess;
}
```


### Iterating With For & While Loops ###

+ Use loops to prevent typing the same code repeatedly
+ When to use **for** vs **while** -> "When you know what you in **FOR**" / "When you are looping for a **WHILE**" -> use for-loop when you know the number of loops at compile time.
+ The syntax of a for-loop: **for** (**Initialization**: count = 1; **Condition**: count <= limit; **Increase**: count = count +1) {**Statement**}
+ Think carefully about the first & last loop.
+ Write a **for** loop to repeat the game.

```cpp
int main()
{
  // introduce the game
  PrintIntro ();

  // get a guess from player and loop for number of turns
  constexpr int NUMBER_OF_TURNS = 5;

  for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		GetGuessAndPrintBack();
    cout << endl;
	}

  return 0;
}
```

**Useful Links**
+ \* [www.cplusplus.com](http://www.cplusplus.com/doc/tutorial/control)
+ \* [msdn.microsoft.com](https://msdn.microsoft.com/en-us/library/b80153d8.aspx)

### Clarity is Worth Fighting For ###

+ More about levels of abstraction.
+ A word on being clever.
+ Using Visual Studio’s Extract “Extract Function”
+ What a header file (.h) is.
+ What’s refactoring, and why we do it.
+ Removing side-effects.
+ Where to find the course code. [UnrealCourse](http://www.unrealcourse.com/) & [Github.com](https://github.com/UnrealCourse)

Encapsulate for-loop in PlayGame() to clean up main():

```cpp
void PrintIntro();
void PlayGame():
string GetGuessAndPrintBack();

int main()
{
  PrintIntro ();
  PlayGame ();

  return 0; //Exit application
}

void PlayGame()
{
  // get a guess from player and loop for number of turns
  constexpr int NUMBER_OF_TURNS = 5;
  for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		GetGuessAndPrintBack();
    cout << endl;
	}
}
```

All functions should only do one thing - removing PrintBack from GetGuess:

```cpp
void PlayGame()
{
  // get a guess from player and loop for number of turns
  constexpr int NUMBER_OF_TURNS = 5;
  for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		GetGuess();
    string Guess = GetGuess();
    cout << "Your guess was: " << Guess << endl;
	}
}

string GetGuess()
{
  cout << "Enter your guess: ";
  string Guess = "";
  getline(cin, Guess);
  return Guess;
}
```
To rename all instances of a function identifier in VisualStudio, select it and press **CTRL+R** twice!

### Booleans and comparisons ###

+ What a boolean is, and how to use it.
+ Only use when completely clear what you mean.
+ Use **==** for comparison.
+ Use **&&** for logical AND.
+ Use **||** for logical OR.
+ Use **[n]** to access a string, starting at n=0.
+ Use **‘ ‘** for characters, and **“ “** for strings.

Add true/false boolean for asking to restart the game after a completed run.

```cpp
void PrintIntro();
void PlayGame():
string GetGuessAndPrintBack();
bool AskToPlayAgain();

int main()
{
  PrintIntro ();
  PlayGame ();
  AskToPlayAgain();

  return 0; //Exit application
}

bool AskToPlayAgain()
{
  cout << "Do you want to play again? y/n ";
  string Response = "";
  getline(cin, Response);

  return (Response[0] == 'y') || (Response[0] = 'Y');
}
```

Response[0] takes the first character from the Response string. Compare to character y/Y and return true or false.

### Using do and while in C++ ###

+ A **do while** loop is: do {code to repeat} while (condition);
+ A do/while code is always executed at least once and repeated until the condition is reached.
+ Making our game play multiple times.

```cpp
int main()
{
  bool bPlayAgain = false;

  do
  {
    PrintIntro ();
    PlayGame ();
    bPlayAgain = AskToPlayAgain();
  }

  while (bPlayAgain);

  return 0;
}
```

The boolean bPlayAgain is set to **false** at the beginning of the loop - AskToPlayAgain sets it to **true** if player types "yes".
The do/while loop is repeated until while is set to false.

### Introducing Classes ###

+ Lookup the Turing machine.
+ A quick overview of the MVC pattern.
+ User defined types (classes).
+ About working at an interface level (black box).
+ An overview of class **FBullCowGame**

### Using Header Files as Contracts ###

+ Introducing .h header files in C++.
+ Why the added complexity is worth it.
+ Defining the interface to our class.
+ Writing our first draft of FBullCowGame.

```cpp
#pragma once
#include <string>

class FBullCowGame
{
public:
  void Reset();
  int GetMaxTries();
  int GetCurrentTry();
  bool IsGameWon();
  bool CheckGuessValidity(std::string);

private:
  int MyCurrentTry;
  int MyMaxTries;
}
```

### Including Our Own Header File ###

+ NEVER use using namespace in a .h
+ In fact, why use it at all?
+ Create your .cpp files and **#include**
+ Don’t create chains of includes.

Remove **using namespace std;** from main.cpp - add std:: to all instances of cout, cin, string, endl, getline

Add *.cpp file to header - select void Reset(); right-click it, choose Quick-Action and Create Definition - this creates FBullCowGame.cpp. Repeat this for all methods in header file:

```cpp
#include FBullCowGame.h

void FBullCowGame::Reset()
{
  return;
}

int FBullCowGame::GetCurrentTry()
{
  return 0;
}

int FBullCowGame::GetMaxTries()
{
  return 0;
}

bool FBullCowGame::IsGameWon()
{
  return false,
}

void FBullCowGame::CheckGuessValidity(std::string)
{
  return false;
}
```

### Instantiating Your Class ###

+ Relax, they’re just user defined types!
+ string FirstName; creates a string object
+ FBullCowGame BCGame; works the same way
+ These instances are initialised by “constructors”
+ Instantiating means “creating an instance of”
+ So we’re simply creating a FBullCowGame game instance "BCGame".

```cpp
#include "FBullCowGame.h"

int main()
{...}

void PlayGame()
{
  FBullCowGame BCGame;

  constexpr int NUMBER_OF_TURNS = 5;
  for (int i = 0; i < NUMBER_OF_TURNS; i++)
  {
    std::string Guess = GetGuess();
    std::cout << "Your guess was: " << Guess << std::endl;
    std::cout << std::endl;
  }
}
```

### Writing & Using Getter Methods ###

+ Use GetMaxTries to GET number of turns / maxTries
+ Why we never access variables directly
+ How to call a method using the dot operator
+ Pros and cons of initializing in at compile time
+ Using “Rebuild Project” to make VS behave!

Initialize MyMaxTries/MyCurrentTry in FBullCowGame.h at compile time (will later be moved into constructor):

**FBullCowGame.h**
```cpp
class FBullCowGame {
public: ...
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
```

Use GetMaxTries/GetCurrentTry Method to access MyMaxTries/MyCurrentTry:

**FBullCowGame.cpp**
```cpp
int FBullCowGame::GetMaxTries() { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() { return MyCurrentTry; }
```

Move the game Instantiating outside of the scope of PlayGame();, so the game instance becomes globally available to all following methods
Use MyMaxTries in main.cpp instead of adding the "magic number" NUMBER_OF_TURNS.
Add MyCurrentTry in GetGuss();

**main.cpp**
```cpp
FBullCowGame BCGame;

int main()
{...}

void PlayGame()
{

  BCGame.GetMaxTries();

  int MaxTries = BCGame.GetMaxTries();
  for (int i = 0; i < MaxTries; i++)
  {
    std::string Guess = GetGuess();
    std::cout << "Your guess was: " << Guess << std::endl;
    std::cout << std::endl;
  }
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}
```

### Introducing the Const Keyword ###

+ **const**’s meaning depends on context
+ Generally means “I promise not to change this”
+ What this is depends on exactly where it appears
+ At the end of a member function, for example **int GetCurrentTry() const;** it prevents the function from modifying any member variables
+ This is a good safety feature.

By adding const at the end of a member function of a class, the variable is set at **compile time** and cannot be changed by the member function at **runtime** -> changing value of MyMaxTries = 12 somewhere inside the class member function will now result in an Error: int FBullCowGame::GetMaxTries() const { MyMaxTries = 12; return MyMaxTries; }

**FBullCowGame.h**
```cpp
int GetMaxTries() const;
int GetCurrentTry() const;
bool IsGameWon() const;
```

**FBullCowGame.cpp**
```cpp
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}
```

### Constructors For Initialisation ###

+ Default constructor called when object created
+ Initialize in constructor when decided at runtime
+ Initialize in declaration if known at compile time
+ Constructor syntax simply: **ClassName()**;
+ Set the member variables in constructor
+ Test this has worked.

Add constructor function to headerfile and move private variable Initialization to constructor in FBullCowGame.cpp - before they were initialized at compile time. the constructor now initializes them at runtime. Adding private: int MyCurrentTry = 666; in headerfile will now be overwritten by constructor at runtime!

**FBullCowGame.h**
```cpp
class FBullCowGame {
public:
	FBullCowGame(); // constructor initialize state at BCGame
  ...
private:
  // see FBullCowGame constructor for initialization
  int MyCurrentTry;
	int MyMaxTries;
}
```

**FBullCowGame.cpp**
```cpp
FBullCowGame::FBullCowGame() // constructor initialize state at BCGame start
{
  int MyCurrentTry = 1;
	int MyMaxTries = 5;
}
```

MyCurrentTry and MyMaxTries are now no longer set at compile time - can be BCGame.Reset() at the end of a game to allow the player to play again:

**main.cpp**
```cpp
void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking guesses
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}
```

The constructor should also just call the Reset() and set the runtime default values:

**FBullCowGame.cpp**
```cpp
FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 5;

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	return;
}
```

### Pseudocode Programming ###

+ More on Pseudocode Programming Practice (PPP)
+ Reviewing our code and architecture
+ Using **// TODO** as a comment prefix
+ Introducing Visual Studio’s Task List: View/Task List -> all your TODOs show up in that list
+ Planning our next wave of coding.

**main.cpp**
```cpp
void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking guesses
	// TODO change from for- to while-loop once we use try validation
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = GetGuess(); // TODO make loop check validity

		// submit only valid guesses to the game
		// print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	// TODO Summarize game
}
```

### Using using for Type Aliases ###

+ We’re substituting types to be “Unreal ready”
+ The declaration is **using \<alias\> = \<type\>;**
+ For example **using int32 = int;**
+ Why Unreal uses **int32** rather than **int**
+ **FText** is for output, **FString** is “mutable”
+ Where to use each type of string
+ Map **FText** and **FString** to **std::string**

### Using struct for Simple Types ###

+ **struct** is almost identical to **class**
+ It’s member variables (data) is public by default
+ Ideal for simple value types like **BullCowCount**
+ Outline **BullCowCount SubmitGuess(FString)**

### Using if Statements in C++ ###

+ Why we need conditionals (selection)
+ Use **if** when it reads better (e.g. few conditions)
+ Use **switch** for multiple, simple conditions
+ (for loads of statements consider a table lookup)
+ The syntax of an **if** statement
+ Using **if** to write count bulls and cows.

### Debugging 101 ###

+ A very brief intro to Visual Studio’s debugger
+ Set a break-point by clicking in margin
+ Watch values by highlighting in debug mode
+ Use “Continue” to cycle back to breakpoint.

### A Place for Everything ###

+ Centralising the hidden word length
+ Making this a property of the game class
+ Writing a getter to access this value
+ Updating our intro to vary with word length.

### Introducing enumerations ###

+ An **enum**erated type consists of named values
+ Use instead of coded meaning
+ Makes the code more readable and meaningful
+ Only defined values can be used - more robust
+ A benefit of C++ 11’s strongly typed enums
+ Creating an **enum class** for error checking.

### Writing Error Checking Code ###

+ Use **else if** for the first time
+ Outline or **CheckGuessValidity()** method
+ Write working code for checking guess length
+ Use the debugger to test the return values.

### Using switch Statements ###

+ Use our error values to communicate with user
+ All our user interaction is via **GameManager.cpp**
+ We’ll use **FText** in this file, as it’s UI text
+ We can “switch” what we say based on the error
+ The syntax of a **switch** statement
+ Remember your **break** keywords!

### Warm Fuzzy Feelings ###

+ _Don’t_ get comfortable with compiler warnings
+ Refactor **GetValidGuess()** to remove warning
+ Rename **SubmitGuess()** to **SubmitValidGuess()**
+ Improve readability of **SubmitValidGuess()**
+ Get a warm fuzzy feeling!

### Handling Game Win Condition ###

+ Change our **PlayGame()** loop to a **while**
+ Implement our **IsGameWon()** function

### Win or Lose "Screen" ###

Write a method to print a game summary to the screen once the game is over.

### Introducing Big O Notation ###

+ Algorithm: the recipe for solving a problem
+ or: 45th US Vice President’s dance style
+ Introducing the complexity of algorithms
+ A quick introduction to “Big O” notation
+ Comparing three ways of checking for isograms.

### TMap and map Data Structures ###

+ The importance of knowing your data types
+ Introducing the **std::map** data type
+ **#define TMap std::map** to keep it ‘Unreal’
+ How we’ll be using the map
+ **TMap\<char, bool\> LetterSeen;** to declare
+ Using **LetterSeen[Letter]** to access
+ Wiring-up and pseudocoding **IsIsogram()**

### Range-based for Loop ###

+ Introducing containers and iterators
+ Using a range-based for loop in Unreal\*
+ Gently introducing the auto keyword
+ Finishing our IsIsogram()

**Useful Links**

+ \* [Unreal Engine - Ranged Based For Loops](https://www.unrealengine.com/blog/ranged-based-for-loops)

### Design a Helper Function ###

+ Gain confidence with a multi-stage challenge
+ A word on implicit dependencies

### Playtesting Your Game ###

+ Having someone else play test your game is vital
+ Silently take notes, or record screen if possible
+ Immediately go away and fix obvious bugs
+ For improvements consider 2nd or 3rd opinion
+ Repeat until the bug / issue rate plateaus.

### Difficulty & Play Tuning ###

+ About the flow channel\*
+ **map** word length to max tries
+ Play test to determine correct difficulty.

**Useful Links**

+ \* Read more in [Sylvester, T. Designing Games - O’Reilly](https://www.amazon.com/dp/B00AWKX1FO/)

### Polishing & Packaging ###

+ First impressions count (think reviews)
+ Don’t ship a half-baked product, even if digital
+ Check through your code (polish)
+ Ship to your customers (package).

### Section 2 Wrap-Up ###

+ HUGE congratulations on your progress
+ Over 5 hours of pure C++ learning
+ Over 30 challenges you’ve completed
+ The journey has only just begun
+ Share your source code for others to play
+ Here are some suggested improvements
+ Next we take the game logic into Unreal :-)
