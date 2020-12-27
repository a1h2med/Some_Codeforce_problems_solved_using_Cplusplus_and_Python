// solution to problem 507/A codeforces.

#include <iostream>

using namespace std;

void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void print_array(int arr[], int startIndex, int endIndex);

int main() {
	int Number_of_instruments, Number_of_free_days;
	int days_for_each_instrument[100];
	int sum = 0;
	cin >> Number_of_instruments >> Number_of_free_days;
	for (int i = 0; i < Number_of_instruments; i++) {
		int temp;
		cin >> temp;
		days_for_each_instrument[i] = temp;
	}
	if (Number_of_instruments == 1 && Number_of_free_days < days_for_each_instrument[0]) {
		cout << 0 << endl;
		system("pause");
		return 0;
	}
	quickSort(days_for_each_instrument, 0, Number_of_instruments-1);
	for (int i = 0; i < Number_of_instruments; i++) {
		if (sum > Number_of_free_days) {
			cout << i - 1 << endl;
			print_array(days_for_each_instrument, 0, i - 1);
			system("pause");
			return 0;
		}
		else{
			sum += days_for_each_instrument[i];
			continue;
		}
	}
	cout << Number_of_instruments << endl;
	print_array(days_for_each_instrument, 0, Number_of_instruments);
	system("pause");
	return 0;
}

void print_array(int arr[], int startIndex, int endIndex) {
	for (int i = startIndex; i < endIndex; i++) {
		cout << arr[i] << " ";
	}
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}