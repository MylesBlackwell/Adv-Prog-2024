/*Program name:main.cpp
* Author:Myles Blacwkell
* Date:10/19/2024
* Purpose:coffe project main file
*/

//headers
#include <iostream>
#include <vector>
#include <string>
#include "coffeeCup.h"

using namespace std;

int main(){
vector<CoffeeCup> cups;

CoffeeCup cup1;
CoffeeCup cup2;
CoffeeCup cup3;
cups.push_back(cup1);
cups.push_back(cup2);
cups.push_back(cup3);

cup1 += 60.3;
cup2.refill(25.9);
cup3 = cup2;

if (cup2 == cup3.getFillLevel()) {
	cout << "Cup2 and Cup 3 Level is the same" << endl;
}

if (cup1<50.1){
	cout << "cup1 is less than 45 ounces." << endl;
}

if (cup3 > 8) {
	cout << "cup 3 is greater than 10 ounces." << endl;
}

cup2.pour(17.3);
cup1 -= 15.2;

CoffeeCup cup4 = cup1 + cup2;
cups.push_back(cup4);

cout << "Cup 1:" << cup1 << endl;
cout << "Cup 2:" << --cup2 << endl;
cout << "Cup 3:" << cup3-- << endl;
cout << "Cup 4" << cup3 << endl;

return 0;
}