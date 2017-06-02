#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    string number;
};

class hashTable{

	public:

		int intHash(long val){
			int a = 34;
			int b = 2;
			int prime = 10000019;
			int hashValue;

			//Integer hash fcn
			hashValue = (((a*val) + b) % prime) % cardinality;
			return hashValue;
		}

		void insertPerson(string key, Person person){
			insert(key, person, foo);
		}

		long stringToNumber(string phoneNumber){
			long number;
			//Convert string to int
			for (string::iterator it = phoneNumber.begin(); it != phoneNumber.end(); ++it){
				if (*it == '-' || *it == '(' || *it == ')'){
					phoneNumber.erase(it);
				}
			}
			number = stol(phoneNumber);
			cout << phoneNumber << endl;	
			cout << number << endl;
			return number;
		}

		void insert(string key, Person person, vector<Person> *foo){
			string phoneNumber = key;
			long number;
			int hashValue;

			number = stringToNumber(phoneNumber);

			//Hash fcn
			hashValue = intHash(number);
			cout << hashValue << endl;

			foo[hashValue].push_back(person); //append the person to the vector at location hashvalue
			numItems += 1;
			rehash();
		}

		void rehash(){
			loadFactor = numItems/cardinality;
			if (loadFactor > 0.75){
			 	cardinality *= 2; //double the size
			 	vector<Person> *oldFoo = foo;
				vector<Person> *bar = new vector<Person>[cardinality];
				for (int i = 0; i < cardinality; i++){
					for (vector<Person>::iterator it = foo[i].begin(); it != foo[i].end(); ++it){
						insert((*it).number, *it, bar);
					}
				}
				foo = bar;
				delete[] oldFoo;
			}
		}

		bool hasKey(string phoneNumber){
			long number;
			int hashValue;
			vector<Person> bucket;

			number = stringToNumber(phoneNumber);
			hashValue = intHash(number);
			bucket = foo[hashValue];
			for (vector<Person>::iterator it = bucket.begin(); it != bucket.end(); ++it){
				if ((*it).number == phoneNumber){
					return true;
				}
			}
			return false;
		}

		string get(string phoneNumber){
			long number;
			int hashValue;
			vector<Person> bucket;

			number = stringToNumber(phoneNumber);
			hashValue = intHash(number);
			bucket = foo[hashValue];
			for (vector<Person>::iterator it = bucket.begin(); it != bucket.end(); ++it){
				if ((*it).number == phoneNumber){
					return (*it).name;
				}
			}
			return "NoName";
		}

		void set(string phoneNumber, string name){
			long number;
			int hashValue;

			number = stringToNumber(phoneNumber);
			hashValue = intHash(number);
			for (vector<Person>::iterator it = foo[hashValue].begin(); it != foo[hashValue].end(); ++it){
				if ((*it).number == phoneNumber){
					 (*it).name = name;
					 return;
				}
			}
			Person newPerson;
			newPerson.name = name;
			newPerson.number = phoneNumber;
			foo[hashValue].push_back(newPerson);
		}

		void remove(string phoneNumber){
			if (not hasKey(phoneNumber)){
				return;
			}

			long number;
			int hashValue;

			number = stringToNumber(phoneNumber);
			hashValue = intHash(number);
			for (vector<Person>::iterator it = foo[hashValue].begin(); it != foo[hashValue].end(); ++it){
				if ((*it).number == phoneNumber){
					foo[hashValue].erase(it);
				}
			}

		}

	private:
		int cardinality = 1000; //size of hash table
		int numItems = 0;
		vector<Person> *foo = new vector<Person>[cardinality]; //array of vectors
		float loadFactor = numItems/cardinality;
};	


int main(){

	hashTable numberToName;
	Person cathy;
	cathy.name = "Cathy";
	cathy.number = "(414)787-7890";

	numberToName.insertPerson(cathy.number, cathy);

	//Test haskey
	cout << numberToName.hasKey(cathy.number) << endl;

	//Test get
	cout << numberToName.get(cathy.number) << endl;
	
	//test set
	numberToName.set(cathy.number, "John");
	cout << numberToName.get(cathy.number) << endl;

	//test remove
	numberToName.remove(cathy.number);
	cout << numberToName.hasKey(cathy.number) << endl;

	return 0;
}
