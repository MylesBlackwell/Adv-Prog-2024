#include "Beverage.h"

// Beverage class implementation
Beverage::Beverage(string name, string description, int servingSize, int calories, double price) {
    this->name = name;
    this->description = description;
    this->servingSize = servingSize;
    this->calories = calories;
    this->price = price;
    cout << "making " + name << endl;
}

Beverage::~Beverage() {
    cout << "the " + name + " is being removed" << endl;
}

string Beverage::getName() {
    return name;
}

string Beverage::getDescription() {
    return description;
}

int Beverage::getServingSize() {
    return servingSize;
}

int Beverage::getCalories() {
    return calories;
}

double Beverage::getPrice() {
    return price;
}

string Beverage::toString() {
    string value = "Beverage: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price);
    return value;
}

// Coffee class implementation
Coffee::Coffee(string name, string description, int servingSize, int calories, double price, bool hot, bool caffeinated, bool creamer, bool sweetener) : Beverage(name, description, servingSize, calories, price) {
    this->hot = hot;
    this->caffeinated = caffeinated;
    this->creamer = creamer;
    this->sweetener = sweetener;
    cout << name << " is now a coffee" << endl;
}

Coffee::~Coffee() {
    cout << name << " is no longer a coffee" << endl;
}

bool Coffee::getTemp() {
    return hot;
}

bool Coffee::getCaffeinated() {
    return caffeinated;
}

bool Coffee::getCreamer() {
    return creamer;
}

bool Coffee::getSweetener() {
    return sweetener;
}

string Coffee::toString() {
    string temp = hot ? "hot" : "cold";
    string isCaffeinated = caffeinated ? " has caffeine " : " has no caffeine ";
    string hasCreamer = creamer ? " has creamer " : " has no creamer ";
    string hasSweetener = sweetener ? " has sweetener " : " has no sweetener ";

    string value = "Coffee: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Temperature: " + temp + isCaffeinated + hasCreamer + hasSweetener;
    return value;
}

