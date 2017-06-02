#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Random generate a NxN matrix with only four types of element: 1,2,3,4. 
//However, no column or row can have same type of element appears 3 times or above continuously 
//(three same type of elements are connected)

int main(){

	int arr[] = {1, 2, 3, 4};
	int row  = 4;
	int col = row;

	int matrix[row][col];

	for (int i = 0; i < row; i++){
		if (i % 2 == 0){ //row number is even
			for (int j = 0; j < col; j++){
				matrix[i][j] = arr[j];
			}
			cout << "LOL" << endl;
		}
		else{
			for (int j = 0; j < col; j++){
				matrix[i][j] = arr[col - 1 -j];
			}
		}		 
	}

	for (int i = 0; i < row; i++){ 
		for (int j = 0; j < col; j++){
			cout << matrix[i][j];
		}
		cout << endl;
	}


	return 0;
}