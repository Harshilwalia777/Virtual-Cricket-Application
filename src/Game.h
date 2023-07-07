#include <cstdlib>
#include<ctime>
#include<limits>
#include<iostream>
#include "Team.h"//<vector>,string,player.h
/*Declare Game class attributes to store information such as team A and team B
details, players per team, maximum deliveries allowed in each innings, names of
all the 11 given players, and a variable to check which innings is going o*/
class Game
{
public:
	Game();
	int PlayerPerTeam;
	int Max_Balls;
	int Total_player;
	std::string Players[11];
	bool isFirst_innings=true;
	Team T_A,T_B;
	Team *Batting_team,*Bowling_Team;
	Player *Batsman,*Bowler;
	void welcome();
	void showAllPlayers();
	int take_integerInput();
	void selectPlayers();
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void initialisePlayers();
	void PlayInnings();
	void bat();
	bool validateInningsScore();
	void ShowGameScorecard();
	void startSecondInnings();
	void Summary();
};
