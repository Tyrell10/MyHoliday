#include <iostream>
#include <string>
#include <sstream>

int main(){
    // konversi angka ke string
    int nilai = 27;
    std::string sebutan;

    std::ostringstream convert;
    convert << nilai;

    sebutan = convert.str();
    std::cout << sebutan << std::endl;

    // konversi string ke angka
    float angka;
    std::string text = "27.5";

    std::istringstream convert2(text);
    if(!(convert2 >> angka)){
        angka = 0;
    } else {
        std::cout << angka << std::endl;
    }

    return 0;
}
