/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch1_3

Workers at a particular company have won a 7.6% pay increase retroactive for six months. This program takes an employee’s previous annual salary as input and outputs the amount of retroactive pay due the employee, the new annual salary, and the new monthly salary.
*/
#include <iostream>
using namespace std;

//Percent pay increase
const float PERCENT = 0.076;

void checkNum(float& num)

int main()
{
	cout << "Enter previous annual salary:" << endl;
	float preSal;
	cin >> preSal;
	checkNum(preSal);
	float payDue = preSal*PERCENT/2;
	cout << "Retroactive pay due: $" << payDue << endl;
	float newSal = preSal + preSal*PERCENT;
	cout << "New annual salary: $" << newSal << endl;
	float mSal = newSal/12;
	cout << "New monthly salary: $" << mSal << endl;
  return 0;
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
