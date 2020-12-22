#include "AreaOfCircle.h"
#include <iostream>

using namespace std;

string exactAngle(int angle)
{
	string axis;
	switch (angle)
	{
	case 0:
		axis = "positive X-Axis";
		break;
	case 90:
		axis = "positive Y-Axis";
		break;
	case 180:
		axis = "negative X-Axis";
		break;
	case 270:
		axis = "negative Y-Axis";
		break;
	}
	return "The angle lies at the " + axis;
}

string Angle(float angle)
{
	string quadrant;

	if (angle > 0 && angle < 90)
		quadrant = "I";
	else if (angle > 90 && angle < 180)
		quadrant = "II";
	else if (angle > 180 && angle < 270)
		quadrant = "III";
	else if (angle > 270 && angle < 360)
		quadrant = "IV";
	else
		quadrant = "-- Woah there, you are entering in the Trigonometry zone.";
	return "The angle lies at Quadrant " + quadrant;
}

void coordinates()
{
	float angle;
	string quadrant;
	string axis;

	cout << "Enter an angle in degrees: ";
	cin >> angle;

	cout << endl;

	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;

	if ((int)angle % 90 == 0)
		cout << exactAngle((int)angle);
	else
		cout << Angle(angle);

	cout << endl;
}