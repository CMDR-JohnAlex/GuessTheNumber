// JOHN ALEXANDER LE ROUX
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
		std::cin >> mainClass.nUserInput;
		mainClass.clearScreen();

		switch (static_cast<MainClass::eGameModes>(mainClass.nUserInput))
		{
		case MainClass::eGameModes::SinglePlayer:
			mainClass.singlePlayerGame();
			break;
		case MainClass::eGameModes::MultiPlayer:
			mainClass.multiPlayerGame();
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}

int MainClass::singlePlayerGame()
{
	while (true)
	{
		std::cout << "Welcome to Guess The Number game single player!\n\n";

		std::cout << "Easy High score: " << NULL << " tries Range: " << mainClass.nRangeLow << " to: " << static_cast<int>(MainClass::eRangeHigh::Easy) << '\n';
		std::cout << "Normal High score: " << NULL << " tries Range: " << mainClass.nRangeLow << " to: " << static_cast<int>(MainClass::eRangeHigh::Normal) << '\n';
		std::cout << "Hard High score: " << NULL << " tries Range: " << mainClass.nRangeLow << " to: " << static_cast<int>(MainClass::eRangeHigh::Hard) << '\n';
		std::cout << "MEGA High score: " << NULL << " tries Range: " << mainClass.nRangeLow << " to: " << static_cast<int>(MainClass::eRangeHigh::MEGA) << '\n';

		std::cout << "\nChoose a number: #1 Easy, #2 Normal, #3 Hard, #4 MEGA, #0 Back: ";
		std::cin >> mainClass.nUserInput;


		switch (static_cast<MainClass::eDifficultyMode>(mainClass.nUserInput))
		{
		case MainClass::eDifficultyMode::Easy:
			mainClass.nRangeHigh = static_cast<int>(MainClass::eRangeHigh::Easy);
			mainClass.sSinglePlayerDifficulty = "easyMode";
			break;
		case MainClass::eDifficultyMode::Normal:
			mainClass.nRangeHigh = static_cast<int>(MainClass::eRangeHigh::Normal);
			mainClass.sSinglePlayerDifficulty = "NormalMode";
			break;
		case MainClass::eDifficultyMode::Hard:
			mainClass.nRangeHigh = static_cast<int>(MainClass::eRangeHigh::Hard);
			mainClass.sSinglePlayerDifficulty = "hardMode";
			break;
		case MainClass::eDifficultyMode::MEGA:
			mainClass.nRangeHigh = static_cast<int>(MainClass::eRangeHigh::MEGA);
			mainClass.sSinglePlayerDifficulty = "megaMode";
			break;
		default:
			return 0;
			break;
		}
		mainClass.nAmountOfTries = 0;
		mainClass.bGuessLoop = true;
		std::cout << "\nRange is from " << mainClass.nRangeLow << " to " << mainClass.nRangeHigh << '\n';

		// Yeah, this is dumb, people might hate this
		std::cout << "Thinking of a number";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << ".\n\n";

		// Get Random Number
		std::random_device dev; // for seeding
		std::default_random_engine gen{ dev() };
		std::uniform_int_distribution<int> dis{ mainClass.nRangeLow, mainClass.nRangeHigh };
		mainClass.nRandNum = dis(gen);

		while (mainClass.bGuessLoop == true)
		{
			std::cout << "Guess the number: ";
			std::cin >> mainClass.nUserGuess;
			mainClass.nAmountOfTries++;
			if (mainClass.nUserGuess > mainClass.nRandNum)
			{
				std::cout << "The number is lower than " << mainClass.nUserGuess << '\n';
			}
			else if (mainClass.nUserGuess < mainClass.nRandNum)
			{
				std::cout << "The number is higher than " << mainClass.nUserGuess << '\n';
			}
			else
			{
				mainClass.clearScreen();
				std::cout << "Congratulations, the number is " << mainClass.nRandNum << " you have tried " << mainClass.nAmountOfTries << " times\n\n";
				mainClass.bGuessLoop = false;

				/*
				if (mainClass.amountOfTries <= "high score tries" || "high score tries" == 0)
				{
					// Save highscore
				}
				*/
			}
		}
	}
	return 0;
}

int MainClass::multiPlayerGame()
{
	std::cout << "Sorry, multi player is not ready yet!\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	return 0;
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
