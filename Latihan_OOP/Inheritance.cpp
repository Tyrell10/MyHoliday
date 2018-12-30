#include <iostream>
#include <string>

class Person{
    protected: // protected liked a private but can be accessed by inheritance
        std::string name;
        int age;
    public:
        void setName(std::string nama){
            name = nama;
        }
        void setAge(int umur){
            age = umur;
        }
};
// Turunan Public
/*class Mahasiswa : public Person{
    public:
        int nim;
        void setNim(int mynim){
            nim = mynim;
        }
        void introduce(){
            std::cout << "My Name is " << name << std::endl << "I'm " << age << std::endl << "NIM : " << nim << std::endl;
        }
}; */

//Turunan Protected
class Mahasiswa : protected Person{
    public:
        int nim;
        void setNim(int mynim){
            nim = mynim;
        }
        void setMhsName(std::string nama){
            setName(nama);
        }
        void setMhsAge(int umur){
            setAge(umur);
        }
        void introduce(){
            std::cout << "My Name is " << name << std::endl << "I'm " << age << std::endl << "NIM : " << nim << std::endl;
        }
};

int main(){
    Mahasiswa *Tyrell = new Mahasiswa();
    Tyrell->setMhsName("Tyrell");
    Tyrell->setMhsAge(18);
    Tyrell->setNim(424133);
    Tyrell->introduce();

    delete Tyrell;
    return 0;
}