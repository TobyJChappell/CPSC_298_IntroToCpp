/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch3Ex1

Determines the mpg of a car based on user-inputted liters consumed and miles traveled.
*/
#include <iostream>
#include <limits>
using namespace std;
//Number of liters per gallon
const double L_PER_GAL = 0.264179;

double calcMPG(double l, double m);

void checkNum(double& num);

int main()
{
	char answer;
	do{
		cout << "Enter the number of liters of gasoline consumed by your car:" << endl;
		double liters;
		cin >> liters;
		checkNum(liters);
		cout << "Enter the number of miles traveled by your car:" << endl;
		double miles;
		cin >> miles;
		checkNum(miles);
		cout << "Your mpg is " << calcMPG(liters, miles) << "." << endl;
		cout << "Would you like to do another calculation? (y/n):" << endl;
		cin >> answer;
	} while(answer == 'y' || answer == 'Y');
	return 0;
}

/**
Calculates the mpg of a car
@param l Liters of gasoline
@param m Miles traveled
*/
double calcMPG(double l, double m)
{
	double g = l/L_PER_GAL;
	return m/g;
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
