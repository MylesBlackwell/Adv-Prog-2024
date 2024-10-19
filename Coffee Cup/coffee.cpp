/*Program name:coffee.cpp
* Author:Myles Blacwkell
* Date:10/19/2024
* Purpose:coffe class source file
*/
//headers
#include <iostream>
#include <vector>
#include <string>
#include "coffeeCup.h"

using namespace std;


CoffeeCup::CoffeeCup() {
    capacity = 64.0;
    contentLevel = 0;
}

string CoffeeCup::getMaterial() {
    return material;
}

string CoffeeCup::getColor() {
    return color;
}

string CoffeeCup::getContent() {
    return content;
}

double CoffeeCup::getFillLevel() {
    return contentLevel;
}

double CoffeeCup::sip(double quantity) {
    if (quantity > 0.7) {
        throw underflow_error("A sip is at the most 1.7 ounces");
    }
    contentLevel -= quantity;
    return contentLevel;
}

double CoffeeCup::pour(double quantity) {
    if (quantity > contentLevel) {
        throw overflow_error("you can not pour more than content level");
    }
    return 0;
}

void CoffeeCup::isEmpty() {
    // Implementation needed
}

void CoffeeCup::isFull() {
    // Implementation needed
}

double CoffeeCup::refill(double quantity) {
    if ((quantity + contentLevel) > 64.0) {
        throw overflow_error("Max cup amount is 64 ounces");
    }
    contentLevel += quantity;
    return contentLevel;
}

bool CoffeeCup::operator==(double quantity) {
    return contentLevel == quantity;
}

bool CoffeeCup::operator<(double quantity) {
    return contentLevel < quantity;
}

bool CoffeeCup::operator>(double quantity) {
    return contentLevel > quantity;
}

CoffeeCup& CoffeeCup::operator--() {
    if (contentLevel < 0.5) {
        throw underflow_error("Cannot sip, cup is empty ");
    }
    contentLevel -= 0.5;
    return *this;
}

CoffeeCup CoffeeCup::operator--(int) {
    CoffeeCup temp = *this;
    --(*this);
    return temp;
}

CoffeeCup& CoffeeCup::operator+=(double quantity) {
    if ((quantity + contentLevel) > 64.0) {
        throw overflow_error("Max cup amount is 64 ounces");
    }
    contentLevel += quantity;
    return *this;
}

CoffeeCup& CoffeeCup::operator-=(double quantity) {
    if (quantity > contentLevel) {
        throw underflow_error("can not pour more than content amount");
    }
    contentLevel -= quantity;
    return *this;
}

CoffeeCup& CoffeeCup::operator=(CoffeeCup& otherCup) {
    this->contentLevel = otherCup.contentLevel;
    return *this;
}

CoffeeCup& CoffeeCup::operator+(CoffeeCup& otherCup) {
    CoffeeCup combine;
    contentLevel = this->contentLevel = otherCup.contentLevel;
    return combine;
}

ostream& operator<<(ostream& os, const CoffeeCup& cup) {
    os << "Material: " << cup.material << "\n"
        << "Color: " << cup.color << "\n"
        << "Content: " << cup.content << "\n"
        << "Capacity: " << cup.capacity << " ounces\n"
        << "Content Level: " << cup.contentLevel << " ounces\n";
    return os;
}
