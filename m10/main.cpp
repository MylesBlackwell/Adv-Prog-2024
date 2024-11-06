#include <iostream>
#include <string>

#include "list.h"

using namespace std;

int main() {
	List list;


	string name;
	bool finished = true;

	int choice;
	do{
		cout << "Menu:\ncurrent list size:" << list.getListSize() << "\n\t1: Add customer \n\t2: Delete Customer \n\t3: Display List\n\t4:End" << endl;
		cin >> choice;
		switch(choice) {
		case 1: // add customer
			cout << "Who would you like to add" << endl;
			getline(cin, name);

			list.addValue(name);

			break;
		case 2: //delete customer
			cout << "Who would you like to remove" << endl;
			getline(cin, name);

			list.addValue(name);

			break;

		case 3:
			try {
				cout << "Customer List:" << endl;
				list.displayList();
			}
			catch (const runtime_error& e) {
				cout << e.what() << endl;
			}
			break;
		case 4:

		default:
			finished = false;
		};
	} while (finished == true);

	return 0;
}