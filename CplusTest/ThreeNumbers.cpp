#include "ThreeNumbers.h"
#include <iostream>
#include <algorithm>

using namespace std;

int enterNumber();
void readNumbers(int arrayOfNumbers[], int maxArrayLength);
void reverseNumbers(int arrayOfNumbers[], int maxArrayLength);

void theOutput()
{
	const int maxArrayLength = 3;
	int number[maxArrayLength];

	for (int i = 0; i < maxArrayLength; i++)
	{
		number[i] = enterNumber();
	}

	readNumbers(number, maxArrayLength);
	reverseNumbers(number, maxArrayLength);
}
int enterNumber()
{
	int n;

	cout << "Enter number: ";
	cin >> n;

	return n;
}

void readNumbers(int arrayOfNumbers[], int maxArrayLength)
{
	cout << "\nNumbers in Order: \n";

	for (int i = 0; i < maxArrayLength; i++)
	{
		cout << arrayOfNumbers[i] << endl;
	}
}

void reverseNumbers(int arrayOfNumbers[], int maxArrayLength) 
{
	cout << "\nNumbers in Reverse: \n";

	reverse(arrayOfNumbers, arrayOfNumbers + maxArrayLength);

	for (int i = 0; i < maxArrayLength; i++)
	{
		cout << arrayOfNumbers[i] << endl;
	}
}