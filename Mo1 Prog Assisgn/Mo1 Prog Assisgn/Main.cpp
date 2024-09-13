/*Program Name: Main.Cpp
* Author: Myles Blackwell
* Date last updated: 9/4/2024
* Purpose: Resturant Bill
*/

#include <iostream>
#include <string>
#include <cmath>


using namespace std;


int main() {

	//Varible for chare
	double charge;

	//Intput for charge
	cout << "How much was your meal" << endl;
	cin >> charge;


	//calculate tax and rounds 
	double tax = charge * 0.0675;
	tax = round(tax * 100)/100;

	//calulate tip and rounds
	double tip = charge * 0.18;
	tip = round(tip * 100)/100;

	//adding all charges together
	double totalBill = charge + tip + tax;


	//delivering tax amount, tip amount, and total
	cout << "Tax: " << tax << endl;
	cout << "Tip(18%): " << tip << endl;
	cout << "Total: " << totalBill << endl;

}