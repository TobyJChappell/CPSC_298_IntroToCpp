/**
@name Toby Chappell
@student_id 2312642
@email tchappell@chapman.edu
@course CPSC-298-01
@assignment Ch5Ex4

Reads in an array of type int and determines how many entries are used. The output is to be a two-column list, in which the first column is a list of the distinct array elements and the second is the count of the number of occurrences of each element. The list is then sorted by entries in the first column, largest to smallest.
*/
#include <iostream>
using namespace std;

int getSize(int a[]);
void sort(int a[], int size);
void countRepeats(int a[], int size, int repeats[]);
void deleteRepeats(int a[], int& size);
void shift(int a[], int position, int size);
void output(int a[], int size, int repeats[]);

int main()
{
	int a[50] = {-12, 3, -12, 4, 1, 1, -12, 1, -1, 1, 2, 3, 4, 2, 3, -12, 6, 3, -2, -1};
	int size = getSize(a);
	sort(a, size);
	cout << "Size: " << size << endl;
	int repeats[size] = {0};
	countRepeats(a, size, repeats);
	deleteRepeats(a, size);
	output(a, size, repeats);
}

/**
Returns the number of filled entries in an array of max 50 numbers
@param a A partially filled array of numbers
*/
int getSize(int a[])
{
	int count = 0;
	while(a[count] != 0 && count < 50)
	{
		count++;
	}
	return count;
}

/**
Sorts the array from greatest to smallest
@param a A partially filled array of numbers
@param size The number of filled positions in the array
*/
void sort(int a[], int size)
{
	for(int x = 0; x < size; x++)
	{
		int max = a[x];
		int pos = x;
		for(int y = x + 1; y < size; y++)
		{
			if(a[y] > max)
			{
				max = a[y];
				pos = y;
			}
		}
		int temp = a[x];
		a[x] = max;
		a[pos] = temp;
	}
}

/**
Counts the number of repeats and assigns the value to an array
@param a A partially filled array of numbers
@param size The number of filled positions in the array
@param repeats Number of repeats of each integer in the array
*/
void countRepeats(int a[], int size, int repeats[])
{
	int count = 0;
	for(int x = 0; x < size; x++)
	{
		repeats[count]++;
		while(a[x] == a[x+1])
		{
			repeats[count]++;
			x++;
		}
		count++;
	}
}

/**
Deletes all repeated numbers and blanks in a partially filled array
@param a A partially filled array of integerrs
@param size The number of filled positions in the array
*/
void deleteRepeats(int a[], int& size)
{
	for(int x = 1; x < size; x++)
	{
		bool isRepeat = false;
		for(int y = 0; y < x; y++)
		{
			if(a[x] == a[y])
			{
				isRepeat = true;
			}
		}
		if(isRepeat || a[x] == ' ')
		{
			shift(a, x, size);
			size--;
			x--;
		}
	}
}

/**
Deletes a letter in the array and moves all elements to fill that location
@param a A partially filled array of integers
@param position The position of the character being deleted
@param size The number of filled positions in the array
*/
void shift(int a[], int position, int size)
{
	for(int x = position; x < size; x++)
	{
		a[x] = a[x+1];
	}
}

/**
Formats the contents of the array and the number of repeats into two columns
@param a A partially filled array of integers
@param size The number of filled positions in the array
@param repeats Number of repeats of each integer in the array
*/
void output(int a[], int size, int repeats[])
{
	cout << "N     Count" << endl;
	for(int x = 0; x < size; x++)
	{
		cout << a[x] << "     " << repeats[x] << endl;
	}
}
