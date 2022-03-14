// JOHN ALEXANDER LE ROUX
// TODO: https://discord.com/channels/331718482485837825/951282415349956638
#include "main.hpp"

MainClass mainClass;

int main(int argc, char* argv[])
{
	/*
	 _____                       _____ _            _   _                 _
	|  __ \                     |_   _| |          | \ | |               | |
	| |  \/_   _  ___  ___ ___    | | | |__   ___  |  \| |_   _ _ __ ___ | |__   ___ _ __
	| | __| | | |/ _ \/ __/ __|   | | | '_ \ / _ \ | . ` | | | | '_ ` _ \| '_ \ / _ \ '__|
	| |_\ \ |_| |  __/\__ \__ \   | | | | | |  __/ | |\  | |_| | | | | | | |_) |  __/ |
	 \____/\__,_|\___||___/___/   \_/ |_| |_|\___| \_| \_/\__,_|_| |_| |_|_.__/ \___|_|
	 https://patorjk.com/software/taag/#p=display&f=Ivrit&t=Guess%20The%20Number%0A

	 _____                            _              _                      _   _
	|  _  |___ ___ ___ ___    ___ ___| |_ ___ ___   | |_ ___    ___ ___ ___| |_|_|___ _ _ ___
	|   __|  _| -_|_ -|_ -|  | -_|   |  _| -_|  _|  |  _| . |  |  _| . |   |  _| |   | | | -_|
	|__|  |_| |___|___|___|  |___|_|_|_| |___|_|    |_| |___|  |___|___|_|_|_| |_|_|_|___|___|
	https://patorjk.com/software/taag/#p=display&f=Rectangles&t=Press%20enter%20to%20continue%0A
	*/
	std::cout << " _____                       _____ _            _   _                 _					   \n";
	std::cout << "|  __ \\                     |_   _| |          | \\ | |               | |				   \n";
	std::cout << "| |  \\/_   _  ___  ___ ___    | | | |__   ___  |  \\| |_   _ _ __ ___ | |__   ___ _ __	   \n";
	std::cout << "| | __| | | |/ _ \\/ __/ __|   | | | '_ \\ / _ \\ | . ` | | | | '_ ` _ \\| '_ \\ / _ \\ '__| \n";
	std::cout << "| |_\\ \\ |_| |  __/\\__ \\__ \\   | | | | | |  __/ | |\\  | |_| | | | | | | |_) |  __/ |	   \n";
	std::cout << " \\____/\\__,_|\\___||___/___/   \\_/ |_| |_|\\___| \\_| \\_/\\__,_|_| |_| |_|_.__/ \\___|_| \n";
	std::cout << '\n';
	std::cout << "                        _____                            _                                   \n";
	std::cout << "                       |  _  |___ ___ ___ ___    ___ ___| |_ ___ ___                         \n";
	std::cout << "                       |   __|  _| -_|_ -|_ -|  | -_|   |  _| -_|  _|                        \n";
	std::cout << "                       |__|  |_| |___|___|___|  |___|_|_|_| |___|_|                          \n";
	std::cout << "                         _                      _   _                                        \n";
	std::cout << "                        | |_ ___    ___ ___ ___| |_|_|___ _ _ ___                            \n";
	std::cout << "                        |  _| . |  |  _| . |   |  _| |   | | | -_|                           \n";
	std::cout << "                        |_| |___|  |___|___|_|_|_| |_|_|_|___|___|                           \n";
	std::getchar();



	while (true)
	{
		mainClass.clearScreen();
		std::cout << "Welcome to Guess The Number Game!\n\n";

		std::cout << "Choose a number: #1 Single player, #2 Multi player, #0 Quit: ";
		std::cin >> mainClass.userInput;
		mainClass.clearScreen();

		switch (static_cast<MainClass::gameModes>(mainClass.userInput))
		{
		case MainClass::gameModes::SinglePlayer: mainClass.singlePlayerGame();
			break;
		case MainClass::gameModes::MultiPlayer: mainClass.multiPlayerGame();
			break;
		default: return 0;
		}
	}
	return 0;
}

