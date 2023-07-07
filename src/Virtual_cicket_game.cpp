#include "game.h"

using namespace std;

int main() {
	Game game;
	game.welcome();
	cout << "\n\nPress Enter to Continue";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	game.showAllPlayers();
	cout << "\n\nPress Enter to Continue";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	game.selectPlayers();
	game.showTeamPlayers();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "\n\nPress Enter to toss";
	system("CLS");
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<"\nTossing The coin....";
	struct timespec delay;
	    delay.tv_sec = 5;                  // Delay of 0 seconds
	    delay.tv_nsec = 500000000; // Delay of 0.5 seconds (500 milliseconds)

	nanosleep(&delay , NULL);
	game.toss();
	game.startFirstInnings();
	game.startSecondInnings();
	game.Summary();
	return 0;
}
