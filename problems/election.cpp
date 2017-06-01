#include <iostream>
#include <string>
#include <vector>


using namespace std;


struct candidate {
	int votes;
	string name;

};

candidate findWinner(vector<candidate> &candidateList){

	candidate winner;
	int currentVotes = 0;
	for (vector<candidate>::iterator it = candidateList.begin(); it != candidateList.end(); ++it) {
    	if (it->votes > currentVotes){
    		currentVotes = it->votes;
    		winner = *it;
    		cout << winner.name << endl;
    	}
	}
	return winner;
}

// void sortCandidates(vector<candidate> &candidateList){

	//do a quick sort but use votes as conditions and swap the vector indices 

// }

int main(void){
	
	vector<candidate> candidateList;
	candidate winner;

	//Candidates
	candidateList.push_back(candidate());
	candidateList.push_back(candidate());
	candidateList.push_back(candidate());
	candidateList.push_back(candidate());
	candidateList.push_back(candidate());

	//Modify its name and votes.
    candidateList[0].name = "Jessica";
    candidateList[0].votes = 98;
    candidateList[1].name = "David";
    candidateList[1].votes = 45;
    candidateList[2].name = "Miguel";
    candidateList[2].votes = 98;
    candidateList[3].name = "Gina";
    candidateList[3].votes = 76;
    candidateList[4].name = "Bob";
    candidateList[4].votes = 82;
    cout << "LOL" << endl;
    winner = findWinner(candidateList);



	return 0;
}