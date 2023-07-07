#include <vector>
#include"player.h"//<string>
/*Declare Team class attributes to store information such as team name, total runs
scored by the team, total wickets lost, total balls bowled, and list of team players*/
class Team{
public:
	Team();
	std::string team_name;
	double total_runs;
	double total_wic;
	double total_balls;
	std::vector<Player> players;
};
