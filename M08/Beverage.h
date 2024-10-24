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
	Beverage(string name, string description, int servingSize, int calories, double price){
		this->name = name;
		this->description = description;
		this->servingSize = servingSize;
		this->calories = calories;
		this->price = price;

		cout << "making " + name << endl;
	}

	~Beverage() {
		cout << "the " + name + " is being removed" << endl;
	}

	//get
	string getName() {
		return name;
	}
	string getDescription() {
		return description;
	}

	int getServingSize() {
		return servingSize;
	}
	int getCalories() {
		return calories;
	}

	double getPrice() {
		return price;
	}


	string toString(){
		string value = "Beverage: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price);
		return value;
	}
};

class Coffee: public Beverage {
private:
	bool hot;
	bool caffeinated;
	bool creamer;
	bool sweetener;

public:
	Coffee(string name, string description, int servingSize, int calories, double price, bool hot, bool caffinated, bool creamer, bool sweetener) : Beverage(name, description, servingSize, calories, price){
		this->hot = hot;
		this->caffeinated = caffinated;
		this->creamer = creamer;
		this->sweetener = sweetener;
		cout << name << "is now a coffee" << endl;
	}

	~Coffee() {
		cout << name << "is no longer a coffe" << endl;
	}

	//get
	bool getTemp() {
		return hot;
	}
	bool getCaffeinated() {
		return caffeinated;
	}
	bool getCreamer() {
		return creamer;
	}
	bool getSweetener() {
		return sweetener;
	}

	string toString() {
		string temp;
		string isCaffiented;
		string hasCreamer;
		string hasSweetener;

		//setting varibles
		if (hot == true) {
			temp = "hot";
		}
		else
		{
			temp = "cold";
		}

		if (caffeinated == true) {
			isCaffiented = " has caffeine ";
		}
		else {
			isCaffiented = " has no caffeine ";
		}


		if (creamer == true) {
			hasCreamer = " has creamer ";
		}
		else {
			hasCreamer = " has no creamer ";
		}

		if (sweetener == true) {
			hasSweetener = " has sweetener ";
		}
		else {
			hasSweetener = " has no sweetener ";
		}

		string value = "Coffee: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Temperature: " + temp + isCaffiented + hasCreamer + hasSweetener;
		return value;
	}
};

