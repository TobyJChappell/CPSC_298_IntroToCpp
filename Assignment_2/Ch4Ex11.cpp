/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch4Ex11

Before you are three doors, in which only one contains the grand prize of $1,000,000 in cash. The game show host asks you to select a door, and you randomly pick one. However, before revealing the prize behind your door, the game show host reveals one of the other doors that contains a consolation prize. At this point, the game show host asks if you would like to stick with your original choice or to switch to the remaining door. Write a function to simulate the game show problem. Determine whether the contestant would win or lose by sticking with the original choice or switching to the remaining door. Next, modify your program so that it simulates playing 10,000 games. Count the number of times the contestant wins when switching versus staying.
*/
#include <iostream>
#include <cmath>
using namespace std;

void simulate(int& switchTo, int& stickWith);
void switchDoor(int& selection, int opening);
void update(int choice, int& switchTo, int& stickWith);

int main()
{
	srand(time(0));
	int switchTo = 0;
	int stickWith = 0;
	for(int x = 0; x < 10000; x++)
	{
		simulate(switchTo, stickWith);
	}
	cout << "Switching wins: " << switchTo << endl;
	cout << "Sticking wins: " << stickWith << endl;
}

/**
Simulates a single game
@param switchTo Number of games won by switching
@param stickWith Number of games won by sticking
*/
void simulate(int& switchTo, int& stickWith)
{
	int prize = rand()%3 + 1;
	int selection = rand()%3 + 1;
	int opening = rand()%3 + 1;
	while(opening == prize || opening == selection)
	{
		opening = rand()%3 + 1;
	}
	int choice = rand()%2;
	if(choice == 0)
	{
		switchDoor(selection, opening);
	}
	if(selection == prize)
	{
		update(choice, switchTo, stickWith);
	}
}

/**
If user decides to switch to the remaining doors, it will update the user's selection.
@param selection User's previous selection
@param opening Door revealed to be a consolation prize
*/
void switchDoor(int& selection, int opening)
{
	for(int y = 1; y <= 3; y++)
	{
		if(y != selection && y != opening)
		{
			selection = y;
		}
	}
}

/**
If the player has won, it updates the variables of how many times they've won by either switching doors or sticking to them.
@param choice 0 if the player switches, 1 if the player sticks
@param switchTo Number of games won by switching
@param stickWith Number of games won by sticking
*/
void update(int choice, int& switchTo, int& stickWith)
{
	if(choice == 0)
	{
		switchTo++;
	}
	else
	{
		stickWith++;
	}
}
