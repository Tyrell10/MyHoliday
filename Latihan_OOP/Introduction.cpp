#include <iostream>
#include <string>

class Human{
public:
    std::string name = "noname"; // default initialized
    void display();/*{
        std::cout << "my name is " << name << std::endl;
    }*/

};
void Human::display(){ 
    std::cout << "my name is " << name << std::endl;
}

int main(){
    Human Tyrell; // name of object
    Tyrell.display();

    Tyrell.name = "Tyrell";
    Tyrell.display();

    Human *Tio = new Human();

    Tio->name = "Tio";
    Tio->display();

    return 0;
}