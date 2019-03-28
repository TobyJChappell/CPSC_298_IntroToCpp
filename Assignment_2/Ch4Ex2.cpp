/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch4Ex2

Prompts the user to enter the side lengths of a triangle. If the triangle can't exist, it then prompts the user that the triangle is illegal. If it does exist, it then calculates and outputs the area and perimeter of the triangle.
*/
#include <iostream>
#include <cmath>
using namespace std;

void calculate(double a, double b, double c, double& area, double& perimeter);
void checkNum(double& num);

int main()
{
	double a, b, c;
	double area;
	double perimeter;
	cout << "Enter the length of the 1st side of the triangle:" << endl;
	cin >> a;
	checkNum(a);
	cout << "Enter the length of the 2nd side of the triangle:" << endl;
	cin >> b;
	checkNum(b);
	cout << "Enter the length of the 3rd side of the triangle:" << endl;
	cin >> c;
	checkNum(c);
	calculate(a, b, c, area, perimeter);
}

/**
Determines if triangle is legal. If it is, it then calculates and outputs the area and perimeter.
@param a 1st side
@param b 2nd side
@param c 3rd side
*/
void calculate(double a, double b, double c, double& area, double& perimeter)
{
	double s;
	if(a <= 0 || b <= 0 || c <= 0)
	{
		cout << "A triangle cannot have a side less than or equal to 0." << endl;
	}
	else if(a >= (b+c) || b >= (a+c) || c >= (a+b))
	{
		cout << "One side of the triangle cannot be greater or equal to both side added together." << endl;
	}
	else
	{
		s = (a+b+c)/2;
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		perimeter = a+b+c;
		cout << "Area: " << area << endl;
		cout << "Perimeter: " << perimeter << endl;
	}
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
