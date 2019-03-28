/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch2_2

You have just purchased a stereo system that cost $1,000 on the following credit plan: no down payment, an interest rate of 18% per year (1.5% per month), and monthly payments of $50. The monthly payment of $50 is used to pay the interest, and whatever is left is used to pay part of the remaining debt. This program outputs how many months it will take to pay off the stereo.
*/
#include <iostream>
using namespace std;

//Cost of stereo in dollars
int cost = 1000;
//Interest rate
float rate = 0.015;
//Monthly payment in dollars
int mPayment = 50;

int main()
{
	int months = 0;
	while(cost > 0)
	{
		float interest = rate*cost;
		cost -= (mPayment-interest);
		months++;
	}
	cout << "It will take " << months << " months to pay off the stereo." << endl;
  return 0;
}
