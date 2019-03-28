#include <iostream>
#include <limits>
#include "Ch7Ex3.h"
using namespace std;

/**
Constructor for class Counter that assigns max value to a number
@param m Max
*/
Counter::Counter(int m)
{
	max = m;
}

/**
Returns the max the counter can go up to
@return int Max
*/
int Counter::getMax()
{
	return max;
}

/**
Sets the max to a numebr
@param m Max
*/
void Counter::setMax(int m)
{
	max = m;
}

/**
Returns the number the counter is currently on
@return int Count
*/
int Counter::getCount()
{
	return count;
}

/**
Sets the count to a numebr
@param c Count
*/
void Counter::setCount(int c)
{
	count = c;
}

/**
Resets count to 0
*/
void Counter::reset()
{
	count = 0;
}

/**
Increments count by 1
*/
void Counter::incr1()
{
	count++;
}

/**
Increments count by 10
*/
void Counter::incr10()
{
	count += 10;
}

/**
Increments count by 100
*/
void Counter::incr100()
{
	count += 100;
}

/**
Increments count by 1000
*/
void Counter::incr1000()
{
	count += 1000;
}

/**
Determines if the count is greater than max
@return bool True if count has exceeded max
*/
bool Counter::overflow()
{
	if(count > max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
Simulates the counter, allowing the user to input whether they would like to increment (pennies, dimes, dollars, or tens of dollars), check overflow, reset, or exit.
*/
void Counter::simulate()
{
	char choice;
	int num;
	do
	{
		cout << "\nPlease enter whether you would like to increment by pennies ('a'), dimes ('s'), dollars ('d'), or tens of dollars ('f')." << endl;
		cout << "You can also type 'o' to check overflow, 'r' to reset, or 'e' to exit." << endl;
		cin >> choice;
		checkChar(choice);
		if(choice != 'o' && choice != 'e' && choice != 'r')
		{
			cout << "Please enter by how much you would like to increment by (1-9):" << endl;
			cin >> num;
			checkNum(num);
		}
		if(choice == 'a')
		{
			for(int x = 0; x < num; x++)
			{
				incr1();
			}
		}
		else if(choice == 's')
		{
			for(int x = 0; x < num; x++)
			{
				incr10();
			}
		}
		else if(choice == 'd')
		{
			for(int x = 0; x < num; x++)
			{
				incr100();
			}
		}
		else if(choice == 'f')
		{
			for(int x = 0; x < num; x++)
			{
				incr1000();
			}
		}
		else if(choice == 'r')
		{
			reset();
		}
		cout << endl;
		if((overflow() || choice == 'o') && choice != 'e')
		{
			if(overflow())
			{
				cout << "WARNING: OVERFLOW DETECTED" << endl;
				cout << "Max: " << max << endl;
			}
			else
			{
				cout << "No overflow detected" << endl;
			}
		}
		cout << "Current Count: " << count << endl;
	} while(choice != 'e');
	cout << "\nThanks for stopping by, have a nice day!\n" << endl;
}

/**
Determines if parameter is a character as well as in the range specified. If not, asks user for a character until one is inputted.
@param c Variable being checked
*/
void Counter::checkChar(char& c)
{
	while(!cin || (c != 'a' && c != 's' && c != 'd' && c != 'f' && c != 'o' && c != 'e' && c != 'r'))
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid character:" << endl;
		cin >> c;
	}
}

/**
Determines if parameter is a number as well as in the range specified. If not, asks user for a number until one is inputted.
@param num Variable being checked
*/
void Counter::checkNum(int& num)
{
	while(!cin || num < 1 || num > 9)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> num;
	}
}

/**
Determines if the max value is greater than 0 and is a valid input
@param max Max value
*/
void checkMax(int& max)
{
	while(!cin || max < 0)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> max;
	}
}
