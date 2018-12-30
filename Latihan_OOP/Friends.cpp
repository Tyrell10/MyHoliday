#include <iostream>
#include <string>

class Human{
    private:
    std::string name;
    int age;

    public:
    Human(std::string nama, int a);
    
    friend void Display(Human man);
};

int main(){
    Human Tyrell("Tyrell",18);
    Display(Tyrell);

    return 0;
}

Human::Human(std::string nama, int a){
    name = nama;
    age = a;
}
void Display(Human man){
    std::cout << "Nama : " << man.name << std::endl;
    std::cout << "Umur : " << man.age << std::endl;
}