#include <iostream>
#include <cstdlib>
#include <string>
#include "GuessingGame.h"

using namespace std;

string difficultyMode;

bool gameFunctioning = true;
bool playAgain = false;
bool playGame = false;
bool difficultyChoice = false;
bool startGame = false;
string difficultyLabels[] = { "Easy", "Meduim", "Hard" };
int difficultyNumbers[] = {25, 50, 100};

string userChoice_Validation();
bool checkInput_GuessGame(string input);
bool gameMechanics(int goalNumber, int userAnswer);
void difficultyFunction(string difficultyMode);

int GuessingGameMain()
{
	srand((unsigned) time(NULL));

	int guesses;
	int userChoice, userAnswer;
	int randomNumber;
	int maxNumber;

	userChoice = 0;

	cout
		<< "\t\tWelcome to Guess the Number!\n\n"
		<< "\t1. Play\n"
		<< "\t2. Exit\n";

	while (playGame == false)
	{
		try
		{
			userChoice = stoi(userChoice_Validation());
			if (userChoice < 0)
				throw 505;
		}
		catch (...)
		{
			continue;
		}

		switch (userChoice)
		{
		case 1:
			playGame = true;
			break;
		case 2:
			gameFunctioning = false;
			playGame = true;
			break;
		default:
			cout << "\tInput is not part of the choices. Please try again.\n";
			break;
		}
	}
	cout << flush;
	system("CLS");

	while (gameFunctioning == true)
	{
		playAgain = false;

		//Choosing Difficulty
		cout
			<< "Mechanics:\n"
			<< "\t- You must guess the number generated by the computer based on the difficulty you choose.\n"
			<< "\t- The computer will count the number of your guesses after you guessed the number.\n"
			<< "\t- The computer will give you hints when you guess the wrong number.\n"
			<< "\n\tNote: You may quit by typing '110' while playing\n"
			<< "\n\t\tHave fun!\n\n" << flush;
		system("PAUSE");
		system("CLS");

		cout
			<< "Difficulty:\n"
			<< "\t1. " << difficultyLabels[0] << " (1 to 25)\n"
			<< "\t2. " << difficultyLabels[1] << " (1 to 50)\n"
			<< "\t3. " << difficultyLabels[2] << " (1 to 100)\n";

		while (difficultyChoice == false)
		{
			try
			{
				userChoice = stoi(userChoice_Validation());
				if (userChoice < 0)
					throw 505;
			}
			catch (...)
			{
				continue;
			}

			switch (userChoice)
			{
			case 1:
				difficultyMode = difficultyLabels[0];
				maxNumber = difficultyNumbers[0];

				randomNumber = (rand() % maxNumber) + 1;
				difficultyFunction(difficultyMode);
				break;
			case 2:

				difficultyMode = difficultyLabels[1];
				maxNumber = difficultyNumbers[1];

				randomNumber = (rand() % maxNumber) + 1;
				difficultyFunction(difficultyMode);
				break;
			case 3:
				difficultyMode = difficultyLabels[2];
				maxNumber = difficultyNumbers[2];

				randomNumber = (rand() % maxNumber) + 1;
				difficultyFunction(difficultyMode);
				break;
			default:
				cout << "\tInput is not part of the choices. Please try again\n";
				break;
			}
		}
		cout << flush;
		system("CLS");

		//Game starts
		cout << "\tGuess the Number!\n";
		for (guesses = 0; guesses >= 0; guesses++)
		{
			try
			{
				userAnswer = stoi(userChoice_Validation());
				if (userChoice < 0)
					throw 505;
			}
			catch (...)
			{
				continue;
			}

			//Exit Code
			if (userAnswer == 110)
				break;
			//When answer is beyond 100 but not the exit code
			if (userAnswer > maxNumber + 1)
				cout << "\t\t" << userAnswer << " is beyond the maximum difficulty number.\n";
			else if (userAnswer < 0)
				cout << "\t\t" << userAnswer << " is below the minimum difficulty number.\n";
			else
				startGame = gameMechanics(randomNumber, userAnswer);
			//When number is correct
			if (startGame == false)
				break;
		}
		cout << flush;
		system("PAUSE");
		system("CLS");

		cout
			<< "\nNumber of Guesses: " << guesses << endl;

		cout
			<< "Would you like to play again?\n"
			<< "\t1. Yes\n"
			<< "\t2. No\n";

		while (playAgain == false)
		{
			try
			{
				userAnswer = stoi(userChoice_Validation());
				if (userChoice < 0)
					throw 505;
			}
			catch (...)
			{
				continue;
			}

			switch (userChoice)
			{
			case 1:
				playAgain = true;
				difficultyChoice = false;
				break;
			case 2:
				playAgain = true;
				gameFunctioning = false;
				break;
			default:
				cout << "\tInput is not part of the choices. Please try again\n";
				break;
			}
		}
	}
	cout << flush;
	system("CLS");

	cout 
		<< "\n\tThank you for playing Guess the Number!"
		<< "\n\tHave a Good day!\n";

	return 0;
}

string userChoice_Validation()
{
	bool validationMistake = true;
	string input;

	while (validationMistake == true && input.empty())
	{
		cout << "Input: ";
		getline(cin, input);

		if (checkInput_GuessGame(input))
			validationMistake = false;
		else
			cout << "\tInput is not a number. Please try again.\n";

	}

	return input;
}
bool checkInput_GuessGame(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]) == false)
			return false;
		return true;
	}
}
bool gameMechanics(int goalNumber, int userAnswer)
{
	if (userAnswer == goalNumber)
	{
		cout << "\n\t\t" << userAnswer << " is correct!\n";
		return false;
	}
	else
	{
		cout << "\t\t" << userAnswer << " is not the number!\n";
		if (userAnswer > goalNumber)
			cout << "\t\tThe number is smaller than " << userAnswer << endl;
		else if (userAnswer < goalNumber)
			cout << "\t\tThe number is larger than " << userAnswer << endl;
	}
	return true;
}
void difficultyFunction(string difficultyMode)
{
	cout << "\nDifficulty: " << difficultyMode << endl;
	difficultyChoice = true;
	startGame = true;
}