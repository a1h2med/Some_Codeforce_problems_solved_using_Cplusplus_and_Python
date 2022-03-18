// solution to codeforces problem Infinite 675/A

// Algorithm
// 1- Add to sequence till you reach the number, otherwise you didn't break .
// If zero Additioon check on first and second .

#include <iostream>

using namespace std;

int main(void) {
	int First, favourite, step;
	cin >> First >> favourite >> step;
	if (step == 0) {
		if (First == favourite)
			cout << "YES";
		else
			cout << "NO";
	}
	else {
		if (First == favourite)
			cout << "YES";
		else if (First < 0 && step < 0 && favourite > 0)
			cout << "NO";
		else {
			while ((First <= favourite && favourite > 0) || (First >= favourite && (favourite < 0 || step < 0))) {
				First = step + First;
				if (favourite == First) {
					cout << "YES";
					break;
				}
			}
			if (First != favourite) {
				cout << "NO";
			}

		}
	}
	return 0;
}