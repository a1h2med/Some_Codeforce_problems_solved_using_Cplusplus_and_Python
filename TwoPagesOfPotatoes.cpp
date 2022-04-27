// Solution To Problem 239/A
/**
 * @file Two Bags of Potatoes.cpp
 * @author Ahmed Ashraf (ahmedashrafmahmoud@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * Problem :
 * Two bags, First, Second Contains x, y ; x,y >= 1.
 * x+y < n , x+y%k
 * x < n-y
 * Algorithm :
 * Multiples of k in range 1 to n .
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int size = 0;
    int y, k, n;
    int *x = new int(size);

    cin >> y >> k >> n ;
    for (int i=2; k*i<n ; i++){
        if (y-(k*i) < n && y!=n){
            x[size] = (k*i)-y;
            size++;
        }
        else 
            break;
    }
    if (size == 0)
        cout<<-1<<endl;
    else{
        for (int i=0; i<size ; i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
