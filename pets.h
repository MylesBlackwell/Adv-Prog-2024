#ifndef Pets_H
#define Pets_H

#include <iostream>
#include <string>
#include <cmath>

#include "food.h"
#include "toy.h"

using namespace std;

class Pets{
protected:
    //varibles
    string name;
    string type;
    int hungerLevel;
    int happyLevel;
    int age;

public:
    //constructor
    Pets(string name, int age){
        this->name = name;
        this->age = age;
        this->hungerLevel = 50;
        this->happyLevel = 100;
    }


    //get methods
    string getName(){
        return name;
    }

    int getHungerLevel(){
        return hungerLevel;
    }

    int getHappyLevel(){
        return happyLevel;
    }


    int getAge(){
        return age;
    }

    virtual string getType() = 0;
    virtual void feed(){};
    virtual void rest(){};
    virtual void status(){};
    virtual void displayStatus(){}
};

class Mammals : public Pets{
protected: 
    string division;
    int energyLevel;

public:
    Mammals(string name, int age) : Pets(name, age){}

    string getDivision(){
        return division;
    };

    int getEnergyLevel(){
        return energyLevel;
    }

    virtual void feed(){};
    virtual void rest(){};
    virtual void status(){};
    virtual void play(){};
    virtual void displayStatus(){}
};

class Dog : public Mammals {
    public:
    //constuctor
    Dog(string name,  int age) : Mammals(name, age){
        cout << "You now have a " << age << " year old dog named " << name << endl;
        this->division = "mammals";
        energyLevel = 100;
    }

    string getType(){
        return type;
    }

    void feed(Food *foodItem){
        cout << "You fed " << name << " a " << foodItem->getName() << endl;
        if (foodItem->getType() == "dog"){
            hungerLevel += foodItem->getValue();
        } else{
            hungerLevel += round(foodItem ->getValue());
        }
    }

    void play(Toy *toy){
        cout << "You gave " << name << " a " << toy->getName() << " to play with " << endl;
        if(toy->getType() == "dog") {
            happyLevel += toy->getScore();
        }
    };

    void rest(){
        energyLevel = 100;
    }

    void displayStatus(){
        cout << "Name: " << name << endl;;
        cout << name << " is a " << type << endl;
        cout << name << " is " << age << endl;
        cout << name << " is " << division << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Happy Level: " << happyLevel << endl;
        cout << "Energy Level " << energyLevel << endl;

    }
};

#endif