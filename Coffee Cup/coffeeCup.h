//Headers
#include <iostream>>

using namespace std;
class CoffeeCup
{
private:
    //varibles
    string material;
    string color; 
    string content;

    //measurements in ounces
    double capacity; 
    double contentLevel;

public:
    //constuctor
    CoffeeCup(){
        //initilization
        capacity = 64.0;
        contentLevel = 0;
    }

    //get functions
    string getMaterial(){
        return material;
    }

    string getColor(){
        return color;
    }

    string getContent(){
        return content;
    }

    double getFillLevel(){
        return contentLevel;
    }


    //mutators
    double sip(double quantity){
        if(quantity > 0.7){
            throw underflow_error("A sip is at the most 1.7 ounces");
        }
        contentLevel =- quantity;
        return contentLevel;
    }

    double pour(double quantity){
        return 0;
    }

    void isEmpty(){

    }

    void isFull(){

    }

    double refill(double quantity){
        if ((quantity + contentLevel) > 64.0){
            throw overflow_error("Max cup amount is 64 ounces");
        }
        contentLevel =+ quantity;
        return contentLevel;
    }

    //Overload Operators
    bool operator==(double quantity){
        return contentLevel == quantity;
    }

    bool operator<(double quantity){
        return contentLevel < quantity;
    }

    bool operator>(double quantity){
        return contentLevel > quantity;
    }

    CoffeeCup& operator--(){
        if (contentLevel < 0.5){
            throw underflow_error("Cannot sip, cup is empty ");
        }
        contentLevel -= 0.5;
        return *this;
    }

    CoffeeCup operator--(int) {
        CoffeeCup temp = *this;
        --(*this);
        return temp;
    }

    CoffeeCup& operator+=(double quantity){
        if ((quantity + contentLevel) > 64.0){
            throw overflow_error("Max cup amount is 64 ounces");
        }
        contentLevel += quantity;
        return *this;
    }

    CoffeeCup& operator-=(double quantity){
        if(quantity > contentLevel){
            throw underflow_error("can not pore than content amout");
        }
    }

    CoffeeCup& operator=(CoffeeCup& otherCup){
        this->contentLevel = otherCup.contentLevel;
    }

    CoffeeCup& operator+(CoffeeCup& otherCup){
        CoffeeCup combine;
        contentLevel = this->contentLevel = otherCup.contentLevel;
        return combine;
    }

    friend ostream& operator<<(ostream& os, const CoffeeCup& cup) {
        os << "Material: " << cup.material << "\n"
           << "Color: " << cup.color << "\n"
           << "Content: " << cup.content << "\n"
           << "Capacity: " << cup.capacity << " ounces\n"
           << "Content Level: " << cup.contentLevel << " ounces\n";
        return os;
    }
};