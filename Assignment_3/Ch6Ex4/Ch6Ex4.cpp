#include <iostream>
#include <limits>
#include "Ch6Ex4.h"
using namespace std;

/**
Returns gallons of gas dispensed
@return float Gallons
*/
float GasPump::getDispensed()
{
	return dispensed;
}

/**
Sets gallons of gas dispensed to a float
@param d Gallons
*/
void GasPump::setDispensed(float d)
{
	dispensed = d;
}

/**
Returns total cost
@return float Dollars
*/
float GasPump::getPrice()
{
	return price;
}

/**
Sets total cost to a float
@param p Dollars
*/
void GasPump::setPrice(float p)
{
	price = p;
}

/**
Returns dollars per gallon
@return float $/gal
*/
float GasPump::getDollarsPerGal()
{
	return dollars_per_gallon;
}

/**
Sets dollars per gallon to a float
@param d $/gal
*/
void GasPump::setDollarsPerGal(float d)
{
	dollars_per_gallon = d;
}

/**
Displays the number of gallons dispensed
*/
void GasPump::displayDispensed()
{
	cout << "Amount Dispensed: " << dispensed << " gal" << endl;
}

/**
Calculates and displays the total price based on the number of gallons dispensed
*/
void GasPump::displayPrice()
{
	price = dispensed*dollars_per_gallon;
	cout << "Price: $" << price << endl;
}

/**
Prompts the user to select what type of gas they would like to fuel their car with, updating the dollars_per_gallon variable appropriately
*/
void GasPump::selectGas()
{
	cout << "Which gas would you like to use (1-5):" << endl;
	cout << "1) Regular: $2.242/gal" << endl;
	cout << "2) Mid-Grade: $2.572/gal" << endl;
	cout << "3) Premium: $2.830/gal" << endl;
	cout << "4) Diesel: $2.927/gal" << endl;
	cout << "5) E85: $1.988/gal" << endl;
	int ans;
	cin >> ans;
	checkNum(ans);
	switch(ans)
	{
		case(1):
			dollars_per_gallon = 2.242f;
			break;
		case(2):
			dollars_per_gallon = 2.572f;
			break;
		case(3):
			dollars_per_gallon = 2.830f;
			break;
		case(4):
			dollars_per_gallon = 2.927f;
			break;
		default:
			dollars_per_gallon = 1.988f;
	}
}

/**
Resets the pump so that dispensed, price, dollars_per_gallon are all equal to 0
*/
void GasPump::reset()
{
	dispensed = 0.0f;
	price = 0.0f;
	dollars_per_gallon = 0.0f;
}

/**
Increases the number of gallons dispensed by 1 and displays the updated dispensed and price variables until the user decides to stop
*/
void GasPump::dispense()
{
	do
	{
		dispensed++;
		displayDispensed();
		displayPrice();
	} while(!stop());
	cout << "Thank you for stopping by, have a nice day!" << endl;
}

/**
Prompts the user if they would like to add more gas
@return bool False if user wants to add another gallon and true if the user wants to stop adding gas
*/
bool GasPump::stop()
{
	char ans;
	cout << "Add another gallon? (y/n)" << endl;
	cin >> ans;
	if(ans == 'y' || ans == 'Y')
	{
		return false;
	}
	else
	{
		return true;
	}
}

/**
Simulates filling a car 1 time
*/
void GasPump::simulate()
{
	reset();
	selectGas();
	dispense();
}

/**
Determines if parameter is a number as well as in the range specified. If not, asks user for a number until one is inputted.
@param num Variable being checked
*/
void GasPump::checkNum(int& num)
{
	while(!cin || num < 1 || num > 5)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> num;
	}
}
