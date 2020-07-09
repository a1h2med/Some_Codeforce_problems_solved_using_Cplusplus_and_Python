// solution to 546/A problem at codeforces

#include <iostream>

using namespace std;

int Summation(int cost, int Number);

int main() {
	int Cost = 0, Money = 0, Number = 0;
	cin >> Cost >> Money >> Number;
	int result = Summation(Cost, Number);
	if (Money > result) {
		cout << 0;
	}
	else {
		cout << abs(Money - result);
	}
	return 0;
}

int Summation(int cost, int Number) {
	int i = 0, summation_result = 0;
	while (i <= Number) {
		summation_result += cost * i;
		i++;
	}
	return summation_result;
}