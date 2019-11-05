#include <iostream>
#include <vector>
using namespace std;


int main(){
	int input_edges , input_nodes , temp_data1 , temp_data2 , flag = 0 , counter = 0;
	cin>>input_nodes>>input_edges;
	vector<vector<int>> Operation (input_edges);
	
	for (int i=0;i<input_edges;i++)
	{
		cin>>temp_data1>>temp_data2;
		Operation[counter] = vector<int> (2); 
		Operation[counter][0] = temp_data1;
		Operation[counter][1] = temp_data2;
		if (counter!=0){
			for (int j=0;j<counter;j++){
			if (temp_data1 == Operation[j][1]){
				if (temp_data2 == Operation[j][0]){
					Operation.erase(Operation.begin()+counter-1);
					if (j == 0)
						Operation.erase(Operation.begin()+j);
					else 
						Operation.erase(Operation.begin()+j-1);
					counter = counter-2;
				}
			}
			else
				continue;
		} }
		counter++;
	}

	if ((input_nodes*(input_nodes-1)) == input_edges){
		flag = 1;
		cout<<"BOTH"<<endl;
		goto Exit;
	}
	if (input_edges == 0){
		flag = 1;
		cout<<"BOTH"<<endl;
		goto Exit;
	}
	if (Operation.empty())
		cout<<"BOTH"<<endl;
	else if (!Operation.empty()) 
		cout<<"DIR"<<endl;
	if (flag == 1){
Exit:
	system("pause");
	return 0;
	}
	system("pause");
	return 0;
}
