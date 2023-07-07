#ifndef MUSTERI_H
#define MUSTERI_H
#include<iostream>
#include<string>
using namespace std;
class Musteri
{
	
	friend ostream &operator<<(ostream &output, Musteri &musteri);
	friend void SifreBilgisiYaz(Musteri musteri);
    public:
        explicit Musteri(int Id=0,string adSoyad="",string hesapSifre="",string tcNo="",float Bakiye=0.0);
        ~Musteri();
		Musteri &operator+=(float EklenenTutar);
		Musteri &operator-=(float CekilecekTutar);
		
		float getKullaniciBakiye()const;
		string getAdSoyad()const;
		string getTcNo()const;
		string getHesapSifre()const;
		
		void hesapDuzenle(string,string ,string );
		void hesapDuzenle(int,string,string ,string ,float);
		void sifreDegistir(string);
		
		void setId(int);
		int getId()const;
		
    private:
    	
        void setAdSoyad(string);
        void setTcNo(string);
        void setHesapSifre(string);                
        void setKullaniciBakiye(float);
        
        void paraYatir(float);
        void paraCek(float);
        
		int Id;
        string AdSoyad;
        string TcNo, HesapSifre;
        float kullaniciBakiye;
        


};
#endif
