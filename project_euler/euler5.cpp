#include <iostream>
#include <string>
#include <vector>
using namespace std;

//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
// Solution: http://www.mathblog.dk/project-euler-problem-5/
int main(){

	int i = 20;
	 
	while (i %  2 != 0 || i %  3 != 0 || i %  4 != 0 || i %  5 != 0 ||
	         i %  6 != 0 || i %  7 != 0 || i %  8 != 0 || i %  9 != 0 ||
	         i % 10 != 0 || i % 11 != 0 || i % 12 != 0 || i % 13 != 0 ||
	         i % 14 != 0 || i % 15 != 0 || i % 16 != 0 || i % 17 != 0 ||
	         i % 18 != 0 || i % 19 != 0 || i % 20 != 0) {
	    i += 20; //only need to check every 20 increments
	}

	cout << i << endl;
	return 0;
}









// int main(){
// 	int small = 1;
// 	int large = 10;
// 	int currentFactor = small;

// 	long smallestProduct = small;
// 	bool flag = true;
// 	bool flag2 = true;
// 	while (flag){

// 		// 1*2*3*4*5 etc
// 		smallestProduct *= currentFactor;
// 		cout << smallestProduct << endl;


// 		//Find the number that is factorable by all numbers (this may not be the smallest)
// 		int i = large;
// 		while (i > currentFactor){
// 			if (smallestProduct % i == 0){
// 				flag = false;
// 				i--;
// 			}
// 			else {
// 				flag = true;
// 				break;
// 			}
// 		}

// 		currentFactor++;

// 	}

// 	cout << "LOL" << endl;

// 	flag = true;
// 	while (flag){
// 		smallestProduct = smallestProduct/2;
// 		cout << "LOL2" << endl;
// 		int i = large;
// 		while (i > 1){
// 			if (smallestProduct % i == 0){
// 				flag = true;
// 				i--;
// 			}
// 			else {
// 				flag = false;
// 				cout << i << endl;
// 				break;
// 			}
// 		}
// 	}
	

// 	cout << smallestProduct*2 << endl;




// 	return 0;
// }