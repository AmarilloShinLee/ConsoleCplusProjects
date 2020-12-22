#include "differentDataInput.h"
#include <iostream>

using namespace std;

void DataInput()
{
	int theNumber;
	char theCharacter;
	float theDecimalNumber;

	cout << "Name:\tGabriel Alpha A. Aguilar";
	cout << "\nCourse:\tBSIT 1 - B\n";
	cout << "\n\t\tWelcome to Input Prompt: Data Type Edition!\n";
	cout << "\nEnter any number, any decimal number, and any character in order on the keyboard: \n";

	//Inputs
	//The Integer
	cin >> theNumber;
	while (cin.fail())	//If input type is not a numerical value
	{
		cout << "\tThat's not an integer, try again.";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> theDecimalNumber;
	}
	cout << "\t Number inputted!\n";

	//The Float
	cin >> theDecimalNumber;
	while (cin.fail())	//If input type is not a numerical value
	{
		cout << "\tThat's not a floating-point value, try again.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> theDecimalNumber;
	}
	cout << "\t Decimal number inputted!\n";

	//The Character
	cin >> theCharacter;
	cout << "\t Character inputted!\n\n";

	//Output
	cout << "\n\nInteger Entered: \t\t" << theNumber;
	cout << "\nCharacter Entered: \t\t" << theCharacter;
	cout << "\nFloating-point number Entered: \t" << theDecimalNumber;
	cout << "\n\nThank you for using the Input Prompt!\n";
	cout << endl;
}