/*Program:team.cpp
*Author: Myles Blackwell
*Date Last Uodated:10/17/2024
*Purpose:Team Class Source File
*/
#include "team.h"

string Team::validateString(string str) { //validates strings to ensure they are not empty
    if (str.size() == 0) {
        throw invalid_argument("String is empty");
    }
    return str;
}

Team::Team(string teamName, int teamSize) { //Constructor with a new team
    this->teamName = validateString(teamName); 
    if (teamSize < 1) {
        throw invalid_argument("Team capacity must be greater than 0");
    }
	//initilization
    players = new string[teamSize]; 
    teamCapacity = teamSize;
    this->teamSize = 0;
}

Team::Team(string teamName, string* ptr) { //constructor for a copy team
    this->teamName = validateString(teamName); 
    teamSize = 0; 
    teamCapacity = atoi(ptr[0].c_str()); //the 0 index has the size of the team
    players = new string[teamCapacity]; //initilizes the array
    for (int i = 0; i < teamCapacity; i++) { //goes through each value of the array
        if (!ptr[i + 1].empty()) {  //if the value is not empty adds it array and increasses size
            players[i] = ptr[i + 1]; 
            teamSize++;
        }
    }
}

Team::~Team() { //opens storage
    delete[] players;
    delete[] copyTeam;
}

string* Team::copyConstuctor() { //copy and return the pointer of the coppy
    copyTeam = new string[teamCapacity + 1];
    copyTeam[0] = to_string(teamCapacity);
    for (int i = 0; i < teamSize; i++) {
        copyTeam[i + 1] = players[i];
    }
    return copyTeam;
}

void Team::addTeammate(string playerName) { //adds a player to array
    if (teamSize < teamCapacity) { //checks to see if it fits in the size
        players[teamSize] = validateString(playerName);
        teamSize++;
    } else {
        cout << "Team spots filled. Delete one before adding" << endl;
    }
}

void Team::deleteTeammate(string playerName) { //deletes the player from the team array
    int index = -1; //index of array
    for (int i = 0; i < teamSize; i++) { //for every index of array
        if (players[i] == playerName) { // if player name is found sets array
            index = i;
            break;
        }
    }
    if (index != -1) { //if player is moves every player down after that point
        for (int i = index; i < teamSize - 1; i++) {
            players[i] = players[i + 1];
        }
        teamSize--; //decreases team size
    } else { //if player is not found throw player invalid argument to show that player is not found
        throw invalid_argument("Player Name not found");
    }
}

int Team::getNumberOfPlayer() { //get number of players
    return teamSize;
}

string Team::setTeamName() { //if no argument just return team name
    return teamName;
}

string Team::setTeamName(string name) { //if there is an argument change the name then return the new team name
    teamName = validateString(name);
    return teamName;
}

string Team::toString() { //returns the team name and players in a string
    string str = "Team Name: " + teamName + " Players: "; //start of string 
    for (int i = 0; i < teamSize; i++) { //for every player in array it adds it to the string
        str = str + players[i] + ", "; 
    }
    return str;
}
