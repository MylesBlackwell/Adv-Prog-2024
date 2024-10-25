#include <iostream>
#include <string>
#include <vector>
#include "Beverage.h"

using namespace std;


int main() {
	vector<Beverage> vec;
	Beverage drink1("drink 1","it is a drink", 3, 5, 5.0);
	Coffee drink2("drink 2", "it is a coffee", 3, 12, 7.1, true, true, false, true);
	Herbal drink3("drink 3", "it is a coffee", 6, 8, 29.5, true, false, false, true);

	vec.push_back(drink1);
	vec.push_back(drink2);
	vec.push_back(drink3);


	for (auto& bev : vec) {
		cout << bev.toString() << endl;
	}
	

	return 0;
}