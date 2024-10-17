/*Program: Main.cpp
*Author: Myles Blackwell
*Date Last Uodated:10/17/2024
*Purpose: Allow the user to create a team, 
		add/remove players from the team, 
		copy the team to another team (hence the need for a copy constructor) and 
		add/remove players from the duplicated team.
*/
//Headers
#include <iostream>
#include "team.h"

using namespace std;

//Makes a vector to hold classes
class MyVector {
private:
    Team** data; //team class points
    size_t capacity; //gets vector capcity
    size_t size; //vector size

	//resize the vector
    void resize(size_t new_capacity) {
        Team** new_data = new Team * [new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
	//Constuctor
    MyVector() { 
		data = nullptr;
		capacity = 0; 
		size = 0; 
		}
	//Deconstructor
    ~MyVector() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
    }

	//Adds to vector
    void push_back(Team* item) {
        if (size >= capacity) { 
            size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
            resize(new_capacity);
        }
        data[size++] = item; // adds a class pointer at the index which increments
    }

	//gets the team pointer at index
    Team* at(size_t index) {
        if (index >= size){ //if the index is out of range
			throw invalid_argument("Index out of range");
		}
        return data[index];
    }

	//gets the currect size of the vector
    size_t getSize() const {
        return size;
    }
};

//checks to see if a string entered is empty
bool isValidString(const string & str) {
    if (str.empty()) {
        return false; //if empty return false
    }
    return true;
}

int main() {
    MyVector vect; //vector initialization

	//varibles
	bool power = true; //power switch
	string teamName;
	int teamSize;
	
    do { //validation for getting inital team name
            cout << "What do you want to name your team: ";
            cin >> teamName;
            if (!isValidString(teamName)) {
                invalid_argument("Team Name is empty");
            }
        } while (!isValidString(teamName)); 

	do { //validation and retrives for team size 
            cout << "How many team members do you want to have: ";
            cin >> teamSize;

            if (cin.fail() || teamSize < 0) {
                cin.clear(); //Clear the rror
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                teamSize = 0;
                cout << "Invalid Input. Please enter a postive number" << endl;
            }
        } while (teamSize == 0);
	//creates the team and adds it to vector
	Team* team = new Team(teamName,teamSize); 
	vect.push_back(team);

	do{ //Menu stays until turned off
		int choice; // choice value
		cout<<"Main Menu:" << endl; //Generated main menu
		for (int i = 0; i < vect.getSize();i++){ //prints all the teams and members
			cout << vect.at(i)->toString()<< endl;
		}
		cout<<"\t1:Create Team\n\t2:Add players\n\t3:Remove Players\n\t4:Copy Team\n\t5:Turn off\nChoice:";
		cin >> choice;
		switch(choice){
			case 1: { //Create Team
				do {  //validates and gets team name
					cout << "What do you want to name your team: ";
					cin >> teamName;
					if (!isValidString(teamName)) {
						invalid_argument("Team Name is empty");
					}
				} while (!isValidString(teamName)); 

				do { // validates and gets number of team members
					cout << "How many team members do you want to have: ";
					cin >> teamSize;

					if (cin.fail() || teamSize < 0) {
						cin.clear(); //Clear the rror
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
						teamSize = 0;
						cout << "Invalid Input. Please enter a postive number" << endl;
					}
				} while (teamSize == 0);
				Team* team = new Team(teamName,teamSize); // makes a new team 
				vect.push_back(team); //adds the team
				break;
			}
			case 2:{// add players
				string teamChoice;
				do {//Gets the name of team name for selections
					cout << "What is the name of your of the team you want to add to: ";
					cin >> teamChoice;
					if (!isValidString(teamChoice)) {
						invalid_argument("Team Name is empty");
					}
				} while (!isValidString(teamChoice));
				int index = -1; //index of vector
				for (int i = 0; i < vect.getSize();i++){ //goes through each team in vector
					if(vect.at(i)->setTeamName() == teamChoice){ // if it finds a matching team name it sets the index and breaks the for loop
						index = i;
						break;
					}
				}
				if (index == -1){ //if the index was never found it informs the user
					cout << "Team Name Not Found" << endl;
					break;
				}else{
					string name;  //player name
					cout << "What do you want to name the player: ";
					cin >> name; //sets player name
					try{ //adds the team member to the vector
						vect.at(index)->addTeammate(name);
					}catch(invalid_argument e){
						cerr << e.what() << endl;
					}
					break;
				}
			}
			case 3:{//Remove Players
				string teamChoice; 
				do { // gets the team of the member they want to remove
					cout << "What is the name of your of the team you want to remove from: ";
					cin >> teamChoice;
					if (!isValidString(teamChoice)) {
						invalid_argument("Team Name is empty");
					}
				} while (!isValidString(teamChoice));
				int index = -1; //the index of vecter
				for (int i = 0; i < vect.getSize();i++){ // goes through each member of vector 
					if(vect.at(i)->setTeamName() == teamChoice){ //if selected team matches team name sets the index
						index = i;
						break;
					}
				}
				if (index == -1){ // if index was never found informs the user
					cout << "Team Name Not Found" << endl;
					break;
				}else{
					string name;
					cout << "What is the name of the player you want to remove: "; 
					cin >> name;
					try{ //deletes the player from the selected team
						vect.at(index)->deleteTeammate(name); 
					}catch(invalid_argument e){
						cerr << e.what() << endl;
					}
					break;
				}
			}
			case 4:{//Copy Team
				string teamChoice;
				do {//sets the team that is to be copied
					cout << "What is the name of the team you want to copy: ";
					cin >> teamChoice;
					if (!isValidString(teamChoice)) {
						invalid_argument("Team Name is empty");
					}
				} while (!isValidString(teamChoice));
				int index = -1; //vecotr index
				for (int i = 0; i < vect.getSize();i++){ // for each index of vecotr
					if(vect.at(i)->setTeamName() == teamChoice){ //when team name matches chosen team sets the index
						index = i;
						break;
					}
				}
				if (index == -1){ //if team is not found, informs the user
					cout << "Team Name Not Found" << endl;
					break;
				}else{
					try{
						string teamName; 
						cout << "What do you want the name of the copy to be: ";
						cin >> teamName; //sets name of the copy

						Team* team = new Team(teamName,vect.at(index)->copyConstuctor()); //creates using the pointer of copy array
						vect.push_back(team);
					}catch(invalid_argument e){
						cerr << e.what() << endl;
					}
					break;
				}
			}
			case 5:{//ends form
				power = false;
			}

			default:{ //if their was an invalid choice
				cout << "Enter a number on the left" << endl;
				break;
			}
		}
	}while (power == true);
	
	return 0;
}