void MainClass::singlePlayerGame()
{
	// Get Random Number
	std::random_device dev; // for seeding
	std::default_random_engine gen{ dev() };
	// std::uniform_int_distribution<int> dis{ mainClass.rangeLow, mainClass.rangeHigh };
	// mainClass.randNum = dis(gen);

	while (true)
	{
		std::cout << "Welcome to Guess The Number game single player!\n\n";

		std::cout << "Easy High score: " << "NULL" << " tries Range: " << mainClass.rangeLow << " to: " << static_cast<int>(MainClass::guessRange::Easy) << '\n';
		std::cout << "Normal High score: " << "NULL" << " tries Range: " << mainClass.rangeLow << " to: " << static_cast<int>(MainClass::guessRange::Normal) << '\n';
		std::cout << "Hard High score: " << "NULL" << " tries Range: " << mainClass.rangeLow << " to: " << static_cast<int>(MainClass::guessRange::Hard) << '\n';
		std::cout << "MEGA High score: " << "NULL" << " tries Range: " << mainClass.rangeLow << " to: " << static_cast<int>(MainClass::guessRange::MEGA) << '\n';

		std::cout << "\nChoose a number: #1 Easy, #2 Normal, #3 Hard, #4 MEGA, #0 Back: ";
		std::cin >> mainClass.userInput;


		switch (static_cast<difficultyMode>(mainClass.userInput))
		{
		case difficultyMode::Easy:
			mainClass.rangeHigh = static_cast<int>(MainClass::guessRange::Easy);
			mainClass.singlePlayerDifficulty = "easyMode";
			break;
		case difficultyMode::Normal:
			mainClass.rangeHigh = static_cast<int>(MainClass::guessRange::Normal);
			mainClass.singlePlayerDifficulty = "NormalMode";
			break;
		case difficultyMode::Hard:
			mainClass.rangeHigh = static_cast<int>(MainClass::guessRange::Hard);
			mainClass.singlePlayerDifficulty = "hardMode";
			break;
		case difficultyMode::MEGA:
			mainClass.rangeHigh = static_cast<int>(MainClass::guessRange::MEGA);
			mainClass.singlePlayerDifficulty = "megaMode";
			break;
		default: return;
			break;
		}
		mainClass.amountOfTries = 0;
		mainClass.guessLoop = true;
		std::cout << "\nRange is from " << mainClass.rangeLow << " to " << mainClass.rangeHigh << '\n';

		// Yeah, this is dumb, people might hate this
		std::cout << "Thinking of a number";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << ".\n\n";

		// Get Random Number
		// std::random_device dev; // for seeding
		// std::default_random_engine gen{ dev() };
		std::uniform_int_distribution<int> dis{ mainClass.rangeLow, mainClass.rangeHigh };
		mainClass.randNum = dis(gen);

		while (mainClass.guessLoop == true)
		{
			std::cout << "Guess the number: ";
			std::cin >> mainClass.userGuess;
			mainClass.amountOfTries++;
			if (mainClass.userGuess > mainClass.randNum)
			{
				std::cout << "The number is lower than " << mainClass.userGuess << '\n';
			}
			else if (mainClass.userGuess < mainClass.randNum)
			{
				std::cout << "The number is higher than " << mainClass.userGuess << '\n';
			}
			else
			{
				mainClass.clearScreen();
				std::cout << "Congratulations, the number is " << mainClass.randNum << " you have tried " << mainClass.amountOfTries << " times\n\n";
				mainClass.guessLoop = false;

				/*
				if (mainClass.amountOfTries <= "high score tries" || "high score tries" == 0)
				{
					// Save highscore
				}
				*/
			}
		}
	}
	return;
}

void MainClass::multiPlayerGame()
{
	std::cout << "Sorry, multi player is not ready yet!\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	return;
}

void MainClass::clearScreen()
{
#ifdef _WIN32 // _WIN32 or _WIN64
	system("CLS"); // clear console
#endif
#ifdef __unix__
	system("clear"); // clear console
#endif
#ifdef __APPLE__
	system("clear"); // clear console
#endif
}
