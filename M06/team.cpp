#include <iostream>

using namespace std;

class  Team {
private:
	//varibles
	string teamName;

	string* players;

	int teamCapcity;
	int teamSize;

public:
	
	//Constuctor
	Team(string teamName, int teamSize) {
		this->teamName = teamName;
		players = new string[teamSize];
		teamCapcity = teamSize;
		this->teamSize = 0;
	}

	//Deconstructor
	~Team() {
		delete[] players;
	}

	//Add Teammate
	void addTeammate(string playerName) {
		if (teamSize < teamCapcity) {
			players[teamSize] = playerName;
			teamSize++;
		}
		else {
			cout << "Team spots filled. Delete one before adding" << endl;
		}
	}

	//Delte Teammate
	void deleteTeammate(string playerName) {
		int index = -1;

		for (int i = 0; i < teamSize; i++) {
			if (players[i] == playerName) {
				index = i;
				break;
			}
		}

		if (index != 1) {
			for (int i = index; i < teamSize - 1; i++) {
				players[i] = players[i + 1];
			}
			teamSize--;
		}
	}
};