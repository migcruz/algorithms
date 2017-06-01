#include <iostream>
#include <string>
using namespace std;

//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?


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

https://www.tesla.com/en_CA/careers/job/associate-manufacturingengineergigafactory-45266
https://www.tesla.com/en_CA/careers/job/chassis-controlsystemstestengineer-42635
https://www.tesla.com/en_CA/careers/job/engineer-vehicledesignintegration-31229
https://www.tesla.com/en_CA/careers/job/fastener-engineer-45435
https://www.tesla.com/en_CA/careers/job/mechanical-designengineer-19667
https://www.tesla.com/en_CA/careers/job/mechanical-designengineer-batterymodule-38873
https://www.tesla.com/en_CA/careers/job/mechanical-designengineer-thermalsystemsandhvac-42707
https://www.tesla.com/en_CA/careers/job/mechanical-engineer-engineeringtestandanalysis-25707