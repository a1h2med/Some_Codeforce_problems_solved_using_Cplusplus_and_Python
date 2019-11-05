#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
using namespace std;

int GetMatrix (string s,float x[100][100], 	int SIZE1[100]){
	string data;
	int counter = 0;int value = 0;
	for (int i=0;i<s.length();i++){
		if (s[i] == '[' || s[i] == ';' || s[i] == ']')
		{
			if (s[i] == ']'){
				s[i] = ' ';
				for (int g=i;g<s.length();g--){
					if(s[g] == ';'){
						data = s.substr(g+1,i+1);
						counter++;
						break;
					}
				}}
		for (int g=i;g<s.length();g++){
			if (s[g] == ';' ){
				data = s.substr(i+1,g-1);
				data += ' ';
			i = g;
			counter++;
			break;
			}
			}
		int coun = 0 , see = 0;
		for (int j=0;j<data.length();j++){
			if (data[j] == ' '){
			string cc = data.substr(coun,j);
			x[counter-1][see] = atof(cc.c_str()); 
			coun = j+1;
			see++;
		}	
			}
		SIZE1[value] = see;
			value++;
		}
	}
	return counter;
}

int main(){
	string Input1,Input2;string Op;
	getline(cin,Input1);
	getline(cin,Op);
	getline(cin,Input2);
	float x[100][100];
	float y[100][100];
	float z[100][100];
	int SIZE1[100];
	int SIZE2[100];
	int size_mat1 = GetMatrix (Input1,x,SIZE1);
	int size_mat2 = GetMatrix (Input2,y,SIZE2);

	if (Op == "+")
	{
		for (int i=0;i<size_mat1;i++)
			for(int j=0;j<SIZE1[i];j++)
				z[i][j] = x[i][j] + y[i][j];
	}
	else if (Op == "-")
	{
		for (int i=0;i<size_mat1;i++)
			for(int j=0;j<SIZE1[i];j++)
				z[i][j] = x[i][j] + y[i][j];
	}
	else 
	{
		for (int i=0;i<size_mat1;i++)
			for(int j=0;j<SIZE1[i];j++)
				z[i][j] = x[i][j] * y[i][j];
	}
	for (int i=0;i<size_mat1;i++){
		if (i == 0)
			cout<<"[";
		for(int j=0;j<SIZE1[i];j++){
			if (j == SIZE1[i]-1){
				cout<<z[i][j];
			}
			else
				cout<<z[i][j]<<" ";
		}
		if (i == size_mat1-1)
			cout<<"]"<<endl;
		else 
			cout<<";";
		}
	system("pause");
	return 0;
}
