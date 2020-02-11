/******       authot => Ahmed Ashraf    ******/
/******       This is a solution for (Thanos Problem) on codeforces     ******/


#include <iostream>
#include <string>
#include "math.h"

using namespace std;

void converting_string_to_int(string input, int* output_array);

int main(){
	int array_size = 0;
	string input_string;
	
	cin>>array_size;

	// it also can be cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.ignore();
	getline(cin,input_string);
	
	// made it to handle inputs like (0 40 or 1 200)
	if (array_size == 0 || array_size == 1){
		cout<<array_size<<endl;
		return 0;	
	}
	
	// dynamic output array in which the process will loop on
	int* output_array;
	output_array = new int[array_size];

	// converting input string to int array, saving the output to output array
	converting_string_to_int(input_string,output_array);

	// this is a temp dynamic array which I made to copy the data to it
	int* new_output_array;

	for (int i = 0 ;i<array_size-1;i++){
		
		// checking whether elements are less than or equal each other or not 
		if (output_array[i] <= output_array[i+1]){
			continue;
		}

		// if not so I will cut half of the array
		else {

			// getting the new size of the array after cutting it
			int new_array_size = array_size/2;
			new_output_array = new int[new_array_size];

			// cutting the array and putting it into my temp array
			for (int j = 0 ;j<new_array_size;j++){
				new_output_array[j] = output_array[j];
				}

			// here I deleted the output_array as I no longer need it and inintialized a new size of it 
			delete[] output_array;
			output_array = new int[new_array_size];

			// here I'm copying the contents of the temp array into the original one
			// then I'll delete the contents of the temp array (to save memory)
			for (int j = 0 ;j<new_array_size;j++){
				output_array[j] = new_output_array[j];
				}
			delete[] new_output_array;

			// reinitializing the size of the array(and the loop as well)
			array_size = new_array_size;
			// to start from 0 in the next count
			i = -1;
			}
	}

	cout<<array_size<<endl;


	system("pause");
	return 0;
}


/**********            this Function simply takes two inputs,1- Output array,2- input string            **********/
/**********            It's input sequence shoud be 1 2 3 4,It doesn't handle ( ( , ) , commas )            **********/
/**********            If you want to edit this code to handle commas and (,) just edit the conditions            **********/
void converting_string_to_int(string input, int* output_array){
	
	// l is a counter for the array
	int l = 0;

	// this for loop is made to loop on all of the string
	for (int i = 0; i<input.length(); i++){
		
		// to start cutting we should find a space in our input string which seperates between two numbers
		// you can handle commas and ( by adding them to this condition
		if (input[i] == ' '){

			// it's a counter made to loop back from when we found the space till the (previous space or the beginning of the code)
			int j = i-1;

			// it's a string where we will store the output of cutting process (which will be inverted)
			string inverted_cut;

			// it's a string to save the final cutted output
			string Cutted;
			
			// this is the condition of the counter which I illustrated earlier
			// If you want to edit this code to handle commas and ( you should start adding commas here and ( in the coming check
			while(input[j] != ' '){

				// here I just taking the input and adding it
				// as you can see I'm adding it vice versa
				inverted_cut += input[j];
				j--;
			
				// this condition is made to handle the beginning of the code(as I don't have either ( or ' ' to know the start of it)
				// You should add ( here if you want to edit this code handling
				if (j < 0)
					break;
			}

			// this loop is just made to get the right string
			for (int k=inverted_cut.length()-1;k>=0;k--){
				Cutted += inverted_cut[k];
			}

			// here I'm converting the string into integer and saving it into the output array 
			output_array[l] = stoi(Cutted);
			l++;
		}

		// this condition is made to handle the last number
		// if you want to handle (,),commas just add ) here or edit (int j = i; to int j = i-1;)
		else if (i == input.length()-1){
			int j = i;
			string inverted_cut;
			string Cutted;
			inverted_cut += input[j];
			j--;
			while(1){
			if (input[j] == ' ')
				break;
			else 
			{	inverted_cut += input[j];
				j--;
			}
			}
			for (int k=inverted_cut.length()-1;k>=0;k--){
				Cutted += inverted_cut[k];
			}
			output_array[l] = stoi(Cutted);
			l++;

		}
	}
}

