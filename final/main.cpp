#include <iostream>
#include <string>
#include <memory>

#include "pets.h"
#include "toy.h"

using namespace std;

#include <iostream>

//node structure
struct Node {
    shared_ptr<Pets> data;
    Node* next;
    Node(shared_ptr<Pets> pet) : data(pet), next(nullptr) {}
};

// Insert a new node at the beginning
void insertAtHead(Node*& head, shared_ptr<Pets> newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

//delete a node with a specific value
void deleteNode(Node*& head, shared_ptr<Pets> key) {
    Node* temp = head;
    Node* prev = nullptr;

    // If the head node itself holds the key
    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }

    // Search for the key to be deleted
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == nullptr) return;

    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp;
}

int main(){
    Dog dog("Rover", 2, 50);
    Toy dogToy("Tennis Ball", "dog", 15);
    Food dogFood("Dog Food", "dog", 25);

    dog.play(&dogToy);
    dog.feed(&dogFood);
    
    dog.displayStatus();
}