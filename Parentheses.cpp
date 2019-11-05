#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	string* input;
	stack<char> A;
	char s;
	int x = 0;
	cin>>x;
	input = new string [x];
	for (int i=0;i<x;i++)
		cin>>input[i];
	for (int i=0;i<x;i++){
		int flag = 0;
		int flag1 = 0;
		while (A.empty() == 0)
			A.pop();
		for (int j=0;j<input[i].length();j++){
			char x = input[i][j];
			if (flag1 == 1)
				break;
			else {
				if (x == '{' || x == '<' || x == '(' || x == '[')
				A.push(x);
			else if (input[i][0] == ')' || input[i][0] == ']' || input[i][0] == '}' || input[i][0] == '>')
				break;
			else {
				switch (x)
				{
					case '}' :
						if (A.empty()){
							flag = 0;
							flag1 = 1;}
						else{
						s = A.top();
						A.pop();
						if (s == '{'){
							flag = 1;
							continue;}
						else {
							flag = 0;
							flag1 = 1;
						}}
						break;
					case ']' :
						if (A.empty()){
							flag = 0;
							flag1 = 1;}
						else{
						 s = A.top();
						A.pop();
						if (s == '['){
							flag = 1;
							continue;}
						else {
							flag = 0;
							flag1 = 1;
						}}
						break;
					case '>' :     
						if (A.empty()){
							flag = 0;
							flag1 = 1;}
						else{
						 s = A.top();
						A.pop();
						if (s == '<'){
							flag = 1;
							continue;}
						else {
							flag = 0;
							flag1 = 1;}}
						break;
					case ')' :     
						if (A.empty()){
							flag = 0;
							flag1 = 1;}
						else{
						 s = A.top();
						A.pop();
						if (s == '('){
							flag = 1;
							continue;}
						else {
							flag = 0;
							flag1 = 1;
						}}
						break;
				default:
					break;
				}
			}
			}
		}
		if (A.empty())
		{
		if (flag == 0)
			cout<<"NO"<<endl;
		else if (flag == 1)
			cout<<"YES"<<endl;}
		else 
			cout<<"NO"<<endl;
	}

	system("pause");
	return 0;
}
