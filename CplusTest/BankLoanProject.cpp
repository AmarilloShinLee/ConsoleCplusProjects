#include "BankLoanProject.h"
#include <iostream>
#include <cmath>

using namespace std;

void zeOutput()
{
	//Notes:
	//House cleaning
	//Put this in a GitHub repo
	//Created the nested loop

	//Basic Variables
	int numbers[3];

	float IM;
	float P;
	float Q;
	float monthlyPayment;
	float calculatedMonthlyInterest; 
	float totalCalculatedMonthlyInterest = 0;

	//Input
	cout << "Mortgage amount:\t";
	cin >> numbers[0];

	cout << "Interest rate per year (%):\t";
	cin >> numbers[1];

	cout << "Mortgage term in years:\t";
	cin >> numbers[2];

	//Calculations
	numbers[2] *= 12;
	IM = ((float)numbers[1] / 12) / 100;
	P = pow(1 + IM, numbers[2]);
	Q = P / (P - 1);
	monthlyPayment = numbers[0] * IM * fabs(Q);

	calculatedMonthlyInterest = numbers[0] * IM;
	totalCalculatedMonthlyInterest += calculatedMonthlyInterest;

	cout << endl;

	//Output
	cout << "\nPrincipal: $" << numbers[0];
	cout << "\nInterest Rate: " << IM;
	cout << "\nMonths: " << numbers[2];
	cout << "\nP:\t" << P;
	cout << "\nQ:\t" << Q;

	cout << endl;

	//Assuming this is the 1st Month
	cout << "\nMonthly Payment:\t" << monthlyPayment;
	cout << "\nInterest (January):\t" << calculatedMonthlyInterest;
	cout << "\nTotal Interest:\t" << totalCalculatedMonthlyInterest;
	cout << "\nPrincipal (Monthly):\t" << monthlyPayment - (numbers[0] * IM);
	cout << "\nModified Principal:\t" << numbers[0] - (monthlyPayment - (numbers[0] * IM));

	cout << endl;

	//Date
}

