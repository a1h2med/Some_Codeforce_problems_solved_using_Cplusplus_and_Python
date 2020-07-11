// solution to 263/A problem at codeforces

#include <iostream>
using namespace std;
int main()
{
	int arr[5][5], x = 0, z = 0, s = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> x;
			if (x == 0 || x == 1)
				arr[i][j] = x;
			else
			{
				i = i + 0; j = j + 0;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == 1)
			{
				z = i; s = j;
			}
		}
	}
	if (z == 2)
	{
		if (s == 2)
			cout << 0 << endl;
		else if (s == 1 || s == 3)
			cout << 1 << endl;
		else if (s == 0 || s == 4)
			cout << 2 << endl;
	}
	else if (z == 3 || z == 1)
	{
		if (s == 2)
			cout << 1 << endl;
		else if (s == 1 || s == 3)
			cout << 2 << endl;
		else if (s == 0 || s == 4)
			cout << 3 << endl;
	}
	else if (z == 0 || z == 4)
	{
		if (s == 2)
			cout << 2 << endl;
		else if (s == 1 || s == 3)
			cout << 3 << endl;
		else if (s == 0 || s == 4)
			cout << 4 << endl;
	}
	return 0;
}