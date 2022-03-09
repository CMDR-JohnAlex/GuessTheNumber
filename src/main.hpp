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
	int nRangeLow = 1;
	int nRangeHigh = NULL;
	int nRandNum = NULL;
	int nUserGuess = NULL;
	int nAmountOfTries = NULL;
	std::string sSingleplayerDifficulty = NULL;
	bool bGuessLoop = NULL;
	std::string gameMode;

	enum class eDifficultyMode
	{
		Easy = 1,
		Normal = 2,
		Hard = 3,
		MEGA = 4
	};

	enum class eRangeHigh
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
	int nUserInput = NULL;
	
	enum class eGameModes
	{
		Singleplayer = 1,
		Multiplayer = 2
	};

	int singleplayerGame();
	int multiplayerGame();
	void clearScreen();
};

#endif
