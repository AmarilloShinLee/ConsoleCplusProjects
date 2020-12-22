#include "ParkingLotConsole.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string vehicles[] = {"Bus", "Car", "Truck"};

bool stringIsInteger(string s);
string inputChecker(string codeWord);
string vehicleType(string&);
float vehicleTypeCharge(string vehicleType, int&);
void TimeTotal(int dataTotal[], string data[]);
void isMinuteExceed(string dataNumber[], int dataPosition);
void estimateFunction(int dataTotal[], string Mode);

void Output()
{
	string inputData[5];									//The required object
	int totalTime[2];										//The total time

	for (int i = 0; i < 5; i++)
	{
		string preWord;

		if (i == 0)
			cout << "Type of Vehicle:\t\t";	//i = 0
		else
		{
			if (i % 2 == 0)
				preWord = "Minutes";	//2
			else
				preWord = "Hours";		//1

			if (i < 3)
				cout << preWord << " vehicle entered lot:\t";	
			else
			{
				if (preWord == "Hours")
					cout << preWord << " vehicle left lot:\t\t";
				else
					cout << preWord << " vehicle left lot:\t";
			}
		}

		inputData[i] = inputChecker(preWord);					//Check if input is string or integer

		while (stringIsInteger(inputData[i]) && i == 0)			//Check if the first iteration is a character or not
		{
			cout << "\tError : Character is not a letter. Try again: \t";
			inputData[i] = inputChecker(preWord);
		}
	}

	inputData[0] = vehicleType(inputData[0]);
	TimeTotal(totalTime, inputData);

	for (int i = 2; i < 5; i *= 2)								//If input minute exceed 60 minutes
		isMinuteExceed(inputData, i);

	cout << "\nTYPE OF VEHICLE" << right << setw(23) << inputData[0] << endl;
	for (int i = 1; i < 3; i++)
	{

		if (i == 1)
			cout << "TIME IN ";
		else
		{
			cout << "TIME OUT";
			i++;
		}
		cout << right << setfill(' ') << setw(23) << "" << setfill('0') << setw(2) << inputData[i] << " : " << setfill('0') << setw(2) << inputData[i + 1] << endl;
	}
	cout << right << setfill(' ') << setw(38) << "--------";

	estimateFunction(totalTime, "Exceed");						//If minutes exceed 0 and 60

	if (totalTime[0] < 0)										//If car is parked beyond midnight
	{
		cout << endl;
		cout << right << setfill(' ') << setw(38) << "TOWED\n";
		exit(1);
	}

	cout << "\nPARKING TIME" << setw(19) << "" << setfill('0') << setw(2) << totalTime[0] << " : " << setfill('0') << setw(2) << totalTime[1];

	estimateFunction(totalTime, "Estimate");					//Estimate hour

	cout << "\nROUNDED TIME" << setfill(' ') << setw(26) << totalTime[0] << endl;
	cout << right << setfill(' ') << setw(38) << "--------";

	cout << "\nTOTAL CHARGE:" << right << setfill(' ') << setw(20) << "$" << fixed << setprecision(2) << vehicleTypeCharge(inputData[0], totalTime[0]) << endl;
}

//If string is an integer
bool stringIsInteger(string s)
{
	for (int i = 0; i <= s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;
		else
			return true;
}

//Calculating Vehicle Type Charge
float vehicleTypeCharge(string vehicleType, int& estimateHour)
{
	float totalCharge = 0;

	switch (toupper(vehicleType[0]))
	{
	case 'C':
		if (estimateHour <= 3)
			totalCharge = (float)estimateHour * 0;
		else
			totalCharge = (float)estimateHour * 1.5;
		break;
	case 'B':
		if (estimateHour <= 2)
			totalCharge = (float)estimateHour * 1.0;
		else
			totalCharge = (float)estimateHour * 2.3;
		break;
	case 'T':
		if (estimateHour <= 1)
			totalCharge = (float)estimateHour * 2.0;
		else
			totalCharge = (float)estimateHour * 3.7;
		break;
	}

	return totalCharge;
}

//Universal Input with Checker
string inputChecker(string codeWord)
{
	int numInput;
	string input;

	cin >> input;

	if (stringIsInteger(input))
	{
		numInput = stoi(input);

		while (numInput < 0 || numInput > 24 && codeWord == "Hours")
		{
			cout << "\tError : Data is beyond 24 hours. Try again:\t";
			cin >> input;
			numInput = stoi(input);
		}

		while (numInput < 0 || numInput > 60 && codeWord == "Minutes")
		{
			cout << "\tError : Data  is beyond 60 minutes. Try again:\t";
			cin >> input;
			numInput = stoi(input);
		}
	}
	else
	{
		while (input.length() > 1)
		{
			cout << "\tToo many characters. Try again:\t";
			cin >> input;
		}
	}

	return input;
}

//Vehicle Type function
string vehicleType(string& input)
{
	switch (toupper(input[0]))
	{
	case 'B':
		input = vehicles[0];
		break;
	case 'C':
		input = vehicles[1];
		break;
	case 'T':
		input = vehicles[2];
		break;
	default:
		break;
	}

	return input;
}

//Calculating total time
void TimeTotal(int dataTotal[], string data[])
{
	for (int i = 0; i < 2; i++)
		dataTotal[i] = stoi(data[i + 3]) - stoi(data[i + 1]);
}

//If input minute exceeds 60
void isMinuteExceed(string dataNumber[], int dataPosition)
{
	if (stoi(dataNumber[dataPosition]) >= 60)
	{
		int HourIn, MinuteIn;

		HourIn = stoi(dataNumber[dataPosition - 1]);
		MinuteIn = stoi(dataNumber[dataPosition]) % 60;

		dataNumber[dataPosition - 1] = to_string(++HourIn);
		dataNumber[dataPosition] = to_string(MinuteIn);
	}
}

//Estimate or if minute exceeds 60 minutes
void estimateFunction(int dataTotal[], string Mode)
{
	if (Mode == "Exceed")
	{
		if (dataTotal[1] < 0)
		{
			dataTotal[0]--;
			dataTotal[1] += 60;
		}
		else if (dataTotal[1] > 60)
		{
			dataTotal[0]++;
			dataTotal[1] -= 60;
		}
	}

	else if (Mode == "Estimate")
	{
		if (dataTotal[1] >= 30)
			++dataTotal[0];
	}
}