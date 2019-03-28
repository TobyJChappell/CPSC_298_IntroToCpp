#include <iostream>
#include "Ch6Ex2.h"
using namespace std;

/**
Sets count to a number
@param c Nonegative integer
*/
void CounterType::setCount(int c)
{
	count = c;
}

/**
Returns the variable count
@return int Count
*/
int CounterType::getCount()
{
	return count;
}

/**
Increases the count by 1
*/
void CounterType::increment()
{
	count++;
}

/**
Decreases the count by 1
*/
void CounterType::decrement()
{
	count--;
}

/**
Displays the count
*/
void CounterType::output()
{
	cout << "Count: " << count << endl;
}
