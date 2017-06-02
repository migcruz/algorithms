#include <iostream>
#include <vector>
using namespace std;

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

bool binarySearchRecursive(vector<int> &array, int x, int left, int right){
	//Array must be sorted first

	if (left > right){
		return false;
	}
	int mid = left + ((right - left) / 2); // prevents overflow vs (right + left) /2
	if (array[mid] == x){
		return true;
	}
	else if (x < array[mid]){
		return binarySearchRecursive(array, x, left, mid -1);
	}
	else {
		return binarySearchRecursive(array, x, mid + 1, right);
	}
}

bool binarySearchIterative(vector<int> &array, int x){
	//Array must be sorted first

	if (left > right){
		return false;
	}
	int left = 0;
	int right = array.size() - 1;

	while (left <= right){
		int mid = left + ((right - left) / 2);
		if (array[mid] == x){
			return true;
		}
		else if (x < array[mid]){
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return false;

}

bool binarySearchR(vector<int> &array, int x){

	return binarySearchRecursive(array, x, 0, array.size() - 1);
}

int main(){

	vector<int> test = {3, 4, 4, 5, 1, 9, 7, 8, 2, 0};
	quickSort(test, 0, test.size() - 1);
	for (vector<int>::iterator it = test.begin(); it != test.end(); ++it){
		cout << *it << endl;
	}

	cout << binarySearchR(test, 5) << endl;	
	cout << binarySearchIterative(test, 5) << endl;	

	cout << binarySearchR(test, 12) << endl;	
	cout << binarySearchIterative(test, 22) << endl;	

	return 0;
}