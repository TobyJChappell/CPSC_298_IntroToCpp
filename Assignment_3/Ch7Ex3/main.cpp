#include <iostream>
#include <limits>
#include "Ch7Ex3.h"
using namespace std;

int main()
{
	int max;
	cout << "How much would you like your max like to be?" << endl;
	cin >> max;
	checkMax(max);
	Counter c1(max);
	c1.simulate();
}
