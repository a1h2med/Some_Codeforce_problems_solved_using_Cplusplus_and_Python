// Solution To Problem 402/A
/**
 * @file Nuts.cpp
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
 *  a nuts, divided into x + 1, more than k sections,
 *  v nuts into some section of the box, Number of Boxes, you have b divisors .
 * Algorithm :
 *  k => Number of sections, a => Number of Nuts,
 *  b => Number of Divisors, v => Number of Nuts in each section .
 *  x => Number Of Boxes ?
 */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int KNumberOfSections, ANumberOfNuts, BNumberOfDivisors,
        VNumberOfNutsSections, NoOfNutsInBoxes, NoOfBoxesDivisors, TotNoOfBoxesNeeded = 0;

    cin >> KNumberOfSections >> ANumberOfNuts >> BNumberOfDivisors >> VNumberOfNutsSections ;

    if (KNumberOfSections <= BNumberOfDivisors){
        NoOfNutsInBoxes = KNumberOfSections * VNumberOfNutsSections;
        NoOfBoxesDivisors = ceil((BNumberOfDivisors + 1) / KNumberOfSections);
        while (ANumberOfNuts > NoOfNutsInBoxes & NoOfBoxesDivisors != 0){
            ANumberOfNuts -= NoOfNutsInBoxes;
            NoOfBoxesDivisors--;
        }
        TotNoOfBoxesNeeded = ceil((BNumberOfDivisors + 1) / KNumberOfSections);

        while (ANumberOfNuts > VNumberOfNutsSections)
        {
            ANumberOfNuts -= VNumberOfNutsSections;
            TotNoOfBoxesNeeded++;
        }
        if (ANumberOfNuts > 0)
            TotNoOfBoxesNeeded++;
    }

    else{
        NoOfNutsInBoxes = (BNumberOfDivisors+1) * VNumberOfNutsSections;
        NoOfBoxesDivisors = 1;
        
        ANumberOfNuts -= NoOfNutsInBoxes;
        
        TotNoOfBoxesNeeded = NoOfBoxesDivisors;
        while (ANumberOfNuts > VNumberOfNutsSections)
        {
            ANumberOfNuts -= VNumberOfNutsSections;
            TotNoOfBoxesNeeded++;
        }
        if (ANumberOfNuts > 0)
            TotNoOfBoxesNeeded++;
    }

    cout<<TotNoOfBoxesNeeded<<endl;
    return 0;
}
