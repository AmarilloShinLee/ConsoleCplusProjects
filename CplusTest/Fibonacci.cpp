#include "Fibonacci.h"
#include <iostream>

using namespace std;

int fib1 = 0;
int fib2 = 1;
int fib3 = 0;
string spacing = ",   ";

//Calculating series length
void Length(int numberLength)
{
	cout << "\nOutput:\n";
	for (int i = 1; i <= numberLength; i++)
	{
		switch (i)
		{
			case 1:
				cout << fib1 << spacing;
				continue;
			case 2:
				cout << fib2 << spacing;
				continue;
		}
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;

		cout << fib3 << spacing;
	}
}

//Computer series from Max Number
void Max(int maxNum)
{
	cout << "\nOutput:\n";
	cout << fib1 << spacing << fib2 << spacing;
	fib3 = fib1 + fib2;
	while (fib3 <= maxNum)
	{
		cout << fib3 << spacing;

		fib1 = fib2;
		fib2 = fib3;
		fib3 = fib1 + fib2;
	}
}

void FibonacciNumbers()
{
	int choice;				//User choice
	int seriesLength;		//length of series
	int seriesMax;			//Number that the series reach
	bool endWhile = false;	//boolean of not ending until User choose proper choice

	//The Output
	cout << "Do you wish to:\n";
	cout << "\t1. Enter the length of the series?\n\t2.Enter the maximum number for the series?\n";
	cout << "Please choose between the two numbers.\n";
	cout << "User Choice: ";
	
	while (endWhile == false)
	{
		cin >> choice;
		while (cin.fail())
		{
			cout << "\tThat is not a numerical value, try again: ";
			cin.clear();
			cin.ignore();
			cin >> choice;
		}
		switch (choice)
		{
			case 1:
				cout << endl << "Mode: Series Length" << endl;
				cout << "Enter a number: ";
				cin >> seriesLength;
				Length(seriesLength);
				endWhile = true;
			break;
			case 2:
				cout << endl << "Mode: Series Max" << endl;
				cout << "Enter a number: ";
				cin >> seriesMax;
				Max(seriesMax);
				endWhile = true;
			break;
			default:
			cout << "That's not part of the choices, try again: ";
			break;
		}
	}
	cout << "...";
	cout << endl;

	//Code Summarized
	//Original Code at https://www.programiz.com/cpp-programming/examples/fibonacci-series
}