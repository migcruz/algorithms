#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

//Find the the number of numbers with digit 3 in N

//Method 1: Modulo

bool hasDigit(int number, int key){

	if (number == 0){
		return false;
	}
	//int powerOf10;
	int divisor;
	int remainder;
	int quotient;
	int powerOf10;
	
	powerOf10 = floor(log10(number));
	
	divisor = pow(10, powerOf10);

	quotient = number / divisor;

	if (number == key){
	    //cout << "HAS KEY" << endl;
		return true;
	}

	if (powerOf10 == 0){
	    //cout << "NO KEY" << endl;
		return false;
	}

	if (quotient == key){
        //cout << "HAS KEY" << endl;
		return true;
	}
	else {
		remainder = number % divisor;
		return hasDigit(remainder, key);
	}


}

int main(void){

	int N = 1000;
	int sum = N;
	int counter = 0;
	int key = 3;
	
	while (sum >= 0){
		if (hasDigit(sum, key))
		{
			cout << sum  << endl;
			counter += 1;
		}
		sum -= 1;
		

	}
	

	cout << "Number of numbers is " << counter << endl;



	return 0;
}


//Method 2: closed form solution
