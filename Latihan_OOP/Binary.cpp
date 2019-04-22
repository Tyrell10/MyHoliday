#include <iostream>

class Kalender{
    private:
        int Hari;
        int Bulan;
        int Tahun;
        void TambahHari(int hari);
        void TambahBulan(int bulan);
        void TambahTahun(int tahun);
    public:
        Kalender(int hari, int bulan, int tahun):Hari(hari), Bulan(bulan), Tahun(tahun){}
        Kalender operator + (int hari){
            Kalender objKal(Hari, Bulan, Tahun);
            objKal.TambahHari(hari);
            return objKal;
        }
        void TampilKal();
};

void Kalender::TambahHari(int hari){
    Hari += hari;
    if(Hari > 30){
        TambahBulan(Hari/30);
        Hari %= 30;
    }
}

void Kalender::TambahBulan(int bulan){
    Bulan += bulan;
    if(Bulan > 30){
        TambahTahun(Bulan/12);
        Bulan %= 12;
    }
}

void Kalender::TambahTahun(int tahun){
    Tahun += tahun;
}

void Kalender::TampilKal(){
    std::cout << Hari << " /" << Bulan << " /" << Tahun << std::endl;
}

int main(){
    Kalender objKal(17,1,2019);
    objKal.TampilKal();

    Kalender objKalBaru(objKal + 17);
    objKalBaru.TampilKal();

    return 0;
}