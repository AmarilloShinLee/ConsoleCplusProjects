#include "BankLoanProject.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#define arraySize 3

using namespace std;

//Main Variables
double numbers[arraySize]; 
double IM, P, Q, monthlyPayment;
double totalCalculatedMonthlyInterest;
int month, year;

//Function Declarations
double calculateMonthlyPayment(double amount, double interestPerYear);
double userInput();
string monthChecker(int monthNumber);
void amortizationTable();
void printInformation();

void zeOutput()
{
	//Time Classes
	tm atTheMoment;
	__time64_t typeTime;
	errno_t rightThisMoment;

	//Time Functions
	_time64(&typeTime);
	rightThisMoment = _localtime64_s(&atTheMoment, &typeTime);

	//Assigning Variables
	month = 1 + atTheMoment.tm_mon;
	year = 1900 + atTheMoment.tm_year;
	totalCalculatedMonthlyInterest = 0;

	//Input
	for (int i = 0; i < arraySize; i++)
	{
		switch (i)
		{
		case 0:
			cout << "Mortgage amount:\t\t";
			break;
		case 1:
			cout << "Interest rate per year (%):\t";
			break;
		case 2:
			cout << "Mortgage term in years:\t\t";
			break;
		}
		numbers[i] = userInput();
	}

	//Output and calculations
	monthlyPayment = calculateMonthlyPayment(numbers[0], numbers[1]);
	cout << endl;
	amortizationTable();
	cout << endl;
	printInformation();

	cout << endl;
}

double userInput()
{
	double input;

	cin >> input;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\tError, not a number. Please try again:\t";
		cin >> input;
	}

	return input;
}
double calculateMonthlyPayment(double amount, double interestPerYear)
{
	numbers[2] *= 12;
	IM = (interestPerYear / 12) / 100;
	P = pow(1 + IM, numbers[2]);
	Q = P / (P - 1);

	return amount * IM * fabs(Q);
}
string monthChecker(int monthNumber)
{
	switch (monthNumber)
	{
	case 1:
		return "Jan ";
		break;
	case 2:
		return "Feb ";
		break;
	case 3:
		return "Mar ";
		break;
	case 4:
		return "Apr ";
		break;
	case 5:
		return "May ";
		break;
	case 6:
		return "Jun ";
		break;
	case 7:
		return "Jul ";
		break;
	case 8:
		return "Aug ";
		break;
	case 9:
		return "Sep ";
		break;
	case 10:
		return "Oct ";
		break;
	case 11:
		return "Nov ";
		break;
	case 12:
		++year;
		return "Dec ";
		break;
	}
}
void amortizationTable()
{
	double balance = numbers[0];

	cout << "AMORTIZATION TABLE\n";
	cout << "---------------------------------------------------------------------------------------\n";
	cout << left << setw(14) << "Month" << setw(14) << "Payment" << setw(8) << "Principal Payment" << right << setw(12) << "Interest" << setw(16) << "Total Interest" << setw(15) << "Balance\n";
	cout << left << setw(14) << "-----" << setw(14) << "-------" << setw(8) << "-----------------" << right << setw(12) << "--------" << setw(16) << "--------------" << setw(15) << "-------\n";
	for (int i = 1; i <= numbers[2]; i++)
	{
		double monthlyPaymentOutputContainer = monthlyPayment;
		double calculatedMonthlyInterest = balance * IM;

		totalCalculatedMonthlyInterest += calculatedMonthlyInterest;
		monthlyPaymentOutputContainer -= calculatedMonthlyInterest;
		balance -= monthlyPaymentOutputContainer;

		cout << monthChecker(month) << year << fixed << setprecision(2) << right << setfill(' ') << setw(13) << monthlyPayment << right << setw(24) << monthlyPaymentOutputContainer << right << setw(12) << calculatedMonthlyInterest << right << setw(16) << totalCalculatedMonthlyInterest << right << setw(14) << balance << endl;
		month++;

		if (!(month <= 12))
			month = 1;
	}
}
void printInformation()
{
	cout << "SUMMARY OF INFORMATION\n" << "------------------------------\n";
	cout << "Monthly Payment:" << right << setfill(' ') << setw(14) << monthlyPayment << endl;
	cout << "Total Interest Paid:" << right << setfill(' ') << setw(10) << totalCalculatedMonthlyInterest << endl;
	cout << "Total Amount Paid:" << right << setfill(' ') << setw(12) << numbers[0] + totalCalculatedMonthlyInterest << endl;
}