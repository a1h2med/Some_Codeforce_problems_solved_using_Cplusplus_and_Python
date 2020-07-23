// solution to 766/A problem at codeforces

#include <iostream>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	if (a.length() != b.length()) {
		if (a.length() > b.length()) {
			cout << a.length();
			return 0;
		}
		else {
			cout << b.length();
			return 0;
		}
	}
	else {
		if (a == b) {
			cout << -1;
			return 0;
		}
		else {
			cout << a.length();
			return 0;
		}
	}
}