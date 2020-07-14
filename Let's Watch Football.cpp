// solution to 195/problem/A/codeforces

#include <iostream>
 
using namespace std;
 
int main(){
    int a = 0,b = 0,c = 0;
    cin >> a >> b >> c;
    int out = ((a*c+b-1)/b) - c;
    cout << out;
    return 0;
}