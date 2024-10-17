#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class  Team {
private:
	//varibles
	string teamName;

	string* players;
	string* copyTeam;

	int teamCapacity;
	int teamSize;

	string validateString(string str){
		if(str.size() == 0){
			throw invalid_argument("String it empty");
		}
		return str;
	} // add to everywhere that needs to make sure string is not empty. That will throw invalid argument error

public:

	//Constructor
	Team(string teamName, int teamSize) {
		this->teamName = validateString(teamName);
		if (teamSize < 1){ 
			throw invalid_argument("Team capacity must be greater than 0");
		}
		players = new string[teamSize];
		teamCapacity = teamSize;
		this->teamSize = 0;
	}

	Team(string teamName, string *ptr) {
		this->teamName = validateString(teamName);
		teamSize = 0;
		teamCapacity = atoi(ptr[0].c_str());
        players = new string[teamCapacity];
		for(int i = 0; i < teamCapacity; i++ ){
			if (!ptr[i+1].empty()){
				players[i] = ptr[i+1];
				teamSize++;
			}
		}

		cout << players[1] << endl;
		//put this into a do while loop then take the error and when handling set it as team size
	}

	//Deconstructor
	~Team() {
		delete[] players;
		delete[] copyTeam;
	}

	//Copy Constructor
	string* copyConstuctor() {
		copyTeam = new string[teamCapacity + 1];

		copyTeam[0] = to_string(teamCapacity);

		for (int i = 0; i < teamSize; i++) {
			copyTeam[i+1] = players[i];
		}
		return copyTeam;
	}

	//Add Teammate
	void addTeammate(string playerName) {
		if (teamSize < teamCapacity) {
			players[teamSize] = validateString(playerName); 
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
				cout << "player found" << endl;
				index = i;
				break;
			}
		}

		if (index != -1) {
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
		teamName = validateString(name);
		return teamName;
	}

	string toString() {
		string str = "Team Name: " + teamName + " Players: "; 
		for (int i = 0; i < teamSize; i++) {
			str = str + players[i] + ", ";
		}

		return str;
	}
};