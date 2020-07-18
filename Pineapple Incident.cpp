// solution to 697/A problem at codeforces

#include <iostream>

using namespace std;

int main() {
	int t = 0, s = 0, x = 0;
	cin >> t >> s >> x;
	if ((t == x) || (((x - t) % s == 0) || ((x - t - 1) % s == 0)) && ((x - t) / s > 0)) {
		cout << "YES";
		return 0;
	}
	else {
		cout << "NO";
		return 0;
	}
}