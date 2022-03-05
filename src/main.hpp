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
	int rangeHigh = NULL;
	int amountOfTries = NULL;
	int randNum = NULL;
	int userGuess = NULL;
	std::string gameMode;
	std::string singleplayerGameMode;
	bool guessLoop = NULL;

	enum class difficultyMode
	{
		Easy = 1,
		Normal = 2,
		Hard = 3,
		MEGA = 4
	};

	enum class rangeHigh
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
		Singleplayer = 1,
		Multiplayer = 2
	};

	int singleplayerGame();
	int multiplayerGame();
	void clearScreen();
};

#endif
