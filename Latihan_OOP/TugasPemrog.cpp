#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

struct Data{
    string nama;
    char matkul;
    int total, sks;
    float ip;
}; 

int main(){
    float nilai;
    int i=0, k=0, j=0, N=0, Nmatkul;
    char pilih;
  
    cout << "Program Hitung Ip Mahasiswa\n" << endl;
    cout << "Banyak Mahasiswa : ";
    cin >> N;
    cout << "Input banyak Matkul : ";
    cin >> Nmatkul;

    Data Ip[Nmatkul];
    float a[N], b[N], c[N], d[N], e[N], Nsks[N], data[N];

    for(j=1; j<=N; j++){
        cout << "Nama : ";
        getchar();
        getline(cin,Ip[j].nama);
        Nsks[j]=0; a[j]=0; b[j]=0; c[j]=0; d[j]=0;
        for(i=1; i<=Nmatkul; i++){
            cout << "Nilai Matkul " << i << " : ";
            cin >> Ip[i].matkul;
            cout << "sks = ";
            cin >> Ip[i].sks;
            Nsks[j] += Ip[i].sks;

            if(Ip[i].matkul == 'A'){
                a[j] += 4.0*Ip[i].sks;
            } else if(Ip[i].matkul == 'B'){
                b[j] += 3.0*Ip[i].sks;
            } else if(Ip[i].matkul == 'C'){
                c[j] += 2.0*Ip[i].sks;
            } else if(Ip[i].matkul == 'D'){
                d[j] += 1.0*Ip[i].sks;
            }
        }
    } 
    for(i=1; i<=N; i++){
        Ip[i].ip = (a[i]+b[i]+c[i]+d[i])/Nsks[i];
        cout << Ip[i].nama << " , Ip = " << Ip[i].ip << endl;
        data[i] = Ip[i].ip; 
    }
    cout << "Ingin cek Nilai ?(Y/N)";
    cin >> pilih;
    while(pilih == 'Y'){
        bool found = false;
        i=0; j=sizeof(data)/sizeof(data[0]);
        cout << "Masukan ip : ";
        cin >> nilai;

        while(!found && i<=j){
            k=(i+j)/2;
            if(data[k]<nilai){
                i = k+1;
            } else if(data[k]==nilai){
                found = true;
                cout << "ip ditemukan" << endl;
                cout << Ip[k].nama << " " << Ip[k].ip << endl;
            } else{
                j=k-1;
            } 
        } if(!found){
            cout << "ip tidak ditemukan" << endl;
        } cout << "Ingin cek Nilai ?(Y/N)";
          cin >> pilih;
    } 

 
    /*for(i=1; i<N; i++){
        Ip[i].ip = (a[i]+b[i]+c[i]+d[i])/Nsks;
        cout << "IP Mhs " << i << " = " << Ip[i].ip << endl;
    }*/
    cin.get();
    return 0;
}