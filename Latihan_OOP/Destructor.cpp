#include <iostream>
#include <string>

class Human{
    private:
        std::string *name;
        int *age;
    
    public:
        Human(std::string nama, int a);
        ~Human();
        void Display();

};
Human::Human(std::string nama, int a){
    name = new std::string;
    age = new int;

    *name = nama;
    *age = a;
}
Human::~Human(){
    delete name;
    delete age;
    std::cout << "All Memories are deleted" << std::endl;
}
void Human::Display(){
    std::cout << "Nama : " << *name << std::endl;
    std::cout << "Umur : " << *age << std::endl;
}

int main(){
    Human *Tyrell = new Human("Tyrell",18);
    Tyrell->Display();

    delete Tyrell;
    return 0;
}