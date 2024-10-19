/*Program name:coffeCup.h
* Author:Myles Blacwkell
* Date:10/19/2024
* Purpose:coffe project header file
*/

#ifndef COFFEECUP_H
#define COFFEECUP_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class CoffeeCup {
private:
    string material;
    string color;
    string content;
    double capacity;
    double contentLevel;

public:
    CoffeeCup();

    string getMaterial();
    string getColor();
    string getContent();
    double getFillLevel();

    double sip(double quantity);
    double pour(double quantity);
    void isEmpty();
    void isFull();
    double refill(double quantity);

    bool operator==(double quantity);
    bool operator<(double quantity);
    bool operator>(double quantity);

    CoffeeCup& operator--();
    CoffeeCup operator--(int);
    CoffeeCup& operator+=(double quantity);
    CoffeeCup& operator-=(double quantity);
    CoffeeCup& operator=(CoffeeCup& otherCup);
    CoffeeCup& operator+(CoffeeCup& otherCup);

    friend ostream& operator<<(ostream& os, const CoffeeCup& cup);
};

#endif // COFFEECUP_H
