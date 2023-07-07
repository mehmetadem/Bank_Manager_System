#include <iostream>
#include <string>
#include <cstring>
#include "musteri.h"
using namespace std;
//----------------------------------Operator Overloading--------------------------------------------------------------------
ostream &operator<<(ostream &output, Musteri &musteri)
{
	output<<"Musteri Adi :"<<musteri.getAdSoyad()<<endl
		  <<"Musteri TC :"<<musteri.getTcNo()<<endl
		  <<"Musteri Sifre :"<<musteri.getHesapSifre()<<endl
		  <<"Musteri Bakiye :"<<musteri.getKullaniciBakiye()<<endl;
	
	return output;
}

Musteri &Musteri::operator+=(float EklenenTutar)
{
	paraYatir(EklenenTutar);
	return *this;
}

Musteri &Musteri::operator-=(float CekilenTutar)
{
	paraCek(CekilenTutar);
	return *this;		
}

//----------------------------------Operator Overloading--------------------------------------------------------------------
void SifreBilgisiYaz(Musteri musteri)
{
	cout<<"Mevcut Sifreniz: "<<musteri.getHesapSifre()<<endl;	
}

Musteri::Musteri(int Id,string adSoyad,string hesapSifre,string tcNo,float Bakiye)
{
	setId(Id);
    setAdSoyad(adSoyad);
    setHesapSifre(hesapSifre);
    setTcNo(tcNo);
    setKullaniciBakiye(Bakiye);
}
Musteri::~Musteri()
{
	setAdSoyad(" ");
    setHesapSifre(" ");
    setTcNo(" ");
    setKullaniciBakiye(0);
}
void Musteri::hesapDuzenle(string _adsoyad,string _sifre,string Tc)
{
    setAdSoyad(_adsoyad);
    setHesapSifre(_sifre);
    setTcNo(Tc);
}
void Musteri::hesapDuzenle(int Id,string _adsoyad,string _sifre,string Tc,float bakiye)
{
	setId(Id);
	setAdSoyad(_adsoyad);
    setHesapSifre(_sifre);
    setTcNo(Tc);
    setKullaniciBakiye(bakiye);
}

void Musteri::setAdSoyad(string _adSoyad)
{
    AdSoyad=_adSoyad;
}
string Musteri:: getAdSoyad()const
{
    return AdSoyad;
}


void Musteri::setTcNo(string _tcNo)
{
    TcNo=_tcNo;
}
string Musteri::getTcNo()const
{
    return TcNo;
}


void Musteri::setHesapSifre(string _hesapSifre)
{
    HesapSifre=_hesapSifre;
}


string Musteri::getHesapSifre()const
{
    return HesapSifre;
}

void Musteri::setKullaniciBakiye(float Bakiye)
{
	kullaniciBakiye=Bakiye;
}
float Musteri::getKullaniciBakiye()const
{
	return kullaniciBakiye;
}

void Musteri::sifreDegistir(string yenisifre)
{
    system("cls");
    int eskisifreUzunluk;
    string streskisifre(yenisifre);
    eskisifreUzunluk=streskisifre.size();
   
        if(eskisifreUzunluk!=4)
        {
        cerr<<"HATA:gecersiz sifre denemesi"<<endl;
        }
        else 
        {
        setHesapSifre(yenisifre);
        }
    
   
    
}

void Musteri::paraCek(float tutar)
{
    kullaniciBakiye=kullaniciBakiye-tutar; 
	setKullaniciBakiye(kullaniciBakiye);
}

void Musteri::paraYatir(float tutar)
{
    kullaniciBakiye=kullaniciBakiye+tutar;
	setKullaniciBakiye(kullaniciBakiye);
}

void Musteri::setId(int id)
{
	Id=id;
}
int Musteri::getId()const
{
	return Id;
}
