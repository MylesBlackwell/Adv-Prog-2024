#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>
#include <string>

using namespace std;

class Beverage {
protected:
    string name;
    string description;
    int servingSize;
    int calories;
    double price;

public:
    Beverage(string name, string description, int servingSize, int calories, double price);
    virtual ~Beverage();

    string getName();
    string getDescription();
    int getServingSize();
    int getCalories();
    double getPrice();
    virtual string toString();
};

class Coffee : public Beverage {
private:
    bool hot;
    bool caffeinated;
    bool creamer;
    bool sweetener;

public:
    Coffee(string name, string description, int servingSize, int calories, double price, bool hot, bool caffeinated, bool creamer, bool sweetener);
    ~Coffee();

    bool getTemp();
    bool getCaffeinated();
    bool getCreamer();
    bool getSweetener();
    string toString();
};

class Tea : public Beverage {
protected:
    bool hot;
    bool creamer;
    bool sweetener;
    bool lemon;

public:
    Tea(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon);
    virtual ~Tea();
    virtual string toString();
};

class Black : public Tea {
public:
    Black(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon);
    ~Black();
    string toString();
};

class Oolong : public Tea {
public:
    Oolong(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon);
    ~Oolong();
    string toString();
};

class Green : public Tea {
public:
    Green(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon);
    ~Green();
    string toString();
};

class Herbal : public Tea {
public:
    Herbal(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon);
    ~Herbal();
    string toString();
};

class Soda : public Beverage {
protected:
    string brand;
    bool diet;
    bool ice;

public:
    Soda(string name, string description, int servingSize, int calories, double price, string brand, bool diet, bool ice);
    ~Soda();

    string getBrand();
    bool getDiet();
    bool getIce();
    string toString();
};

class Cola : public Soda {
public:
    Cola(string name, string description, int servingSize, int calories, double price, string brand, bool diet, bool ice);
    ~Cola();
    string toString();
};

class LemonLime : public Soda {
public:
    LemonLime(string name, string description, int servingSize, int calories, double price, string brand, bool diet, bool ice);
    ~LemonLime();
    string toString();
};

class Birch : public Soda {
public:
    Birch(string name, string description, int servingSize, int calories, double price, string brand, bool diet, bool ice);
    ~Birch();
    string toString();
};

class EnergyDrink : public Beverage {
protected:
    string brand;
    bool sweetener;

public:
    EnergyDrink(string name, string description, int servingSize, int calories, double price, string brand, bool sweetener);
    ~EnergyDrink();

    string getBrand();
    string toString();
};

class Caffeine : public EnergyDrink {
public:
    Caffeine(string name, string description, int servingSize, int calories, double price, string brand, bool sweetener);
    ~Caffeine();
    string toString();
};

class Taurine : public EnergyDrink {
public:
    Taurine(string name, string description, int servingSize, int calories, double price, string brand, bool sweetener);
    ~Taurine();
    string toString();
};

#endif // BEVERAGE_H
