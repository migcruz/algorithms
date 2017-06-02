#include <iostream>
#include <string>
#include <vector>
using namespace std;

//The sum of the squares of the first ten natural numbers is,

//12 + 22 + ... + 102 = 385
//The square of the sum of the first ten natural numbers is,

//(1 + 2 + ... + 10)2 = 552 = 3025
//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

// Solution: http://www.mathblog.dk/project-euler-problem-6/
//Note: that brute force is easy to implement as well

int main(){

	int n = 100; //first 100 natural numbers

	int sum = (n*(n+1))/2; //sum of natural the first n natural numbers
	int sumSquared = sum*sum;

	int sumOfSquares = (n*(n+1))*((2*n)+1)/6; //sum of the squares of the first n natural numbers

	int diff = sumSquared - sumOfSquares;



	cout << diff << endl;
	return 0;
}

