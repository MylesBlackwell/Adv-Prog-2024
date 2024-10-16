#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class  Team {
private:
	//varibles
	string teamName;

	string* players;
	string* copyTeam;

	int teamCapcity = 0;
	int teamSize;

	validateString; // add to everywhere that needs to make sure string is not empty. That will throw invalid argument error

public:

	//Constructor
	Team(string teamName, int teamSize) {
		this->teamName = teamName;
		players = new string[teamSize];
		teamCapcity = teamSize;
		this->teamSize = 0;
	}

	Team(string teamName,string *ptr[]) {
		this->teamName = teamName;

		players = new string[atoi(ptr[0]->c_str())];
		teamCapcity = atoi(ptr[0]->c_str());

		int i = 0;
		do {
			cout << ptr[i];
			i++;
		} while (true);
	}

	//Deconstructor
	~Team() {
		delete[] players;
		delete[] copyTeam;
	}

	//Copy Constructor
	string* copyConstuctor() {
		copyTeam = new string[teamCapcity];

		copyTeam[0] = teamCapcity;

		for (int i = 0; i < teamSize; i++) {
			copyTeam[i+1] = players[i];
		}
		

		return copyTeam;
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
		else {
			throw invalid_argument("Player Name not found");
		}
	}

	//Get Number of Players
	int getNumberOfPlayer() {
		return teamSize;
	}

	//set name
	string setTeamName() {
		return teamName;
	}

	string setTeamName(string name) {
		teamName = name;
		return teamName;
	}

	string toString() {
		string str = "Team Name: " + teamName + "Players: "; 

		for (int i = 0; i < teamSize; i++) {
			str = str + players[i] + ", ";
		}
	}
};