#include "ReverseArrangment.h"
#include <iostream>
#include <algorithm>

using namespace std;

void theMethod()
{
	const int MaxNumbers = 3;
	int numbers[MaxNumbers];
	int comparison;

	//Heading
	cout << "Name:\t\tGabriel Alpha A. Aguilar";
	cout << "\nCourse:\t\tBSIT 1 - B";
	cout << "\nActivity No.: \t3\n";
	cout << "\n\t\tWelcome to Input Prompt: Reverse Psychology Edition!\n";

	//Reverse Input
	cout << "Enter " << MaxNumbers << " numbers: \n";
	for (int i = 0; i < MaxNumbers; i++)
	{
		cout << "\t";
		cin >> numbers[i];
		//If input type is not a numerical value
		while (cin.fail())
		{
			cout << "\tThat's not an integer, try again.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numbers[i];
		}
	}

	comparison = sizeof(numbers) / sizeof(numbers[0]);	//Getting size of array to the first number
	reverse(numbers, numbers + comparison);				//Reverse method in C++ library

	//Reverse Output
	cout << "\nThe numbers in reversed positions are: \n";
	for (int i = 0; i < MaxNumbers; i++)
	{
		cout << "\t" << numbers[i] << "\n";
	}
	
	cout << "\nThank you for using Input Prompt: Reverse Psychology Edition!\n";
}