class Tea : public Beverage {
protected:
	bool hot;
	bool creamer;
	bool sweetener;
	bool lemon;

public:
	Tea(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Beverage(name, description, servingSize, calories, price) {
		this->hot = hot;
		this->creamer = creamer;
		this->sweetener = sweetener;
		this->lemon = lemon;

		cout << name << " is now a tea" << endl;
	}

	~Tea() {
		cout << name << " is no longer tea" << endl;
	}

	string toString() {
		string temp;
		string hasLemon;
		string hasCreamer;
		string hasSweetener;

		//setting varibles
		if (hot == true) {
			temp = "hot";
		}
		else
		{
			temp = "cold";
		}

		if (lemon == true) {
			hasLemon = " has caffeine ";
		}
		else {
			hasLemon = " has no caffeine ";
		}


		if (creamer == true) {
			hasCreamer = " has creamer ";
		}
		else {
			hasCreamer = " has no creamer ";
		}

		if (sweetener == true) {
			hasSweetener = " has sweetener ";
		}
		else {
			hasSweetener = " has no sweetener ";
		}

		string value = "Tea: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Temperature: " + temp + hasLemon + hasCreamer + hasSweetener;
		return value;
	}
};

class Black : public Tea {
public:
	Black(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Tea(name, description, servingSize,  calories, price, hot, creamer, sweetener, lemon) {
		cout << name <<"tea type is black" << endl;
	}

	~Black() {
		cout << name << " is no longer black tea" << endl;
	}

	string toString() {
		string temp;
		string hasLemon;
		string hasCreamer;
		string hasSweetener;

		//setting varibles
		if (hot == true) {
			temp = "hot";
		}
		else
		{
			temp = "cold";
		}

		if (lemon == true) {
			hasLemon = " has caffeine ";
		}
		else {
			hasLemon = " has no caffeine ";
		}


		if (creamer == true) {
			hasCreamer = " has creamer ";
		}
		else {
			hasCreamer = " has no creamer ";
		}

		if (sweetener == true) {
			hasSweetener = " has sweetener ";
		}
		else {
			hasSweetener = " has no sweetener ";
		}

		string value = "Black Tea: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Temperature: " + temp + hasLemon + hasCreamer + hasSweetener;
		return value;
	}
};

class Oolong : public Tea {
public:
	Oolong(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Tea(name, description, servingSize, calories, price, hot, creamer, sweetener, lemon) {
		cout << name << "tea type is Oolong" << endl;
	}

	~Oolong() {
		cout << name << " is no longer Oolong tea" << endl;
	}

	string toString() {
		string temp;
		string hasLemon;
		string hasCreamer;
		string hasSweetener;

		//setting varibles
		if (hot == true) {
			temp = "hot";
		}
		else
		{
			temp = "cold";
		}

		if (lemon == true) {
			hasLemon = " has caffeine ";
		}
		else {
			hasLemon = " has no caffeine ";
		}


		if (creamer == true) {
			hasCreamer = " has creamer ";
		}
		else {
			hasCreamer = " has no creamer ";
		}

		if (sweetener == true) {
			hasSweetener = " has sweetener ";
		}
		else {
			hasSweetener = " has no sweetener ";
		}

		string value = "Oolong Tea: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Temperature: " + temp + hasLemon + hasCreamer + hasSweetener;
		return value;
	}
};


class Green : public Tea {
public:
	Green(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Tea(name, description, servingSize, calories, price, hot, creamer, sweetener, lemon) {
		cout << name << "tea type is Green" << endl;
	}

	~Green() {
		cout << name << " is no longer Green tea" << endl;
	}

	string toString() {
		string temp;
		string hasLemon;
		string hasCreamer;
		string hasSweetener;

		//setting varibles
		if (hot == true) {
			temp = "hot";
		}
		else
		{
			temp = "cold";
		}

		if (lemon == true) {
			hasLemon = " has caffeine ";
		}
		else {
			hasLemon = " has no caffeine ";
		}


		if (creamer == true) {
			hasCreamer = " has creamer ";
		}
		else {
			hasCreamer = " has no creamer ";
		}

		if (sweetener == true) {
			hasSweetener = " has sweetener ";
		}
		else {
			hasSweetener = " has no sweetener ";
		}

		string value = "Green Tea: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Temperature: " + temp + hasLemon + hasCreamer + hasSweetener;
		return value;
	}
};

class Herbal : public Tea {
public:
	Herbal(string name, string description, int servingSize, int calories, double price, bool hot, bool creamer, bool sweetener, bool lemon) : Tea(name, description, servingSize, calories, price, hot, creamer, sweetener, lemon) {
		cout << name << "tea type is Heerbal" << endl;
	}

	~Herbal() {
		cout << name << " is no longer Herbal tea" << endl;
	}

	string toString() {
		string temp;
		string hasLemon;
		string hasCreamer;
		string hasSweetener;

		//setting varibles
		if (hot == true) {
			temp = "hot";
		}
		else
		{
			temp = "cold";
		}

		if (lemon == true) {
			hasLemon = " has caffeine ";
		}
		else {
			hasLemon = " has no caffeine ";
		}


		if (creamer == true) {
			hasCreamer = " has creamer ";
		}
		else {
			hasCreamer = " has no creamer ";
		}

		if (sweetener == true) {
			hasSweetener = " has sweetener ";
		}
		else {
			hasSweetener = " has no sweetener ";
		}

		string value = "Herbal Tea: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Temperature: " + temp + hasLemon + hasCreamer + hasSweetener;
		return value;
	}
};

class Soda : public Beverage {
protected:
	string brand;
	bool diet;
	bool ice;
public:
	Soda(string name, string description, int servingSize, int calories, double price, string brand, bool died, bool ice) : Beverage(name, description, servingSize, calories, price) {
		this->brand = brand;
		this->diet = diet;
		this->ice = ice;

		cout << name << " is now a soda" << endl;
	}

	~Soda() {
		cout << name << " is no longer a Soda" << endl;
	}

	string getBrand() {
		return brand;
	}

	bool getDiet() {
		return diet;
	}

	bool getIce() {
		return ice;
	}

	string toString() {
		string hasIce;
		string isdiet;

		//setting varibles
		if (diet == true) {
			isdiet = "is diet";
		}
		else
		{
			isdiet = "is not diet";
		}

		if (ice == true) {
			hasIce = " has caffeine ";
		}
		else {
			hasIce = " has no caffeine ";
		}

		string value = "Soda: " + name + " Description: " + description + " Serving Size " + to_string(servingSize) + " Calories: " + to_string(calories) + " Price: " + to_string(price) + " Brand: " + brand + isdiet + hasIce;
		return value;
	}
};