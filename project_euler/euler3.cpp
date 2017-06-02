#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?


// http://www.mathblog.dk/project-euler-problem-3/
// Fundamental theorem of arithmetic: Every integer > 1 is either a prime number or is a unique product of primes
int main()
{
	const long numm = 600851475143;
	long newnumm = numm;
	long largestFact = 0;
	 
	int counter = 2;
	while (counter * counter <= newnumm) { //up to sqrt(n) no need to check for factors bigger than that because they would have been covered earlier
	    if (newnumm % counter == 0) { //therefore divisible by counter then you test the newnumm if it is a prime number using the same counter (test with 92 on paper)
	        newnumm = newnumm / counter;
	        largestFact = counter;
	    } else {
	        counter++;
	    }
	}
	if (newnumm > largestFact) { // the remainder is a prime number
	    largestFact = newnumm;
	}
	cout << largestFact << endl;
	return 0;
}



// Sieve of eratosthenes https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes


/* doesnt work due to size of memory alloc
int main ()
{
	bool flag = true;
	long int n = 600851475143;
	double sqrt_n = sqrt(n);
	vector<bool> sieve(n+1, true);
	for (int i = 2; i <= sqrt_n; i++)
	{
		if (sieve[i] == true)
		{
			for (int j = i*i; j <= n; j += i)
			{
				sieve[j] = false;
			}
		}
	}
    cout << n << endl;
	while (flag)
	{
		int i = sieve.size() - 1;

		if (sieve[i] == true)
		{
			cout << i << endl;
			flag = false;
		}
	}


	
	return 0;
}*/



https://www.tesla.com/en_CA/careers/job/associate-manufacturingengineergigafactory-45266
https://www.tesla.com/en_CA/careers/job/chassis-controlsystemstestengineer-42635
https://www.tesla.com/en_CA/careers/job/engineer-vehicledesignintegration-31229
https://www.tesla.com/en_CA/careers/job/fastener-engineer-45435
https://www.tesla.com/en_CA/careers/job/mechanical-designengineer-19667
https://www.tesla.com/en_CA/careers/job/mechanical-designengineer-batterymodule-38873
https://www.tesla.com/en_CA/careers/job/mechanical-designengineer-thermalsystemsandhvac-42707
https://www.tesla.com/en_CA/careers/job/mechanical-engineer-engineeringtestandanalysis-25707