//main pleae
#include <iostream>

#include "team.h"

using namespace std;

class MyVector {
private:
    Team** data;
    size_t capacity;
    size_t size;

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
    MyVector() : data(nullptr), capacity(0), size(0) {}

    ~MyVector() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
    }

    void push_back(Team* item) {
        if (size >= capacity) {
            size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
            resize(new_capacity);
        }
        data[size++] = item;
    }

    Team* at(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t getSize() const {
        return size;
    }
};

bool isValidString(const string & str) {
    if (str.empty()) {
        return false; //if empty return false
    }
    return true;
}

int main() {
    MyVector vect;

	bool power = true;
	string teamName;
	
	int teamSize;
	
    do {
            cout << "What do you want to name your team: ";
            cin >> teamName;
            if (!isValidString(teamName)) {
                invalid_argument("Team Name is empty");
            }
        } while (!isValidString(teamName)); 

	do { //a do while loop to insure that memory is entered correctly
            cout << "How many team members do you want to have: ";
            cin >> teamSize;

            if (cin.fail() || teamSize < 0) {
                cin.clear(); //Clear the rror
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                teamSize = 0;
                cout << "Invalid Input. Please enter a postive number" << endl;
            }
        } while (teamSize == 0);
	Team* team = new Team(teamName,teamSize);
	vect.push_back(team);

	do{
		int choice;
		cout<<"Main Menu:" << endl;
		for (int i = 0; i < vect.getSize();i++){
			cout << vect.at(i)->toString()<< endl;
		}
		cout<<"\t1:Create Team\n\t2:Add players\n\t3:Remove Players\n\t4:Copy Team\n\t5:Turn off\nChoice:";
		cin >> choice;
		switch(choice){
			case 1: { //Create Team
				do {
					cout << "What do you want to name your team: ";
					cin >> teamName;
					if (!isValidString(teamName)) {
						invalid_argument("Team Name is empty");
					}
				} while (!isValidString(teamName)); 

				do { //a do while loop to insure that memory is entered correctly
						cout << "How many team members do you want to have: ";
						cin >> teamSize;

						if (cin.fail() || teamSize < 0) {
							cin.clear(); //Clear the rror
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
							teamSize = 0;
							cout << "Invalid Input. Please enter a postive number" << endl;
						}
				} while (teamSize == 0);
				Team* team = new Team(teamName,teamSize);
				vect.push_back(team);
				break;
			}
			case 2:{// add players
				string teamChoice;
				do {
					cout << "What is the name of your of the team you want to add to: ";
					cin >> teamChoice;
					if (!isValidString(teamChoice)) {
						invalid_argument("Team Name is empty");
					}
				} while (!isValidString(teamChoice));
				int index = -1;
				for (int i = 0; i < vect.getSize();i++){
					if(vect.at(i)->setTeamName() == teamChoice){
						index = i;
						break;
					}
				}
				if (index == -1){
					cout << "Team Name Not Found" << endl;
					break;
				}else{
					string name;
					cout << "What do you want to name the player: ";
					cin >> name;
					try{
						vect.at(index)->addTeammate(name);
					}catch(invalid_argument e){
						cerr << e.what() << endl;
					}
					break;
				}
			}
			case 3:{//Remove Players
				string teamChoice;
				do {
					cout << "What is the name of your of the team you want to remove from: ";
					cin >> teamChoice;
					if (!isValidString(teamChoice)) {
						invalid_argument("Team Name is empty");
					}
				} while (!isValidString(teamChoice));
				int index = -1;
				for (int i = 0; i < vect.getSize();i++){
					if(vect.at(i)->setTeamName() == teamChoice){
						index = i;
						break;
					}
				}
				if (index == -1){
					cout << "Team Name Not Found" << endl;
					break;
				}else{
					string name;
					cout << "What is the name of the player you want to remove: ";
					cin >> name;
					try{
						vect.at(index)->deleteTeammate(name);
					}catch(invalid_argument e){
						cerr << e.what() << endl;
					}
					break;
				}
			}
			case 4:{//Copy Team
				string teamChoice;
				do {
					cout << "What is the name of the team you want to copy: ";
					cin >> teamChoice;
					if (!isValidString(teamChoice)) {
						invalid_argument("Team Name is empty");
					}
				} while (!isValidString(teamChoice));
				int index = -1;
				for (int i = 0; i < vect.getSize();i++){
					if(vect.at(i)->setTeamName() == teamChoice){
						index = i;
						break;
					}
				}
				if (index == -1){
					cout << "Team Name Not Found" << endl;
					break;
				}else{
					try{
						string teamName;
						cout << "What do you want the name of the copy to be: ";
						cin >> teamName;

						Team* team = new Team(teamName,vect.at(index)->copyConstuctor());
						vect.push_back(team);
					}catch(invalid_argument e){
						cerr << e.what() << endl;
					}
					break;
				}
			}
			case 5:{//end form
				power = false;
			}

			default:{
				cout << "Enter a number on the left" << endl;
				break;
			}
		}
	}while (power == true);

   /* Team* team1 = new Team("Team1",5);
    vect.push_back(team1);
    cout << vect.at(0)->setTeamName() << endl;
    vect.at(0)->addTeammate("Myles");

    string* copy = vect.at(0)->copyConstuctor();
    Team* team2 = new Team("Team2", copy);
    vect.push_back(team2);
    vect.at(1)->addTeammate("Tom");

    cout << vect.at(0)->toString() << endl;
    cout << vect.at(1)->toString() << endl;*/
	
	return 0;
}