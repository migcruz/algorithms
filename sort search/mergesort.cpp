#include <iostream>
#include <string>
#include <vector>
using namespace std;

// O(n log n) avg, O(n^2) worst case if you pick a pivot that is the least or greatest number

void mergeHalves(vector<int> &array, vector<int> &temp, int leftStart, int rightEnd){
	int leftEnd = (rightEnd + leftStart)/2;
	int rightStart = leftEnd + 1;

	int left = leftStart; //starting point for left half
	int right = rightStart; //starting point for right half
	int index = leftStart; //current index of the new array (vector)



	while (left <= leftEnd && right <= rightEnd){
		if (array[left] <= array[right]){
			temp[index] = array[left];
			left++;
		}
		else { // copy the right element
			temp[index] = array[right];
			right++;
		}
		index++;
	}

	//Left or right are now out of bounds
	// Now copy elements
	if (left > leftEnd){
		for (int i = right; i <= rightEnd; i++){
			temp[index] = array[i];
			index++;
		}
	}
	else {
		for (int i = left; i <= leftEnd; i++){
			temp[index] = array[i];
			index++;
		}
	}

	for (int i = leftStart; i <= rightEnd; i++){
		array[i] = temp[i];
	}

};



void mergeSort(vector<int> &array, vector<int> &temp, int leftStart, int rightEnd){
	if (leftStart >= rightEnd) {
		return;
	}
	int middle = leftStart + ((rightEnd - leftStart)/2); //prevents overflow as oppsoed to normal half formula
	mergeSort(array, temp, leftStart, middle);
	mergeSort(array, temp, middle + 1, rightEnd);
	mergeHalves(array, temp, leftStart, rightEnd);
};

int main(){
	vector<int> test = {3, 4, 4, 5, 1, 9, 7, 8, 2, 0};
	vector<int> temp(test.size());
	mergeSort(test, temp, 0, test.size() - 1);
	for (vector<int>::iterator it = test.begin(); it != test.end(); ++it){
		cout << *it << endl;
	}

	return 0;
}
