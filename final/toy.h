#ifndef Toy_H
#define Toy_H

#include <iostream>
#include <string>

using namespace std;

class Toy{
private:
    string name;
    string type;
    int score;

public:
    //constructor
    Toy(string name, string type, int score){
        this->name = name;
        this->type = type;
        this->score = score;
    }

    string getName(){
        return name;
    }

    int getScore(){
        return score;
    }

    string getType(){
        return type;
    }
};

#endif