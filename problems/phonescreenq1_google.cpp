#include <iostream>
#include <string>
using namespace std;

int main(){

	string array[5] = {"first", "second", "third", "fourth", "fifth"};
	string temp;
	string total;
	string newArray[5];
	string divider = " ";

	// First make a big string
	for (int i = 0; i < 5; i++){
		total.append(array[i]);
		total.append(" ");
	}

	cout << total << endl;

	//Put it back in the list
	bool stop = false;
	int index = 0;
	for (string::iterator it = total.begin(); it != total.end(); ++it){
		if (*it == ' '){
			stop = true;
		}
		if (not stop){
			temp.push_back(*it);
		}
		else {
			newArray[index] = temp;
			temp.erase();
			stop = false;
			index++;
		}
	}
	cout << total << endl;

	for (int i = 0; i < 5; i++){
		cout << newArray[i] << endl;
	}

	return 0;
}

//Phone screen Q: String encoding and decoding: Design a method that converts a list of strings into a single string which can be later converted back to the list.

