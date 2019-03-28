/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch6Ex4

Creates a class named GasPump which models the behavior of a gas pump. The following behaviors are implemented:
a. A display of the amount dispensed
b. A display of the amount charged for the amount dispensed
c. A display of the cost per gallon, liter, or other unit of volume that is used where you reside
d. Before use, the gas pump must reset the amount dispensed and amount charged to zero.
e. Once started, a gas pump continues to dispense fuel, keep track of the amount dispensed, and compute the charge for the amount dispensed until stopped.
f. A stop dispensing control of some kind is needed.
*/

#include <iostream>
#include <limits>
using namespace std;

class GasPump
{
private:
	float dollars_per_gallon;
	float dispensed = 0.0f;
	float price = 0.0f;
	void checkNum(int& num);
	void displayDispensed();
	void displayPrice();
	void selectGas();
	void reset();
	void dispense();
	bool stop();
public:
	float getDispensed();
	void setDispensed(float d);
	float getPrice();
	void setPrice(float p);
	float getDollarsPerGal();
	void setDollarsPerGal(float d);
	void simulate();
};
