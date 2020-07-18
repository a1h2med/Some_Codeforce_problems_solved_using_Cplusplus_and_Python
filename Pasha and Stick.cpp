// solution to 610/A problem at codeforces

#include <iostream>

using namespace std;

int main() {
	int length_of_stick = 0;
	cin >> length_of_stick;
	if ((length_of_stick % 2) == 1) {		// I can't handle primary numbers
		cout << 0;
		return 0;
	}
	else {
		int half_length = length_of_stick / 2;
		if (half_length % 2 == 0)
			half_length -= 1;
		cout << half_length / 2;
		return 0;
	}
}
