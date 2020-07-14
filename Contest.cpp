// solution to 501/A/codeforces
#include <iostream>
 
using namespace std;
 
int main(){
    int a,b,c,d;
    float misha_points = 0, Vasya_points = 0;
    cin >> a>>b>>c>>d;
    float misha_points1 = 3*a/10;
    float misha_points2 = a-((a/250)*c);
    if (misha_points1 > misha_points2)
        misha_points = misha_points1;
    else
        misha_points = misha_points2;
    
    float Vasya_points1 = 3*b/10;
    float Vasya_points2 = b-((b/250)*d);
    if (Vasya_points1 > Vasya_points2)
        Vasya_points = Vasya_points1;
    else
        Vasya_points = Vasya_points2;
    if (Vasya_points > misha_points){
        cout<<"Vasya";
        return 0;
    }
    else if (Vasya_points < misha_points) {
        cout<<"Misha";
        return 0;
    }
    else {
        cout<<"Tie";
        return 0;
    }
}