#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main(){
	int a , y=0 , counter =0;
	cin>>a;
	float *Ass = new float [a];
	
	for (int i=0;i<a;i++)
		cin>>Ass[i];

	for (int i=0;i<a;i++){
		for (int j=0 ; j<a ; j++){
			if (j==i)
				continue;
			else {
				if (Ass[i] <  Ass[j]){
					if (i > j)
					{
						y = Ass[i];
						Ass[i] = Ass[j];
						Ass[j] = y;
						break;
					}
					else 
						continue;
				}
				else {
					if (j > i){
					y = Ass[i];
					Ass[i] = Ass[j];
					Ass[j] = y;
					break;
					}
					else continue;
				}
			}
		}
		if (i == a-1){
			counter++;
			if (counter == a-1)
				break;
			else i=0;
		}
	}

	for (int i=0;i<a;i++)
		cout<<Ass[i]<<endl;

	system("pause");
	return 0;
}