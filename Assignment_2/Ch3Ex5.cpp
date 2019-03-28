/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch3Ex5

Determines the clothing size based on a person's height, weight, and age.
*/
#include <iostream>
#include <limits>
using namespace std;


float calcHat(float height, float weight);
float calcJacket(float height, float weight, int age);
float calcWaist(float height, float weight, int age);
void checkNum(float& num);
void checkNum(int& num);


int main()
{
	char answer;
	float height;
	float weight;
	int age;
	do{
		cout << "Enter your height (inches):" << endl;
		cin >> height;
		checkNum(height);
		cout << "Enter your weight (pounds):" << endl;
		cin >> weight;
		checkNum(weight);
		cout << "Enter your age:" << endl;
		cin >> age;
		checkNum(age);
		cout << "Hat Size: " << calcHat(height, weight) << endl;
		cout << "Jacket Size: " << calcJacket(height, weight, age) << endl;
		cout << "Waist Size: " << calcWaist(height, weight, age) << endl;
		cout << "Would you like to repeat the calculation? (y/n):" << endl;
		cin >> answer;
	} while(answer == 'y' || answer == 'Y');
}

/**
Calculates hat size
@param height Height in inches
@param weight Weight in pounds
@return float Hat size
*/
float calcHat(float height, float weight)
{
	return weight/height*2.9;
}

/**
Calculates jacket size (chest in inches)
@param height Height in inches
@param weight Weight in pounds
@param age Age in years
@return float Jacket size
*/
float calcJacket(float height, float weight, int age)
{
	float addition = 0.0;
	if(age > 30)
	{
		addition = (float)((age-30)/10)/8;
	}
	return height*weight/288 + addition;
}

/**
Calculates waist in inches
@param height Height in inches
@param weight Weight in pounds
@param age Age in years
@return float Waist
*/
float calcWaist(float height, float weight, int age)
{
	float addition = 0.0;
	if(age > 28)
	{
		addition = (float)((age-28)/2)/10;
	}
	return weight*5.7 + addition;
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
