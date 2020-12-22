#include "BankLoanProject.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float roundUpPayMent(float zePayment);

void zeOutput()
{
	//Notes:
	//House cleaning
	//Created the nested loop

	//Basic Variables
	float numbers[3];

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
	IM = (numbers[1] / 12) / 100;
	P = pow(1 + IM, numbers[2]);
	Q = P / (P - 1);
	monthlyPayment = numbers[0] * IM * fabs(Q);

	cout << endl;

	//Output
	cout << "\nPrincipal: $" << numbers[0];
	cout << "\nInterest Rate: " << IM;
	cout << "\nMonths: " << numbers[2];
	cout << "\nP:\t" << P;
	cout << "\nQ:\t" << Q;

	cout << endl;

	//Assuming this is the 1st Month (Open this after the nested loop debug)
	cout << "\nMonthly Payment:\t" << monthlyPayment;
	cout << "\nRounded Payment:\t" << roundUpPayMent(monthlyPayment);
	cout << "\nPrincipal (Monthly):\t" << monthlyPayment - (numbers[0] * IM);
	cout << "\nModified Principal:\t" << numbers[0] - (monthlyPayment - (numbers[0] * IM));

	cout << "\n\n";



	cout << "\n\n";

	cout << left << setw(14) << "Month" << setw(14) << "Payment" << setw(8) << "Principal Payment" << right << setw(12) << "Interest" << setw(16) << "Total Interest" << setw(14) << "Balance" << endl;
	for (int i = 1; i <= numbers[2]; i++)
	{
		float monthlyPaymentContainer = roundUpPayMent(monthlyPayment);

		calculatedMonthlyInterest = numbers[0] * IM;

		totalCalculatedMonthlyInterest += calculatedMonthlyInterest;
		monthlyPaymentContainer -= calculatedMonthlyInterest;
		numbers[0] -= monthlyPaymentContainer;

		cout << "Month " << right << setfill('0') << setw(2) << i;
		cout << fixed << setprecision(2);
		cout << right << setfill(' ') << setw(13) << monthlyPayment;
		cout << right << setw(24) << monthlyPaymentContainer;
		cout << right << setw(12) << calculatedMonthlyInterest;
		cout << right << setw(16) << totalCalculatedMonthlyInterest;
		cout << right << setw(14) << numbers[0];
		cout << endl;
	}

	cout << endl;

	//Date
}

float roundUpPayMent(float zePayment)
{
	float saidValue = (int)(zePayment * 100 + .5);
	return (float)saidValue / 100;
}