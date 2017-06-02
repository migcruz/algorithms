#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.


// http://www.mathblog.dk/project-euler-problem-3/
// Fundamental theorem of arithmetic: Every integer > 1 is either a prime number or is a unique product of primes

string reverse(string s)
{
    int length = s.length();
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

bool isPalindrome(string x, string y){
	bool result;
	if (x == y){
		result = true;
	}
	else{
		result = false;
	}
	return result;
}

bool findPalindrome(int product){
	string intString = to_string(product);
	string intString2 = reverse(intString);
	bool result = isPalindrome(intString, intString2);
	return result;
}

int main(){
	//999*999 = 998001
	//largest palindrome 997799
	int factor = 999;
	int factor2 = 999;
	int palindrome;
	int product = factor*factor2;
	bool flag = true;
	string productString = to_string(product);
	int i = 2;
	int j = 3;

	// Make a palindrome
	if (productString[2] - '0' > productString[3] - '0'){ // -'0' converts to int
		int temp = productString[2] - '0';
		temp -= 1; //lowers the middle number by 1
		productString.replace(3, 1, to_string(temp));
		productString.replace(2, 1, to_string(temp));

		 //replace last and second last digits with first two digits to guarantee largest palindrome
		productString[productString.length() - 1] = productString[0];
		productString[productString.length() - 2] = productString[1];
		palindrome = stoi(productString);
	}

	cout << palindrome << "LOL" << endl;

	// Keep making paldinromes until one is a factorable by a 3 digit number
	while (flag){
		if (palindrome % factor == 0 && palindrome/factor <= 999){
			flag = false;
		}

		factor--;
		if (factor == 100){
			factor = 999;

			//Make a new palindrome
			int temp2;
			int temp = productString[2] - '0';
			temp -= 1;
			temp2 = temp;
			if (temp < 0){
				temp = 9;
			}
			productString.replace(3, 1, to_string(temp));
			productString.replace(2, 1, to_string(temp));
			palindrome = stoi(productString);
			cout << palindrome << endl;
			if (temp2 < 0){	
				temp = 9;
				productString.replace(3, 1, to_string(temp));
				productString.replace(2, 1, to_string(temp));

				productString.replace(1, 1, to_string((productString[1] - '0') - 1));
				productString.replace(productString.length() - 2, 1, to_string(productString[1] - '0'));
				palindrome = stoi(productString);
				cout << palindrome << "LOL" << endl;
			}

		}
		//cout << palindrome << "LOL" << endl;
	}
	factor2 = palindrome / factor;


	cout << palindrome << endl;
	cout << factor << endl;
	cout << factor2 << endl;


	//ATTEMPT AT TRYING ALL COMBINATIONS O(n^2)
	// int factor = 999;
	// int factor2 = 999;

	// while (!findPalindrome(factor*factor2)){
	// 	if (factor2 < factor){
	// 		factor--;
	// 	}
	// 	else {
	// 		factor2--;	
	// 	}
		
		
	// }

	// cout << factor*factor2 << endl;

	// NOT NEEDED CODE
	// string test = "MOM";
	// string test2;

	// test2 = reverse(test);
	// cout << test2 << endl;

	// cout << isPalindrome(test, test2) << endl;


	return 0;
}
