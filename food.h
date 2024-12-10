#ifndef Food_H
#define Food_H

#include <iostream>
#include <string>

using namespace std;

class Food{
private:
    //varibles
    string name;
    string type;
    int value;
public:
    //Constructor
    Food(string name, string type, int value){
        this->name = name;
        this->type = type;
        this->value = value;
    }

string getName(){
    return name;
}

string getType(){
    return type;
}

int getValue(){
    return value;
}

};

#endif