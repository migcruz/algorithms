#include <iostream>
#include <string>
using namespace std;

//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.
//soln: https://math.stackexchange.com/questions/9259/find-the-sum-of-all-the-multiples-of-3-or-5-below-1000
int main ()
{
	int sum3;
	int sum5;
	int totalsum = 0;
	int n = 1;
	int m = 1;
	bool flag = true;
	while (flag)
	{
		sum3 = 3*n;

		if (5*m < 1000)
		{
			sum5 = 5*m;
		}
		else
		{
			sum5 = 0; //Stop adding multiples of 5
		}
		
		if (n % 5 == 0) //Divisble by 5 therefore ignore
		{
			totalsum = totalsum + sum5;
		}
		else
		{
			totalsum = totalsum + sum5 + sum3;
		}
		n = n + 1;
		m = m + 1;
		
		if (3*n > 1000)
		{
			flag = false;
		}
			
	}
	cout << totalsum << endl;
	return 0;
}