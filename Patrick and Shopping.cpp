// solution to 599/A problem at codeforces

#include <iostream>

using namespace std;

int GetMin(int* Array_of_Numbers, int size);

int main() {
	int length_to_first_shop = 0, length_to_second_shop = 0, length_bet_two_shops = 0;
	cin >> length_to_first_shop >> length_to_second_shop >> length_bet_two_shops;
	int tot_length_to_first_shop = length_to_first_shop * 2;
	int tot_length_to_second_shop = length_to_second_shop * 2;

	int Prob_length_values[4];
	Prob_length_values[0] = length_to_first_shop * 2 + length_to_second_shop * 2;
	Prob_length_values[1] = length_to_first_shop + length_bet_two_shops + length_to_second_shop;
	Prob_length_values[2] = length_to_first_shop * 2 + length_bet_two_shops * 2;
	Prob_length_values[3] = length_to_second_shop * 2 + length_bet_two_shops * 2;
	int MIN_distance = GetMin(Prob_length_values, 4);
	cout << MIN_distance;
	system("pause");
	return 0;
}

int GetMin(int* Array_of_Numbers, int size) {
	int Min_value = Array_of_Numbers[0];
	for (int i = 0; i < size; i++) {
		if (Array_of_Numbers[i] < Min_value)
			Min_value = Array_of_Numbers[i];
	}
	return Min_value;
}