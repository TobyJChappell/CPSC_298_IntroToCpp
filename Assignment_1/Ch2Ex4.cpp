/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch2_4

Finds and prints all prime numbers between 3 and 100.
*/
#include <iostream>
using namespace std;
int main()
{
	for(int x = 3; x <= 100; x++)
	{
		bool isPrime = true;
		for(int y = 2; y < x; y++){
			if(x%y == 0)
			{
				isPrime = false;
			}
		}
		if(isPrime)
		{
			cout << x << " ";
		}
	}
	cout << endl;
  return 0;
}
