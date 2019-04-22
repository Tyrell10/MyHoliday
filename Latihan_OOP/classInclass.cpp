#include <iostream>
#include <string>

class Roda{
    private:
        std::string *merk_roda;
        int *diameter;
    public:
        Roda();
        Roda(std::string merk, int d);
        ~Roda();
        std::string getMerk();
        int getDiameter();
        //void display();
};
Roda::Roda(){    
    merk_roda = new std::string;
    diameter = new int;
}
Roda::Roda(std::string merk, int d){
    merk_roda = new std::string;
    diameter = new int;

    *merk_roda = merk;
    *diameter = d;
}
Roda::~Roda(){
    //delete merk_roda;
    //delete diameter;
}
std::string Roda::getMerk(){
    return *merk_roda;
}
int Roda::getDiameter(){
    return *diameter;
}
/*void Roda::display(){
    std::cout << "Merk : " << getMerk() << std::endl;
    std::cout << "diameter : " << getDiameter() << std::endl;
}*/

class Mobil{
    private:
        std::string *merk_mobil;
        Roda *roda_d1;
        Roda *roda_d2;
        Roda *roda_b1;
        Roda *roda_b2;
    public:
        Mobil(std::string m, Roda r1, Roda r2, Roda r3, Roda r4);
        ~Mobil();
        std::string getMerk_mobil();
        void display();
        void display_Roda();
};
std::string Mobil::getMerk_mobil(){
    return *merk_mobil;
}

Mobil::Mobil(std::string m, Roda r1, Roda r2, Roda r3, Roda r4){
    merk_mobil = new std::string;
    roda_d1 = new Roda();
    roda_d2 = new Roda();
    roda_b1 = new Roda();
    roda_b2 = new Roda();

    *merk_mobil = m; 
    *roda_d1 = r1;
    *roda_d2 = r2;
    *roda_b1 = r3;
    *roda_b2 = r4;
}
Mobil::~Mobil(){
    delete merk_mobil;
    delete roda_d1;
    delete roda_d2;
    delete roda_b1;
    delete roda_b2;
    std::cout << "All memories has been deleted!" << std::endl;
}
void Mobil::display(){
    std::cout << "Merk : " << getMerk_mobil() << std::endl;
    display_Roda();
}
void Mobil::display_Roda(){
    std::cout << "Roda depan1" << std::endl;
    std::cout << "Merk : " << roda_d1->getMerk() << std::endl;
    std::cout << "Diameter : " << roda_d1->getDiameter() << std::endl;
    
    std::cout << "Roda depan2" << std::endl;
    std::cout << "Merk : " << roda_d2->getMerk() << std::endl;
    std::cout << "Diameter : " << roda_d2->getDiameter() << std::endl;

    std::cout << "Roda belakang1" << std::endl;
    std::cout << "Merk : " << roda_b1->getMerk() << std::endl;
    std::cout << "Diameter : " << roda_b1->getDiameter() << std::endl;

    std::cout << "Roda belakang2" << std::endl;
    std::cout << "Merk : " << roda_b2->getMerk() << std::endl;
    std::cout << "Diameter : " << roda_b2->getDiameter() << std::endl;
}

int main(){
    Roda r1("Bridgestone",40);
    Roda r2("Bridgestone",40);
    Roda r3("Bridgestone",40);
    Roda r4("Bridgestone",40);

    Mobil m("Pajero", r1, r2, r3, r4);
    m.display();

    return 0;
}