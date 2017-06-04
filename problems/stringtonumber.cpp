#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* abs */
#include <unordered_map>

using namespace std;


//Find if array is balanced by accessing each element only once. Balanced means that at an index in the array, the sum of values of lower indices = sum of alues at higher indices than
//Note that the sum of zero indices is zero so endpoints indices can be solutions. If no index then find the index that has the minimal difference between left and right sums
// Microsoft

int main(void){

	//Dictionary of string to numbers up to 999 999 999
	unordered_map<string, int> stringToNumberDict = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"ten", 10},
        {"eleven", 11},
        {"twelve", 12},
        {"thirteen", 13},
        {"fourteen", 14},
        {"fifteen", 15},
        {"sixteen", 16},
        {"seventeen", 17},
        {"eighteen", 18},
        {"nineteen", 19},
        {"twenty", 20},
        {"thirty", 30},
        {"forty", 40},
        {"fifty", 50},
        {"sixty", 60},
        {"seventy",70},
        {"eighty", 80},
        {"ninety", 90},
        {"hundred", 100},
        {"thousand",1000},
        {"million", 1000000}

    };

    unordered_map<string, int> subset_TY = {
        {"twenty", 20},
        {"thirty", 30},
        {"forty", 40},
        {"fifty", 50},
        {"sixty", 60},
        {"seventy",70},
        {"eighty", 80},
        {"ninety", 90}
    };

    unordered_map<string, int> subset_consts = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"ten", 10},
        {"eleven", 11},
        {"twelve", 12},
        {"thirteen", 13},
        {"fourteen", 14},
        {"fifteen", 15},
        {"sixteen", 16},
        {"seventeen", 17},
        {"eighteen", 18},
        {"nineteen", 19}
    };

    unordered_map<string, int> subset_teens = {
        {"ten", 10},
        {"eleven", 11},
        {"twelve", 12},
        {"thirteen", 13},
        {"fourteen", 14},
        {"fifteen", 15},
        {"sixteen", 16},
        {"seventeen", 17},
        {"eighteen", 18},
        {"nineteen", 19}
    };

    unordered_map<string, int> subset_magnitude = {
        {"hundred", 100},
        {"thousand",1000},
        {"million", 1000000}

    };


    int total = 0;

    string temp = "LOL"; //store key tmeporarily
	string stringNumber = "one million two hundred thousand fifty seven";
	string key;
	vector<string> keys;
	bool stop = false;
	for (string::iterator it = stringNumber.begin(); it != stringNumber.end(); ++it){
		if (*it == ' '){
			stop = true;
		}
		if (not stop){
			key.push_back(*it);
		}
		else {
			keys.push_back(key);
			key.erase();
			stop = false;
		}
	}
	keys.push_back(key); //push in last key

	//Check if dict works
	for (vector<string>::iterator it = keys.begin(); it != keys.end(); ++it){
		cout << stringToNumberDict[*it] << endl;

	}

	//Check if dict works
	for (vector<string>::iterator it = keys.begin(); it != keys.end(); ++it){

		int x;
		if (subset_TY.find(temp) != subset_TY.end()){ //in dict subset of twenty, thirty etc

			if (subset_consts.find(*it) != subset_consts.end()){ 

				if (subset_teens.find(*it) != subset_teens.end()){
					cout << "ERROR1" << endl;
					return -1; //error
				}

				x = stringToNumberDict[temp] + stringToNumberDict[*it];
				total += x;
			}

			else { //in magnitude
				

				x = stringToNumberDict[temp] * stringToNumberDict[*it];
				total += x;
			}
			
		}
		else {

			if (subset_magnitude.find(temp) != subset_magnitude.end()){

				if (subset_magnitude.find(*it) != subset_magnitude.end()){

					cout << "ERROR2" << endl;
					return -1; //error dbl magnitude
				}
				// else {

					
				// }
			}

		}

		temp = *it;





		

	}


	


	return 0;
}