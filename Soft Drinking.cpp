// solution to 151/A problem at codeforces

#include <iostream>

using namespace std;

int GetMin(int* Array_of_Numbers, int size);

int main() {
	int Number_Of_Friends = 0, Number_Of_Bottles = 0, Bottle_Milliliters = 0, Number_Of_Limes = 0, Limes_Slices = 0;
	int Grams_Of_Salt = 0, Needed_Milliliters = 0, Slice_of_lime = 1, Grams_Of_Salt_Needed = 0;

	cin >> Number_Of_Friends >> Number_Of_Bottles >> Bottle_Milliliters >> Number_Of_Limes >> Limes_Slices >> Grams_Of_Salt >> Needed_Milliliters >> Grams_Of_Salt_Needed;
	int Milliliters = Number_Of_Bottles * Bottle_Milliliters;
	int Number_Of_Toasts_M = Milliliters / Needed_Milliliters;
	int Number_Of_Toasts_L = Number_Of_Limes * Limes_Slices;
	int Number_Of_Toasts_S = Grams_Of_Salt / Grams_Of_Salt_Needed;
	int Array_Of_Toasts[3] = { Number_Of_Toasts_M , Number_Of_Toasts_L , Number_Of_Toasts_S };
	int Min_value = GetMin(Array_Of_Toasts, 3);
	int result = Min_value / Number_Of_Friends;
	cout << result;
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