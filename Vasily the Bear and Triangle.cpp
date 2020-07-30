// solution to 336/A problem at codeforces


#include <iostream>

using namespace std;

int main() {
    int x = 0, y = 0;
    cin >> x >> y;
    int z = abs(x) + abs(y);
    if ((x > 0) && (y > 0))
        cout << 0 << " " << z << " " << z << " " << 0;
    else if ((x < 0) && (y > 0))
        cout << -z << " " << 0 << " " << 0 << " " << z;
    else if ((x > 0) && (y < 0))
        cout << 0 << " " << -z << " " << z << " " << 0;
    else
        cout << -z << " " << 0 << " " << 0 << " " << -z;
    return 0;
}