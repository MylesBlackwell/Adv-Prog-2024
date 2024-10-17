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

int main() {
    MyVector vect;

    Team* team1 = new Team("Team1",5);
    vect.push_back(team1);
    cout << vect.at(0)->setTeamName() << endl;
    vect.at(0)->addTeammate("Myles");

    string* copy = vect.at(0)->copyConstuctor();
    Team* team2 = new Team("Team2", copy);
    vect.push_back(team2);
    vect.at(1)->addTeammate("Tom");

    cout << vect.at(0)->toString() << endl;
    cout << vect.at(1)->toString() << endl;
	
	return 0;
}