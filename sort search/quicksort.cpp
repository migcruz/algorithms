#include <iostream>
#include <string>
#include <vector>
using namespace std;

// O(n log n) avg, O(n^2) worst case if you pick a pivot that is the least or greatest number

int partition(vector<int> &array, int left, int right, int pivot){
	while (left <= right) {
		while (array[left] < pivot){
			left += 1;
		}
		while (array[right] > pivot){
			right -= 1;
		}
		if (left <= right){
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left += 1;
			right -= 1;
		}
	}
	return left;
};

void quickSort(vector<int> &array, int left, int right){
	if (left >= right) {
		return;
	}
	int pivot = array[(left + right)/2]; //try to find median instead but this will do for now
	int index = partition(array, left, right, pivot);
	quickSort(array, left, index - 1);
	quickSort(array, index, right);
};

int main(){
	vector<int> test = {3, 4, 4, 5, 1, 9, 7, 8, 2, 0};
	quickSort(test, 0, test.size() - 1);
	for (vector<int>::iterator it = test.begin(); it != test.end(); ++it){
		cout << *it << endl;
	}

	return 0;
}
