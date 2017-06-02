#include <iostream>
#include <string>
using namespace std;

int main(){
    //bit shift
	int x = 6;
	int y = x << 1;
	cout << y << endl;
	
	//mask
	int a = 0b00010001;
	int mask = 0b11101111;
	int b = a & mask;
	cout << a << " " <<  mask << " " << b << endl;
	
	return 0;
}



