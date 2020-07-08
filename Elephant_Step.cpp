// solution to 617/A problem at codeforces

#include <iostream>

using namespace std;

int calculating_Step(int x);

int main() {
	int x = 0;
	cin >> x;
	cout << calculating_Step(x);
	return 0;
}

int calculating_Step(int x) {
	int temp = 0, result = 0;
	if (x % 5 == 0) {
		result = x / 5;
		return result;
	}
	temp = x - 1;
	if (temp % 5 == 0) {
		result = temp / 5 + 1;
		return result;
	}
	temp = x - 2;
	if (temp % 5 == 0) {
		result = temp / 5 + 1;
		return result;
	}
	temp = x - 3;
	if (temp % 5 == 0) {
		result = temp / 5 + 1;
		return result;
	}
	temp = x - 4;
	if (temp % 5 == 0) {
		result = temp / 5 + 1;
		return result;
	}
}