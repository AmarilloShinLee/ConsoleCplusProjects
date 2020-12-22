#include "TheCalculator.h"
#include <iostream>

using namespace std;

int theNumber(int index);
int Addition(int numbers[]);
int Subtraction(int numbers[]);
int Multiplication(int numbers[]);
int Division(int numbers[]);

void CalculatorOutput() 
{
	const int numbersMaxArray = 2;
	int numbers[numbersMaxArray];					//The data are arranged in a decreasing manner
	int sum, difference, product, quotient;
	int operationChoice;

	for (int index = 0; index < numbersMaxArray; index++)
	{
		numbers[index] = theNumber(index);
	}

	cout << "\nDo wish to...\n\t1. Add?\n\t2. Subtract?\n\t3. Multiply?\n\t4. Divide?\n";
	cout << "Enter your choice in numbers: ";
	cin >> operationChoice;

	switch (operationChoice)
	{
	case 1:
		sum = Addition(numbers);
		break;
	case 2:
		difference = Subtraction(numbers);
		break;
	case 3:
		product = Multiplication(numbers);
		break;
	case 4:
		quotient = Division(numbers);
		break;
	default:
		cout << "That is not part of the choices. Try again later.\n";
		break;
	}
}
//Reading data function
int theNumber(int index)
{
	int numbers;

	if (index == 0)
	{
		cout << "Enter a number: ";
	}
	else
	{
		cout << "Enter another number: ";
	}
	cin >> numbers;

	return numbers;
}
//The Operations
int Addition(int numbers[]) 
{
	int sum;
	sum = numbers[0] + numbers[1];

	cout << "You chose: Add.\n";
	cout << "\nThe sum of " << numbers[0] << " and " << numbers[1] << " is: " << sum << endl;

	return sum;
}
int Subtraction(int numbers[])
{
	int difference;
	difference = numbers[0] - numbers[1];

	cout << "\nYou chose: Subtract.\n";
	cout << "\nThe difference of " << numbers[0] << " and " << numbers[1] << " is: " << difference;
	cout << "\nWhere:\n\t" << numbers[0] << " is the Subtrahend.\n\t" << numbers[1] << " is the Minuend.\n";

	return difference;
}
int Multiplication(int numbers[])
{
	int product;
	product = numbers[0] * numbers[1];

	cout << "\nYou chose: Multiply.\n";
	cout << "The product of " << numbers[0] << " and " << numbers[1] << " is: " << product;

	return product;
}
int Division(int numbers[])
{
	int quotient, remainder;

	quotient = numbers[0] / numbers[1];
	remainder = numbers[0] % numbers[1];

	cout << "\nYou chose: Divide.\n\nThe quotient of " << numbers[0] << " and " << numbers[1] << " is: " << quotient << endl;

	if (remainder == 0)
	{
		cout << "There is no remainder." << endl;
	}
	else
	{
		cout << "\tThe remainder is " << remainder << endl;
	}
	cout << "\nWhere:\n\t" << numbers[0] << " is the Dividend.\n\t" << numbers[1] << " is the Divisor.\n";

	return quotient;
}

