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
	int gamesWon = 0;

};

struct match{
	team team1;
	team team2;
	team winner;
	team loser;
};

match playGame(match game){

	srand(time(0));
	int x == rand() % 2;
	if (x == 0){
		game.winner = game.team1;
		game.loser = game.team2;
		game.winner.gamesWon += 1;

	}
	else {
		game.winner = game.team2;
		game.loser = game.team1;
		game.winner.gamesWon += 1;
	}

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
    teamList[1].name = "team2";
    teamList[1].teamid = 1;
    teamList[2].name = "team3";
    teamList[2].teamid = 2;
    teamList[3].name = "team4";
    teamList[3].teamid = 3;

    group1.push(teamList[0]);
    group1.push(teamList[1]);
    group2.push(teamList[2]);
    group2.push(teamList[3]);

    for (int day = 0; day < 2, day++) {
    	match game;
    	team temp;
    	vector<team>::iterator it;


    	game.team1 = teamList[0];
    	game.team2 = teamList[1];

    	game = playGame(game);

    	game.team1 = teamList[2];;
    	game.team2 = teamList[3];;

    	game = playGame(game);
    	
    	temp = teamList[0];
    	teamList[0] = teamList


    }

	return 0;
}