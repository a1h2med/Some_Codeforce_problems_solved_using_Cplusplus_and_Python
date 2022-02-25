#include <iostream>

using namespace std;

int main(void) {

	int a = 0;
	int b = 0;

	auto Add = [&](int A, int B) {
		a = 50;
		cout << A + B;
	};
	Add(15, 10);
	system("pause");
	return 0;
}
