// solution to 509/A problem at codeforces

#include <iostream>

using namespace std;

int main() {
	int elemCount = 0, Max_Number = 1;
	cin >> elemCount;
	int** Matrix = new int* [elemCount];

	for (int i = 0; i < elemCount; i++)
		Matrix[i] = new int[elemCount];

	for (int i = 0; i < elemCount; i++) {
		Matrix[i][0] = 1;
	}

	for (int i = 0; i < elemCount; i++) {
		Matrix[0][i] = 1;
	}

	for (int i = 1; i < elemCount; i++) {
		for (int j = 1; j < elemCount; j++) {
			Matrix[i][j] = Matrix[i][j - 1] + Matrix[i - 1][j];
			if (Matrix[i][j] > Max_Number)
				Max_Number = Matrix[i][j];
		}
	}
	cout << Max_Number;
	return 0;
}