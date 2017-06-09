#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* abs */
#include <unordered_map>

using namespace std;



int foo(int x){
	if (x < 0){
		return 0;
	}
	else {
		return x;
	}
}


//Refactor foo to have no conditional statements (i.e. everything must be executed)
int bar(int x){

	int msb = 0; //most significant bit
	int mask;
	unsigned int y = x;

	while (y > 1){
		y = y >> 1;
		
		//msb = y;
		cout << y << endl;
	}
	//mask = msb - 1; //either will be 0000 or 1111 (can be more bits depending on x)
	mask = y - 1; //either will be 0000 or 1111 (can be more bits depending on x)

	x = x & mask;


	return x;
}




int main(void){
	int x = -4;
	int y;

	y = foo(x);
	cout << y << " FOO" << endl;
	y = bar(x);
	cout << y << " BAR" << endl;




	return 0;
}