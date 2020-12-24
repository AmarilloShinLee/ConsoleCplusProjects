#include "BankLoanProject.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

//Main Variables
double numbers[3]; 
double IM, P, Q, monthlyPayment, calculatedMonthlyInterest;
double totalCalculatedMonthlyInterest = 0;

//Function Declarations
double calculateMonthlyPayment(double amount, double interestPerYear);
double userInput();
string monthChecker(int monthNumber);
void amortizationTable();
void printInformation();

void zeOutput()
{
	tm atTheMoment;
	__time64_t typeTime;
	errno_t rightThisMoment;

	_time64(&typeTime);
	rightThisMoment = _localtime64_s(&atTheMoment, &typeTime);

	//Input
	cout << "Mortgage amount:\t\t";
	numbers[0] = userInput();

	cout << "Interest rate per year (%):\t";
	numbers[1] = userInput();

	cout << "Mortgage term in years:\t\t";
	numbers[2] = userInput();

	//Output and calculations
	monthlyPayment = calculateMonthlyPayment(numbers[0], numbers[1]);
	cout << endl;
	amortizationTable();
	cout << endl;
	printInformation();

	cout << endl;
	//Printing the Date today
	//cout << "Month and Year Today:\t\t" << monthChecker(atTheMoment.tm_mon + 1) << " " << (1900 + atTheMoment.tm_year) << endl;
}

double userInput()
{
	double input;

	cin >> input;		//Changing this

	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\tError, not a number. Please try again:\n\t";
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

void amortizationTable()
{
	double balance = numbers[0];

	cout << left << setw(14) << "Month" << setw(14) << "Payment" << setw(8) << "Principal Payment" << right << setw(12) << "Interest" << setw(16) << "Total Interest" << setw(14) << "Balance" << endl;
	cout << left << setw(14) << "-----" << setw(14) << "-------" << setw(8) << "-----------------" << right << setw(12) << "--------" << setw(16) << "--------------" << setw(14) << "-------" << endl;
	for (int i = 1; i <= numbers[2]; i++)
	{
		double monthlyPaymentOutputContainer = monthlyPayment;

		calculatedMonthlyInterest = balance * IM;

		totalCalculatedMonthlyInterest += calculatedMonthlyInterest;
		monthlyPaymentOutputContainer -= calculatedMonthlyInterest;

		balance -= monthlyPaymentOutputContainer;

		cout << "Month " << right << setfill('0') << setw(2) << i << fixed << setprecision(2) << right << setfill(' ') << setw(13) << monthlyPayment << right << setw(24) << monthlyPaymentOutputContainer << right << setw(12) << calculatedMonthlyInterest << right << setw(16) << totalCalculatedMonthlyInterest << right << setw(14) << balance << endl;
	}
}

string monthChecker(int monthNumber)
{
	switch (monthNumber)
	{
	case 1:
		return "Jan";
		break;
	case 2:
		return "Feb";
		break;
	case 3:
		return "Mar";
		break;
	case 4:
		return "Apr";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "Jun";
		break;
	case 7:
		return "Jul";
		break;
	case 8:
		return "Aug";
		break;
	case 9:
		return "Sep";
		break;
	case 10:
		return "Oct";
		break;
	case 11:
		return "Nov";
		break;
	case 12:
		return "Dec";
		break;
	default:
		return "Invalid Month number";
		break;
	}
} //Deal with this tomorrow

void printInformation()
{
	cout << "SUMMARY OF INFORMATION\n" << "----------------------\n";
	cout << "Monthly Payment:" << right << setfill(' ') << setw(14) << monthlyPayment << endl;
	cout << "Total Interest Paid:" << right << setfill(' ') << setw(10) << totalCalculatedMonthlyInterest << endl;
	cout << "Total Amount Paid:" << right << setfill(' ') << setw(12) << numbers[0] + totalCalculatedMonthlyInterest << endl;
}