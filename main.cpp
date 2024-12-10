#include <iostream>
#include <string>

#include "pets.h"
#include "toy.h"

using namespace std;

int main(){
    Dog dog("Rover", 2);
    Toy dogToy("Tennis Ball", "dog", 15);
    Food dogFood("Dog Food", "dog", 25);

    dog.play(&dogToy);
    dog.feed(&dogFood);
    
    dog.displayStatus();
}