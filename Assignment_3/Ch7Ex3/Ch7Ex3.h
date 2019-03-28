/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch7Ex3

Simulates a counter, allowing the user to input whether they would like to increment (pennies, dimes, dollars, or tens of dollars), check overflow, reset, or exit.
*/
#include <iostream>
#include <limits>

using namespace std;

void checkMax(int& max);

class Counter
{
private:
	int max;
	int count;
public:
	Counter(int m);
	int getMax();
	void setMax(int m);
	int getCount();
	void setCount(int c);
	void reset();
	void incr1();
	void incr10();
	void incr100();
	void incr1000();
	bool overflow();
	void simulate();
	void checkChar(char& c);
	void checkNum(int& num);
};
