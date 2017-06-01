#include <iostream>
#include <string>
using namespace std;

//Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
//1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
//soln: //soln: http://www.mathblog.dk/project-euler-problem-2/


int main ()
{
	int current_term = 1;
	int previous_term = 0;
	int next_term;
	int sum = 0;
	bool flag = true;
	
	while (flag)
	{
		next_term = current_term + previous_term;
		if (next_term < 4000000)
		{
			if (next_term % 2 == 0) //Even number
			{
				sum = sum + next_term;
			}
			
			// Update
			previous_term = current_term;
			current_term = next_term;
		}
		else
		{
			flag = false;
		}
		
	}
	cout << sum << endl;
	return 0;
}

//OR more elegant way (only add every 3rd term)
/*
 l on*g fib3 = 2;
 long fib6 = 0;
 long result = 2;
 long summed = 0;
 
 while (result < 4000000) {
	 summed += result;
	 
	 result = 4*fib3 + fib6;
	 fib6 = fib3;
	 fib3 = result;
	 }*/