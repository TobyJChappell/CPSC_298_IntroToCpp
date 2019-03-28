/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch5Ex2

Write a function called deleteRepeats that has a partially filled array of characters as a formal parameter and that deletes all repeated letters from the array. When a letter is deleted, the remaining letters are moved forward to fill in the gap. The number of positions will be updated once an element is deleted.
*/
#include <iostream>
using namespace std;

void deleteRepeats(char letters[], int& size);
void sort(char letters[], int position, int size);
void output(char letters[], int size);

int main()
{
	char c1[10];
	c1[0] = 'a';
  c1[1] = 'c';
  c1[2] = ' ';
  c1[3] = 'c';
	c1[4] = ' ';
	c1[5] = 'c';
	c1[6] = 'b';
	c1[7] = 'a';
	int size = 8;
	cout << "Original Array: ";
	output(c1, size);
	deleteRepeats(c1, size);
	cout << "Modified Array (repeats deleted): ";
	output(c1, size);
}

/**
Deletes all repeated characters and blanks in a partially filled array
@param letters A partially filled array of letters
@param size The number of filled positions in the array
*/
void deleteRepeats(char letters[], int& size)
{
	for(int x = 1; x < size; x++)
	{
		bool isRepeat = false;
		for(int y = 0; y < x; y++)
		{
			if(letters[x] == letters[y])
			{
				isRepeat = true;
			}
		}
		if(isRepeat || letters[x] == ' ')
		{
			sort(letters, x, size);
			size--;
			x--;
		}
	}
}

/**
Deletes a letter in the array
@param letters A partially filled array of letters
@param position The position of the character being deleted
@param size The number of filled positions in the array
*/
void sort(char letters[], int position, int size)
{
	for(int x = position; x < size; x++)
	{
		letters[x] = letters[x+1];
	}
}

/**
Outputs the array as well as the size
@param letters A partially filled array of letters
@param size The number of filled positions in the array
*/
void output(char letters[], int size)
{
	for(int x = 0; x < size; x++)
	{
		cout << letters[x] << " ";
	}
	cout << endl;
	cout << "Size: " << size << endl;
}
