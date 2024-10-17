//main pleae
#include <iostream>

#include "team.h"

using namespace std;

int main() {
	//test 
	cout << "worked 12" << endl;
	
	cout << "//Team name is test and size is 3" << endl;
	Team team("test",3);

	cout << "//Return Team Name" << endl;
	cout <<"team Name" <<team.setTeamName() << endl;

	cout << "//adding 2 players" << endl;
	team.addTeammate("myles");
	team.addTeammate("player2");

	cout << team.toString() << endl;

	cout << "//Delete Player2" << endl;
	team.deleteTeammate("player2");

	cout << team.toString() << endl;

	cout << "//copy team" << endl;
	string* copy = team.copyConstuctor();
	Team secondTeam("string",copy);
	cout << secondTeam.toString() << endl;

	cout << "//add player" << endl;
	secondTeam.addTeammate("anthjony");

	cout << secondTeam.toString() << endl;

	
	return 0;
}