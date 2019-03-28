/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch6Ex2

Creates a class called CounterType, which is an object used to count things. Records a count that is a nonnegative whole number and has an accessor, mutator, increment, decrement, and output method.
*/

#include <iostream>
using namespace std;

class CounterType
{
private:
	int count = 0;
public:
	void setCount(int c);
	int getCount();
	void increment();
	void decrement();
	void output();
};
