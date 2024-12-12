#include <iostream>
#include <string>
#include <memory>

#include "pets.h"
#include "toy.h"
#include "linkedList.h"

using namespace std;

#include <iostream>

int main(){
    LinkedList<unique_ptr<Pets> > ownedPets;

    cout << "Welcome to Pet Simulator" << endl;

    bool start;

    auto dog = make_unique<Dog>("Rover", 2, 50);
    ownedPets.addNode(move(dog));
    
    cout << ownedPets.refNode(1)->getName() << endl;
}