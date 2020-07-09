// solution to 764/A problem at codeforces

#include <iostream>

using namespace std;

int getting_intersection(int Ilia_alpinist_calls, int Artists_come, int Day);

int main() {
	int Ilia_alpinist_calls = 0, Artists_come = 0, Day = 0;
	cin >> Ilia_alpinist_calls >> Artists_come >> Day;
	int result = getting_intersection(Ilia_alpinist_calls, Artists_come, Day);
	cout << result;
	return 0;
}

int getting_intersection(int Ilia_alpinist_calls, int Artists_come, int Day) {
	int killed = 0, temp = Ilia_alpinist_calls, temp2 = Artists_come;
	while (temp <= Day && temp2 <= Day) {
		if (temp <= temp2 && (temp <= Day && temp2 <= Day)) {
			if (temp == temp2)
				killed += 1;
			else {
				temp += Ilia_alpinist_calls;
				continue;
			}
		}
		temp2 += Artists_come;
	}
	return killed;
}