/*Program:team.h
*Author: Myles Blackwell
*Date Last Uodated:10/17/2024
*Purpose:Team Class Header File
*/
//Headers
#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//Team Classs
class Team {
private:
	//varibles
    string teamName;
    string* players;
    string* copyTeam;
    int teamCapacity;
    int teamSize;

	//validates strings
    string validateString(string str); 

public:
	//constructos
    Team(string teamName, int teamSize);
    Team(string teamName, string* ptr); //copy team

	//deconstuctors
    ~Team();

	//mutators
    string* copyConstuctor(); //returns pointer array of copy of 
    void addTeammate(string playerName); //adds teamate to array
    void deleteTeammate(string playerName); //deletes teammate of array
    
	//get functions
	int getNumberOfPlayer();
    string setTeamName();
    string setTeamName(string name);//changes team name

    string toString(); //retruns the team name and current members of team as a string
};

#endif // TEAM_H
