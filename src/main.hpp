// JOHN ALEXANDER LE ROUX
#ifndef MAIN_HPP
#define MAIN_HPP
// User-Defined Headers

// 3rd Party Library Headers

// Standard Library Headers
#include <iostream>
#include <random>
#include <chrono>
#include <thread>

class MainClass
{
private:
	// Private Variables/Functions
	// Private members of a class A are not accessible outside of A's code, or from the code of any class derived from A.
	int rangeLow = 1;
	int rangeHigh = 0;
	int amountOfTries = 0;
	int randNum = 0;
	int userGuess = 0;
	std::string singlePlayerDifficulty;
	bool guessLoop = false;

	enum class difficultyMode
	{
		Easy = 1,
		Normal = 2,
		Hard = 3,
		MEGA = 4
	};

	enum class guessRange
	{
		Easy = 10,
		Normal = 100,
		Hard = 10000,
		MEGA = std::numeric_limits<std::int32_t>::max()
	};

protected:
	// Protected Variables/Functions
	// Protected members of a class A are not accessible outside of A's code, but is accessible from the code of any class derived from A.
public:
	// Public Variables/Functions
	// Public members of a class A are accessible for all and everyone.
	int userInput = NULL;


	enum class gameModes
	{
		SinglePlayer = 1,
		MultiPlayer = 2
	};

	void singlePlayerGame();
	void multiPlayerGame();
	void clearScreen();
};

#endif
