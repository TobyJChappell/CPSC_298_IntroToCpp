#include <iostream>
#include "Ch6Ex2.h"
using namespace std;

int main()
{
	CounterType c1;
	c1.setCount(2);
	c1.output();
	c1.increment();
	c1.output();
	c1.decrement();
	c1.output();
	c1.decrement();
	c1.output();
}
