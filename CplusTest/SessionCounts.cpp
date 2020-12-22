#include "SessionCounts.h"
#include <iostream>
#include <iomanip>
#define salesTax 0.0825

using namespace std;

/*Created by: Gabriel Alpha Aguilar*/

//How Content Should Be Printed
void itemList(string itemName, float itemPrice, int itemsSold, float itemTotalPrice)
{
	cout << left << setw(6) << itemsSold; 
	cout << left << setw(20) << itemName; 
	cout << right << setw(10) << fixed << setprecision(2) << itemPrice;
	cout << right << setw(16) << itemTotalPrice;
}

//Calculating Each the Item Quantity and Price
float itemsSold(int numberOfItems, float price)
{
	return numberOfItems * price;
}

void CompanyBill()
{
	//Arrays of Data
	string items[] = { "TV", "VCR", "Remote Controller", "CD Player", "Tape Recorder" };
	float price[] = { 400.00, 220.0, 35.20, 300.00, 150.00 };

	//Calculating Array Size
	const int arrayItemSize = sizeof(items) / sizeof(items[0]);

	//Declared Variables
		//Array size is based on the previous array size
	int itemQuantity[arrayItemSize];
	float itemTotalPrice[arrayItemSize];
	float subTotalSum;
	float subTotalTax;
	float totalAmount;

	//For Permalink Purposes
	subTotalSum = 0;

	//Finding Each Data in the arrays
	for (int i = 1; i <= arrayItemSize; i++)
	{
		cout << "How many " << items[i-1] << "s were sold? ";
		cin >> itemQuantity[i-1];
		while (cin.fail())
		{
			cout << "\tThat's not a numerical value, try again: ";
			cin.clear();
			cin.ignore();
			cin >> itemQuantity[i - 1];
		}

		itemTotalPrice[i - 1] = itemsSold(itemQuantity[i - 1], price[i - 1]);
	}

	cout << endl;

	//The Output
	cout << left << setw(6) << "QTY" << left << setw(20) << "DESCRIPTION" << right << setw(4) << "UNIT PRICE" << setw(16) << "TOTAL PRICE" << endl;
	cout << left << setw(6) << "---" << left << setw(20) << "-----------" << right << setw(4) << "----------" << setw(16) << "-----------" << endl;
	//The Content of the Output
	for (int i = 1; i <= arrayItemSize; i++)
	{
		itemList(items[i - 1], price[i-  1], itemQuantity[i - 1], itemTotalPrice[i - 1]);

		subTotalSum += itemTotalPrice[i - 1];
		subTotalTax = subTotalSum * salesTax;
		totalAmount = subTotalSum + subTotalTax;

		cout << endl;
	}
	cout << setw(36) << "----------" << setw(16) << "-----------" << endl;
	cout << setw(36) << "Subtotal:" << setw(16) << subTotalSum << endl;
	cout << setw(36) << "Taxes:" << setw(16) << subTotalTax << endl;
	cout << setw(36) << "Total:" << setw(16) << totalAmount << endl;
}
