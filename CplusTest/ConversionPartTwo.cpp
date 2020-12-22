#include "ConversionPartTwo.h"
#include <iostream>
#include <string>
#define ft 12
#define yd 36
#define cm 2.54
#define m 39.37

using namespace std;

void ConversionFunction(float measurement)
{
	cout << endl;

	string choice;
	string feetLabel, yardLabel, centimeterLabel, meterLabel;
	float feet, yards, centimeters, meters;
	bool endWhile = false;

	feetLabel = "Feet";
	yardLabel = "Yards";
	centimeterLabel = "Centimeters";
	meterLabel = "Meters";

	cout << "Do you wish to convert it into " << feetLabel << ", " << yardLabel << ", " << centimeterLabel << ", " << meterLabel << "? ";
	
	while (endWhile == false)
	{
		//getline(cin, choice);
		cin >> choice;

		if (choice == feetLabel || choice == "feet")
		{
			feet = measurement / ft;
			cout << feetLabel << ":\t" << feet;
			endWhile = true;
		}
		else if (choice == yardLabel || choice == "yards")
		{
			yards = measurement / yd;
			cout << yardLabel << ":\t" << yards;
			endWhile = true;
		}
		else if (choice == centimeterLabel || choice == "centimeters")
		{
			centimeters = measurement / cm;
			cout << centimeterLabel << ":\t" << centimeters;
			endWhile = true;
		}
		else if (choice == meterLabel || choice == "meters")
		{
			meters = measurement / m;
			cout << meterLabel << ":\t" << meters;
			endWhile = true;
		}
		else
		{
			cout << "\tThat is not part of the choices, try again: ";
		}
	}

	cout << endl;
}

void Conversion()
{
	float inchMeasurement;
	char choice;
	bool endWhile = false;

	string inchLabel[] = { "inch", "inches" };

	cout << "Enter measurement in inches: ";
	cin >> inchMeasurement;
	while (cin.fail())
	{
		cout << "\tThat is not a numerical value, try again: ";
		cin.clear();
		cin.ignore();
		cin >> inchMeasurement;
	}

	cout << endl;

	cout << "Data Entered: \t";
	if (inchMeasurement == 1 || inchMeasurement == 0 || inchMeasurement == -1)
	{
		cout << inchMeasurement << " " << inchLabel[0] << endl;
	}
	else
	{
		cout << inchMeasurement << " " << inchLabel[1] << endl;
	}

	cout << endl;

	cout << "Do you wish to convert your measurement? Y/N: ";	
	while (endWhile == false)
	{
		cin >> choice;

		switch (choice)
		{
		case 'Y':
		case 'y':
			ConversionFunction(inchMeasurement);
			endWhile = true;
			break;
		case 'N':
		case 'n':
			endWhile = true;
			break;
		default:
			cout << "\tNot part of the choices, try again: ";
			break;
		}
	}

	cout << endl << "Thank you for using the Conversion System." << endl;
}