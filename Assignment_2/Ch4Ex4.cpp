/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch4Ex4

The program reads in a length in feet and inches and outputs the equivalent length in meters and centimeters. The calculation can be repeated as many times as the user wishes.
*/
#include <iostream>
#include <limits>
using namespace std;

//Number of meters per foot
const float M_PER_FT = 0.3048;
//Number of centimeters per meter
const int CM_PER_M = 100;
//Number of inches per foot
const int IN_PER_FT = 12;

void getIn(float& feet, float& inches);
void calculate(float feet, float inches, float& meters, float& centimeters);
void printOut(float feet, float inches, float meters, float centimeters);
void checkNum(float& num);

int main()
{
	char answer;
	float feet;
	float inches;
	float meters;
	float centimeters;
	do{
		getIn(feet, inches);
		calculate(feet, inches, meters, centimeters);
		printOut(feet, inches, meters, centimeters);
		cout << "Would you like to repeat the calculation? (y/n):" << endl;
		cin >> answer;
	} while(answer == 'y' || answer == 'Y');
}

/**
Prompts the user to input the number of feet and inches of a certain length. If the number of inches inputted is greater than or equal to a foot, the method simplifies the length so that for every 12 inches extra in the inches category are taken off, 1 foot is added to the feet category.
@param feet Number of feet
@param inches Number of inches
*/
void getIn(float& feet, float& inches)
{
	cout << "Enter a length in feet and inches:" << endl;
	cout << "Feet: ";
	cin >> feet;
	checkNum(feet);
	cout << "Inches: ";
	cin >> inches;
	checkNum(inches);
	while(inches > 12)
	{
		inches -= 12;
		feet++;
	}
}

/**
Converts feet and inches into meters and centimeters;
@param feet Number of feet
@param inches Number of inches
@param meters Number of meters
@param centimeters Number of centimeters
*/
void calculate(float feet, float inches, float& meters, float& centimeters)
{
	meters = feet*M_PER_FT;
	centimeters = inches/IN_PER_FT*M_PER_FT*CM_PER_M;
}

/**
Outputs the number of meters and centimeters based on the user-inputted feet and inches
@param feet Number of feet
@param inches Number of inches
@param meters Number of meters
@param centimeters Number of centimeters
*/
void printOut(float feet, float inches, float meters, float centimeters)
{
	cout << "There are " << meters << " m and " << centimeters << " cm in " << feet << " ft and " << inches << " in." << endl;
}

/**
Determines if parameter is a number. If not, asks user for a number until one is inputted.
@param float& num Variable being checked
*/
void checkNum(float& num)
{
	while(!cin)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> num;
	}
}