// Tea class implementation
Tea::Tea(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Beverage(name, description, servingSize, calories, price) {
    this->hot = hot;
    this->creamer = creamer;
    this->sweetener = sweetener;
    this->lemon = lemon;
    cout << name << " is now a tea" << endl;
}

Tea::~Tea() {
    cout << name << " is no longer tea" << endl;
}

string Tea::toString() {
    string temp = hot ? "hot" : "cold";
    string hasLemon = lemon ? " has lemon " : " has no lemon ";
    string hasCreamer = creamer ? " has creamer " : " has no creamer ";
    string hasSweetener = sweetener ? " has sweetener " : " has no sweetener ";

    string value = "Tea: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Temperature: " + temp + hasLemon + hasCreamer + hasSweetener;
    return value;
}

// Black class implementation
Black::Black(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Tea(name, description, servingSize, calories, price, hot, creamer, sweetener, lemon) {
    cout << name << " tea type is black" << endl;
}

Black::~Black() {
    cout << name << " is no longer black tea" << endl;
}

string Black::toString() {
    return Tea::toString();
}

// Oolong class implementation
Oolong::Oolong(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Tea(name, description, servingSize, calories, price, hot, creamer, sweetener, lemon) {
    cout << name << " tea type is Oolong" << endl;
}

Oolong::~Oolong() {
    cout << name << " is no longer Oolong tea" << endl;
}

string Oolong::toString() {
    return Tea::toString();
}

// Green class implementation
Green::Green(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Tea(name, description, servingSize, calories, price, hot, creamer, sweetener, lemon) {
    cout << name << " tea type is Green" << endl;
}

Green::~Green() {
    cout << name << " is no longer Green tea" << endl;
}

string Green::toString() {
    return Tea::toString();
}

// Herbal class implementation
Herbal::Herbal(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Tea(name, description, servingSize, calories, price, hot, creamer, sweetener, lemon) {
    cout << name << " tea type is Herbal" << endl;
}

Herbal::~Herbal() {
    cout << name << " is no longer Herbal tea" << endl;
}

string Herbal::toString() {
    return Tea::toString();
}

// Soda class implementation
Soda::Soda(string name, string description, int servingSize, int calories, double price, string brand, bool diet, bool ice) : Beverage(name, description, servingSize, calories, price) {
    this->brand = brand;
    this->diet = diet;
    this->ice = ice;
    cout << name << " is now a soda" << endl;
}

Soda::~Soda() {
    cout << name << " is no longer a Soda" << endl;
}

string Soda::getBrand() {
    return brand;
}

bool Soda::getDiet() {
    return diet;
}

bool Soda::getIce() {
    return ice;
}

string Soda::toString() {
    string isDiet = diet ? "is diet" : "is not diet";
    string hasIce = ice ? " has ice " : " has no ice ";

    string value = "Soda: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Brand: " + brand + isDiet + hasIce;
    return value;
}

// Cola class implementation
Cola::Cola(string name, string description, int servingSize, int calories, double price, string brand, bool diet, bool ice) : Soda(name, description, servingSize, calories, price, brand, diet, ice) {
    cout << name << " is a " << brand << " Cola" << endl;
}

Cola::~Cola() {
    cout << name << " is no longer a cola" << endl;
}

string Cola::toString() {
    return Soda::toString();
}

// LemonLime class implementation
LemonLime::LemonLime(string name, string description, int servingSize, int calories, double price, string brand, bool diet, bool ice) : Soda(name, description, servingSize, calories, price, brand, diet, ice) {
    cout << name << " is a " << brand << " Lemon-Lime" << endl;
}

LemonLime::~LemonLime() {
    cout << name << " is no longer Lemon-Lime" << endl;
}

string LemonLime::toString() {
    return Soda::toString();
}

// Birch class implementation
Birch::Birch(string name, string description, int servingSize, int calories, double price, string brand, bool diet, bool ice) : Soda(name, description, servingSize, calories, price, brand, diet, ice) {
    cout << name << " is a " << brand << " Birch" << endl;
}

Birch::~Birch() {
    cout << name << " is no longer Birch" << endl;
}

string Birch::toString() {
    return Soda::toString();
}

// EnergyDrink class implementation
EnergyDrink::EnergyDrink(string name, string description, int servingSize, int calories, double price, string brand, bool sweetener) : Beverage(name, description, servingSize, calories, price) {
    this->brand = brand;
    this->sweetener = sweetener;
    cout << name << " is a " << this->brand << " energy drink" << endl;
}

EnergyDrink::~EnergyDrink() {
    cout << name << " is no longer an energy drink." << endl;
}

string EnergyDrink::getBrand() {
    return brand;
}

string EnergyDrink::toString() {
    string hasSweetener = sweetener ? " has sweetener " : " has no sweetener ";

    string value = "Energy Drink: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Brand: " + brand + hasSweetener;
    return value;
}

// Caffeine class implementation
Caffeine::Caffeine(string name, string description, int servingSize, int calories, double price, string brand, bool sweetener) : EnergyDrink(name, description, servingSize, calories, price, brand, sweetener) {
    cout << name << " uses caffeine as a stimulant" << endl;
}

Caffeine::~Caffeine() {
    cout << name << " no longer uses caffeine as a stimulant" << endl;
}

string Caffeine::toString() {
    return EnergyDrink::toString() + " uses caffeine";
}

// Taurine class implementation
Taurine::Taurine(string name, string description, int servingSize, int calories, double price, string brand, bool sweetener) : EnergyDrink(name, description, servingSize, calories, price, brand, sweetener) {
    cout << name << " uses taurine as a stimulant" << endl;
}

Taurine::~Taurine() {
    cout << name << " no longer uses taurine as a stimulant" << endl;
}

string Taurine::toString() {
    return EnergyDrink::toString() + " uses taurine";
}
