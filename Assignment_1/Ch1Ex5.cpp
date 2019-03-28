/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch1_5

Determines whether a meeting room is in violation of fire law regulations regarding the maximum room capacity. Prompts the user to input the maximum room capacity and the number of people to attend the meeting. If the number of people is less than or equal to the maximum room capacity, the program outputs that it is legal to hold the meeting and tells how many additional people may legally attend. If the number of people exceeds the maximum room capacity, the program outputs that the meeting cannot be held as planned due to fire regulations and tells how many people must be excluded in order to meet the fire regulations.
*/
#include <iostream>
using namespace std;

void checkNum(int& num);

int main()
{
	cout << "Enter the maximum room capacity:" << endl;
	int max;
	cin >> max;
	checkNum(max);
	cout << "Enter the number of people attending the meeting:" << endl;
	int people;
	cin >> people;
	checkNum(people);
	if(people <= max)
	{
		cout << "It is legal to hold a meeting in this room." << endl;
		if(people == max)
		{
			cout << "However, no more people may attend the meeting." << endl;
		}
		else
		{
			cout << (max-people) << " more people may attend the meeting." << endl;
		}
	}
	else
	{
		cout << "Due to fire regulations, it is illegal to hold a meeting here with this many people." << endl;
		cout << "Please exclude " << (people-max) << " people in order to meet the fire regulations." << endl;
	}
  return 0;
}

/**
Determines if parameter is a number. If not, asks user for a number until one is inputted.
@param int& num Variable being checked
*/
void checkNum(int& num)
{
	while(!cin)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> num;
	}
}
