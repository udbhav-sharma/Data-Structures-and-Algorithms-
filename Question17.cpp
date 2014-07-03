/*
Write a function, for a given number, print out all different ways to make this number, by using addition and any number equal to or smaller than this number and greater than zero.

For example, given a 5, we have the following different ways to make up 5:

1st: 1, 1, 1, 1, 1
2nd: 1, 4
3rd : 1, 1, 1, 2
4th : 1, 1, 3
5th : 2, 3
6th : 1, 2, 2
7th : 5

Print out one case at a time in its own line, assuming the line is sufficiently long.
*/

#include <iostream>

using namespace std;

void PrintCombo(int num, int* arr, int index )
{
	if (num == 0)
	{
		for (int i = 0; i<index; i++)
		{
			if (i != 0)
				cout << ',';
			cout << arr[i];
		}
		cout << '\n';
		return;
	}
	for (int i = num; i > 0; i--)
	{
		if (index == 0 || i <= arr[index - 1])
        {
			arr[index] = i;
			PrintCombo(num - i, arr, index + 1);
        }
	}
}

int main()
{
	int num;
	cout << "Enter the number \n";
	cin>>num;
	int *arr = new int[num];
	PrintCombo(num, arr, 0);
}
