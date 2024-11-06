#include <iostream>
#include <string>

using namespace std;

class List {
private:
	struct Node {
		string customer;
		Node* next;
	};

	Node* head;

public:
	List() : head(nullptr) {} //constuctor

	List(const List& other) : head(nullptr) { //copy constuctor
		Node* current = other.head;
		while (current != nullptr) {
			addValue(current->customer);
			current = current->next;
		}
	}

	~List() {
		Node* current = head;
		while (current != nullptr) {
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	//methods
	void addValue(const string& customerName) { // add value
		Node* newNode = new Node;
		newNode->customer = customerName;
		newNode->next = nullptr;

		if (listIsEmpty() == true || head->customer > customerName) {
			newNode->next = head;
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != nullptr && current->next->customer < customerName) {
				current = current->next;
			}
			newNode->next = current->next; 
			current->next = newNode;

		}
	}

	void removeValue(const string& customerName) { //removes value
		if (!listIsEmpty()) {
			throw runtime_error("List is empty. There is nothing able to be removed");
		}

		Node* current = head;
		while (current->next != nullptr && current->next->customer != customerName) {
			current = current->next; 
		}


		if (current->next->customer == customerName) {
			Node* t = current->next;
			current->next = current->next->next;
			delete t;
			cout << customerName << " has been removed." << endl;
		}
		else {
			throw runtime_error(customerName + " not found");
		}
	}

	void displayList() const {
		if (listIsEmpty() == false) {
			throw runtime_error("List is empty.");
		}

		Node* current = head;
		while (current != nullptr) {
			cout << current->customer << endl;
			current = current->next;
		}
	}

	bool listIsEmpty() const { //check if list is empty
		return head == nullptr;
	}

	int getListSize() { //get the current list size
		if (!listIsEmpty()) {
			return 0;
		}
		else {
			int i = 0;
			Node* current = head;
			while (current != nullptr) {
				i++;
				current = current->next;
			}
		}
	}
};
