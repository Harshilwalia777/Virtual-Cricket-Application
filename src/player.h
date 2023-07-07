#include <string>
/*Declare Player class attributes to store information such as name, unique id, runs
scored, balls played, balls bowled, runs given, and wickets taken in the match*/


class Player{
public:
	Player();
	std::string name;
	int unique_id;
	long int runs;
	long int runsGiven;
	int wickets;
	int ball_played;
	int balls_bowled;


};
