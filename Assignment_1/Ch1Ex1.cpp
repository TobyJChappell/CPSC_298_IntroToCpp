/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch1_1

Prompts the user to input the weight of a cereal box in ounces and proceeds to display its weight in tons. Additionally, it displays the number of cereal boxes needed to make a ton.
*/
#include <iostream>
using namespace std;

//Number of ounces per ton (Used for conversion)
const double OZ_PER_TON = 35273.92;

void checkNum(double& num)

int main()
{
	double ounce;
	cout << "Enter the weight of a package of cereal in ounces:" << endl;
	cin >> ounce;
	checkNum(ounce);
	double ton = ounce/OZ_PER_TON;
	cout << "Weight of cereal in metric tons: " << ton << endl;
	int boxes = 1/ton + 1;
	cout << "Number of boxes needed to make a metric ton: " << boxes << endl;
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
