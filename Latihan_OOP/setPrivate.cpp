#include <iostream>

class Box{
    private:
        long panjang, lebar, tinggi, volume;

    public:
        void setPanjang(long p);
        void setLebar(long l);
        void setTinggi(long t);
        long getVolume();
};
void Box::setPanjang(long p){
    panjang = p;
}
void Box::setLebar(long l){
    lebar = l;
}
void Box::setTinggi(long t){
    tinggi = t;
}
long Box::getVolume(){
    volume = panjang * lebar * tinggi;
    return volume;
}

int main(){
    Box Balok;

    Balok.setPanjang(4.0);
    Balok.setLebar(4.0);
    Balok.setTinggi(4.0);

    std::cout << "Volume Balok = " << Balok.getVolume() << std::endl;

    return 0;
}
