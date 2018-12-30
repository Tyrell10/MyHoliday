#include <iostream>
#include <string>

class Human{
    public:
        Human();
        Human(std::string nama,int a);
        void speak();

    private:
        std::string name;
        int age;
};
Human::Human(){
    std::cout << "Default Class" << std::endl;
}
Human::Human(std::string nama, int a=0){
    std::cout << "Overloading Class" << std::endl;
    name = nama;
    age = a;
}
void Human::speak(){
    std::cout << "Nama : " << name << std::endl;
    std::cout << "Umur : " << age << std::endl;
}

int main(){
    Human Tayo("Tayo", 10);
    Tayo.speak();

    Human *Ferguso = new Human();
    Ferguso->speak();

    return 0;
}