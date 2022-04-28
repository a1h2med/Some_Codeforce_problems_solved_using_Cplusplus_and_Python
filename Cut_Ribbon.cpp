// Solution To Problem 189/A
/**
 * @file Cut_Ribbon.cpp
 * @author Ahmed Ashraf (ahmedashrafmahmoud@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * Problem :
 *  ribbon length is n, after cutting lengths shoud be a, b or c, and should be MAX .
 *  choose such that is divisible by 5 .
 * Algorithm :
 *  check on lengths, and subtract from the length .
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, a, b, c, Out = 0;

    cin >> n >> a >> b >> c ;

    int minimum = min({a,b,c});

    while (minimum < n){
        
        if (a < n){
            n -= a;
            Out++;
        }

        if (b < n){
            n -= b;
            Out++;
        }

        if (c < n){
            n -= c;
            Out++;
        }
    }

    if (minimum == n)
        Out++;
    cout<<Out<<endl;
    return 0;
}
