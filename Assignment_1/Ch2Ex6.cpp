/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch2_6

Prompts the user to input the weight (in pounds) and radius (in feet) of a sphere and outputs whether the sphere will sink or float in water. Uses g = 62.4 lb/ft^3 as the specific weight of water.
*/
#include <iostream>
#include <cmath>
using namespace std;

//Weight of water
const double WEIGHT_OF_FLUID = 62.4;

void checkNum(double& num);

int main()
{
	cout << "Enter the weight of the sphere (in pounds):" << endl;
	double weight;
	cin >> weight;
	checkNum(weight);
	cout << "Enter the radius of the sphere (in feet):" << endl;
	double radius;
	cin >> radius;
	checkNum(radius);
	double volume = 4/3*M_PI*pow(radius, 3);
	double buoyantForce = volume*WEIGHT_OF_FLUID;
	if(buoyantForce >= weight)
	{
		cout << "The sphere will float." << endl;
	}
	else
	{
		cout << "The sphere will sink." << endl;
	}
  return 0;
}

/**
Determines if parameter is a number. If not, asks user for a number until one is inputted.
@param double& num Variable being checked
*/
void checkNum(double& num)
{
	while(!cin)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> num;
	}
}
