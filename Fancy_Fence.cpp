// Solution To Problem 239/A
/**
 * @file Fancy_Fence.cpp
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
 * regular polygon, single path, single angle a .
 * Algorithm :
 * Regular Polygon Eqn.
 * (n-2)*180 / n = angle .
 * n(180 - angle) = 360 .
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int NoOfTestCases = 0;
    int *InAngles = new int(NoOfTestCases);
    string Outputs;

    cin >> NoOfTestCases ;
    for (int angles=0; angles<NoOfTestCases ; angles++)
        cin >> InAngles[angles];
    
    for (int angles=0; angles<NoOfTestCases ; angles++){
        if (360%(180-InAngles[angles]) == 0)
                InAngles[angles] = 1;
            else
                InAngles[angles] = 0;
    }

    for (int output=0; output<NoOfTestCases; output++)
        if (InAngles[output] == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    return 0;
}
