#include "Game.h"
using namespace std;
Game::Game(){
	isFirst_innings=false;
	T_A.team_name="team-A";
	T_B.team_name="team-B";
	PlayerPerTeam=4;
	Max_Balls=6;
    Total_player=11;
    Players[0]="Virat";
    Players[1]="Sachin";
    Players[2]="Jadeja";
    Players[3]="Hardik";
    Players[4]="Bumrah";
    Players[5]="Risabh";
    Players[6]="Tommy";
    Players[7]="Rusell";
    Players[8]="Chris";
    Players[9]="Smith";
    Players[10]="Starc";
};
void Game::welcome(){
	cout<<"-----------------------------------------------------";
	cout<<"\n|=====================CRIC-IN==================|";
	cout<<"\n|							|";
    cout<<"\n|	Welcome to Virtual Cricket Game|";
    cout<<"\n-----------------------------------------------\n\n";
    cout<<"-----------------------------------------------------";
    cout<<"\n|=====================INSTRUCTIONS==============|";
    cout<<"\nCreate 2 Teams (Team A and Team B with 4";
    cout<<"\nPlayers each) from given pool of 11 Players";
    cout<<"\n2. Lead the toss and decide the choice of play.";
    cout<<"\nEach innings will be of 6 balls.";
}

void Game::showAllPlayers(){
	cout<<"-----------------------------------------------------";
	cout<<"\n|================POOL OF PALYERS==================|\n";
	cout<<"-----------------------------------------------------\n\n";

	for(int i=0;i<11;i++){
      cout<<"\t["<<i<<"]"<<Players[i]<<endl;
	}
}
int Game::take_integerInput(){
 int n;

 while(!(cin>>n)){//this expression also return a boolean value
	 cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(),'\n');
	 cout<<"Invalid input! Please try again with  valid input";
 }
 return n;
}
void Game::selectPlayers(){
	cout<<endl;
	cout<<"-----------------------------------------";
	cout<<"\n|select 4 players for team-a and team-b|";
	cout<<"\n------------------------------------------";
	for(int i=0;i<PlayerPerTeam;i++){
		//add player to team A
		TeamAselection:
			cout<<endl<<"Select player"<<i+1<<"of Team-A-";
			int playerIndexTeamA=take_integerInput();
			if(playerIndexTeamA<0||playerIndexTeamA>10){

				goto TeamAselection;
			}
			else if((this->Players[playerIndexTeamA].compare("0"))==0){
				cout<<"Player got selected,Please select another player";
				goto TeamAselection;
			}
			else{

			Player teamAplayer;
			teamAplayer.unique_id=playerIndexTeamA;
			teamAplayer.name=Players[playerIndexTeamA];
			T_A.players.push_back(teamAplayer);
			this->Players[playerIndexTeamA]="0";
			}
		//add player to Team B
		TeamBselection:
				cout<<endl<<"Select player"<<i+1<<"of Team-B-";

				int playerIndexTeamB=take_integerInput();

				if(playerIndexTeamB<0||playerIndexTeamB>10){
						goto TeamBselection;
				}
					else if((this->Players[playerIndexTeamB].compare("0"))==0){
								cout<<"Player got selected, select another player";
								goto TeamBselection;
					}
				else{
						Player teamBplayer;
						teamBplayer.unique_id=playerIndexTeamB;
						teamBplayer.name=Players[playerIndexTeamB];
						T_B.players.push_back(teamBplayer);
						this->Players[playerIndexTeamB]="0";

			}
}
}
void Game::showTeamPlayers(){
	cout<<" --------------------------------\t\t\t\t\t-------------------------------------\n\n";
	cout<<"|=========  Team-A  =========|  \t\t\t\t\t   |=========  Team-B  =========|";
	cout<<"\n--------------------------------\t\t\t\t  -------------------------------------\n\n";
    for(int i=0;i<PlayerPerTeam;i++){
     cout<<"\n"<<"["<<T_A.players[i].unique_id<<"]"<<T_A.players[i].name<<"\t\t\t\t\t\t\t\t\t"<<"["<<T_B.players[i].unique_id<<"]"<<T_B.players[i].name;
    }
}
void Game::toss(){
srand(time(NULL));
int a=rand()%2;
switch(a){
case 0:
	cout<<"\nTeam-A has won the toss";
	tossChoice(T_A);
	break;

case 1:
	cout<<"\nTeam-B has won the toss";
	tossChoice(T_B);
	break;
}
}
void Game::tossChoice(Team WinnerTeam){
	cout<<"Enter 1 to Bat or 2 to bowl first. "<<endl
			<<"1.Bat"<<endl
			<<"2.Bowl"<<endl;
		int tossInput=take_integerInput();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		switch(tossInput){
		case 1:
			cout<<endl<<WinnerTeam.team_name<<"won the toss and choose to bat first"<<endl<<endl;
			if(WinnerTeam.team_name.compare("team-A")==0){
			Batting_team=&T_A;
			Bowling_Team=&T_B;
			}
			else{
				Batting_team=&T_B;
				Bowling_Team=&T_A;
			}

			break;
		case 2:
			cout<<endl<<WinnerTeam.team_name<<"won the toss and choose to bowl first"<<endl<<endl;
			if(WinnerTeam.team_name.compare("team-A")==0){
					Batting_team=&T_B;
					Bowling_Team=&T_A;
					}
					else{
						Batting_team=&T_A;
						Bowling_Team=&T_B;
					}
			break;
		default:
			cout<<endl<<"Invalid Input Please Try again"<<endl<<endl;
			tossChoice(WinnerTeam);
		}
}
void Game::startFirstInnings(){
	cout<<"\t\t|| First Inning Starts||"<<endl<<endl;
	isFirst_innings=true;
	initialisePlayers();
	PlayInnings();
}
void Game:: initialisePlayers(){
    Batsman=&Batting_team->players[0];
    Bowler=&Bowling_Team->players[0];
    cout<<Batting_team->team_name<<" - "<<Batsman->name<<" is batting "<<endl;
    cout<<Bowling_Team->team_name<<" - "<<Bowler->name<<" is Bowling"<<endl<<endl;

}
void Game::PlayInnings(){

	for(int i=0;i<Max_Balls;i++){

		cout<<"Enter to Bowl.";
		fflush(stdout);
	    getchar();
		cout<<"\nBowling..."<<endl;
		bat();
		if(!(validateInningsScore())){
			break;
		}
	}

}
void Game::bat(){
	srand(time(NULL));
	int runsScored=(rand()%7);

	//Update batting team and batsman Score
	Batsman->runs+=runsScored;
	Batting_team->total_runs=Batting_team->total_runs+runsScored;
	Batsman->ball_played+=1;
	//update bowling team and bowler
	Bowler->balls_bowled+=1;
	Bowling_Team->total_balls+=1;
	Bowler->runsGiven+=runsScored;
if(runsScored!=0){
	cout<<endl<<Bowler->name<<" to "<<Batsman->name<<" "<<runsScored<<" runs!"<<endl<<endl;
	ShowGameScorecard();
}
else{
	cout<<endl<<Bowler->name<<" to "<<Batsman->name<<"  OUT!  "<<endl<<endl;
	Batting_team->total_wic+=1;
	Bowler->wickets+=1;
	ShowGameScorecard();
	int nextPlayerIndex=Batting_team->total_wic;
	Batsman=&Batting_team->players[nextPlayerIndex];
}

}
bool Game::validateInningsScore(){
	if (isFirst_innings==true){
		if(Batting_team->total_wic==PlayerPerTeam||Bowling_Team->total_balls==Max_Balls){
			cout<<"\t\t||FIRST INNINGS ENDS ||| "<<endl<<endl;
			cout<<Batting_team->team_name<<" "<<Batting_team->total_runs<<" - "
					<<Batting_team->total_wic<<"("<<Bowling_Team->total_runs+1<<") "<<"Runs to win the match"<<endl<<endl;
			isFirst_innings=false;
		}

	}
	else{
         if((Batting_team->total_runs)>(Bowling_Team->total_runs)){
        	 cout<<Batting_team->team_name<<" Has WON THE MATCH"<<endl<<endl;
          return false;
         }
         if((Batting_team->total_runs)==(Bowling_Team->total_runs)){
        	 cout<< "MATCH IS TIED"<<endl<<endl;
        	 return false;
         }

		}

return true;
}
void Game::ShowGameScorecard(){
	cout<<"--------------------------------------------------------------------------------------";
	cout<<"\n\t"<<Batting_team->team_name<<" "<<Batting_team->total_runs<<" - "
						<<Batting_team->total_wic<<"("<<Bowling_Team->total_balls<<") | "<<Batsman->name
						<<" "<< Batsman->runs<<"("<<Batsman->ball_played<<") \t"<<
						Bowler->name<<" "<<Bowler->balls_bowled<<" - "<<Bowler->wickets<<"\t"<<endl<<endl;
	cout<<"---------------------------------------------------------------------------------------"<<endl<<endl;
}
void Game::startSecondInnings(){
	cout<<"\t\t|| Second Inning Starts||"<<endl<<endl;
		Team *temp;
		//swapping two Pointers
		temp=Batting_team;
		Batting_team=Bowling_Team;
		Bowling_Team=temp;
		initialisePlayers();
		PlayInnings();
		 if((Batting_team->total_runs)<(Bowling_Team->total_runs)&&Batting_team->total_balls==6){
		              	 cout<<Bowling_Team->team_name<<" Has WON THE MATCH"<<endl<<endl;
		       }
}
void Game::Summary(){
	cout<<"|||\t\t\tMATCH ENDS\t\t\t|||"<<endl<<endl;

	cout<<T_A.team_name<<"  "<<T_A.total_runs<<" - "<<"("<<T_A.total_balls<<")"<<endl;
	cout<<"========================================================"<<endl;
	for(int i=0;i<PlayerPerTeam;i++){
	cout<<"Player\t\tBatting\t\tBowling"<<endl;;
	cout<<"--------------------------------------------------------"<<endl;
	cout<<"["<<i<<"]"<<T_A.players[i].name<<"\t"<<T_A.players[i].runs<<"("<<T_A.players[i].ball_played<<")"
			<<"\t       "<<T_A.players[i].balls_bowled<<" - "<<T_A.players[i].runsGiven<<" - "<<T_A.players[i].wickets<<endl;
	}
	cout<<endl;
	cout<<T_B.team_name<<"  "<<T_B.total_runs<<" - "<<"("<<T_B.total_balls<<")"<<endl;
		cout<<"========================================================"<<endl;
		for(int i=0;i<PlayerPerTeam;i++){
		cout<<"Player\t\tBatting\t\tBowling"<<endl;;
		cout<<"--------------------------------------------------------"<<endl;
		cout<<"["<<i<<"]"<<T_B.players[i].name<<"\t"<<T_B.players[i].runs<<"("<<T_B.players[i].ball_played<<")"
				<<"\t      "<<T_B.players[i].balls_bowled<<" - "<<T_B.players[i].runsGiven<<" - "<<T_B.players[i].wickets<<endl;
		}
}
