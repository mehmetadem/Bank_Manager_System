#ifndef EKRAN_H
#define EKRAN_H
#include<iostream>
#include<string>
#include "musteri.h"
using namespace std;

class Ekran
{
    public:
    	static void KarsilamaMesaji();
    	
        void anaSayfa();
        void hesapOlusturmaSayfasi();
        void kullaniciGirisi();
        int kullaniciIslem(int index);
        
        void paraYatir(int index);
		void paraCek(int index);
		void kullaniciBilgileri(int index);
		void sifreDegistir(int index);
		int IndexBulma(string TCNO);
		
		void KullaniciBilgileri();
		void VerileriCek();
		void Giris();
		void st(int);
		int at();
    private:
        Musteri musteriler[20];
        

};
#endif
