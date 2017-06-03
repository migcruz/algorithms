#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>

//4 teams are playing in 3 game days. Make a an algoithm so that at the end of day 3 each team ahs played every other team
using namespace std;

struct team{
	string name;
	//vector<team> teamsplayed;
	int teamid;
	int gamesWon;

};

struct match{
	team team1;
	team team2;
};

match playGame(match game){
	int x;
	srand(time(0));
	x = rand() % 2;
	if (x == 0){
		game.team1.gamesWon += 1;

	}
	else {
		game.team2.gamesWon += 1;
	}
	//cout << game.team1.gamesWon << "LOL" << endl;
	//cout << game.team2.gamesWon << "LOL" << endl;
	return game;
};




int main(void){

	vector<team> teamList;
	queue<team> group1;
	queue<team> group2;

	//Initialize teams
	teamList.push_back(team());
	teamList.push_back(team());
	teamList.push_back(team());
	teamList.push_back(team());

    teamList[0].name = "team1";
    teamList[0].teamid = 0;
    teamList[0].gamesWon = 0;
    teamList[1].name = "team2";
    teamList[1].teamid = 1;
    teamList[1].gamesWon = 0;
    teamList[2].name = "team3";
    teamList[2].teamid = 2;
    teamList[2].gamesWon = 0;
    teamList[3].name = "team4";
    teamList[3].teamid = 3;
    teamList[3].gamesWon = 0;

    group1.push(teamList[0]);
    group1.push(teamList[1]);
    group2.push(teamList[2]);
    group2.push(teamList[3]);

    for (int day = 0; day < 2; day++) {
    	match game;
    	team temp;
    	vector<team>::iterator it = teamList.begin();


    	game.team1 = teamList[0];
    	game.team2 = teamList[1];

    	game = playGame(game);
    	teamList[0] = game.team1;
    	teamList[1] = game.team2;
    	//cout << teamList[0].gamesWon << "KEK" << endl;
		//cout << teamList[1].gamesWon << "KEK" << endl;

    	// Second game of the day
    	game.team1 = teamList[2];
    	game.team2 = teamList[3];

    	game = playGame(game);
    	teamList[2] = game.team1;
    	teamList[3] = game.team2;
    	
    	//Swap positions to get new unique pairs, if more than 4 then split into groups and do this again
    	temp = teamList[3];
    	teamList.pop_back();
    	teamList.insert(it + 1, temp);

    }

    for (vector<team>::iterator it = teamList.begin(); it != teamList.end(); ++it) {
    	cout << it->name << " has won " << it->gamesWon << " games" << endl;

    }

	return 0;
}