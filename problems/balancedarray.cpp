#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* abs */

using namespace std;


//Find if array is balanced by accessing each element only once. Balanced means that at an index in the array, the sum of values of lower indices = sum of alues at higher indices than
//Note that the sum of zero indices is zero so endpoints indices can be solutions. If no index then find the index that has the minimal difference between left and right sums
// Microsoft

int main(void){

	vector<int> intVector = {1, 4, 7, 8, 10, 20};

	int leftSum = 0;

	int total = 0;
	int index = 0;
	int diff = 0;
	int minDiff = 0;
	int balancedIndex;
	vector<int> arrayOfHighSums;

	//Find total first

	for (vector<int>::iterator it = intVector.begin(); it != intVector.end(); ++it){

		total += *it;
	}
	cout << "total is " << total << endl;

	for (vector<int>::iterator it = intVector.begin(); it != intVector.end(); ++it) {
		
		if (leftSum == total - *it - leftSum){

			cout << "balanced at index " << index << " with value " << intVector[index] << endl;
			return 0;
		}
		else {
			int newDiff = abs((total - *it - leftSum) - (leftSum)); //rightsum - leftsum
			if (newDiff < diff ){
				diff = newDiff;
				balancedIndex = index;
				minDiff = newDiff;
			}
			diff = newDiff;
		}
		leftSum += *it;
		index++;

	}

	cout << "NO Balance with min diff at index " << balancedIndex << " with value and diff " << intVector[balancedIndex] << " : " << minDiff << endl;


	return 0;
}