#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "musteri.h"
#include "ekran.h"
using namespace std;

void Ekran::KarsilamaMesaji()
{
	
	cout<<"DUDU bankaya hos geldiniz"<<endl;
}


void Ekran::anaSayfa()
{
	Giris();
	KarsilamaMesaji();
    int deger;
    cout<<"hesabiniz var mi?[hayir ise 1,evet ise 2]"<<endl;
    cin>>deger;
    switch(deger)
    {
    	case 1:
    		hesapOlusturmaSayfasi();
    	break;
    	case 2:
    		kullaniciGirisi();
    	break;
    	default:
    		cerr<<"HATA:gecersiz tuslama 1 veya 2 yi tuslayiniz"<<endl;
     		anaSayfa();
     	break;
	}
    
}



int Ekran::kullaniciIslem(int index)
{
	cout<<endl;
	
    int secim;
    cout<<"para yatirma icin 1'i tuslayiniz"<<endl;
    cout<<"para cekmek icin 2'yi tuslayiniz"<<endl;
    cout<<"Kullanici Bilgileri icin 3'yi tuslayiniz"<<endl;
    cout<<"sifreyi degistirmek icin 4'u tuslayiniz"<<endl;
    cout<<"ana sayfaya donmek icin 5'u tuslayiniz"<<endl;
    cout<<"cikis icin 6'u tuslayiniz"<<endl;
    cout<<"islem munarasi giriniz"<<endl;
    cin>>secim;
	switch (secim)
	{
		case 1:
			paraYatir(index);
		break;
		case 2:
			paraCek(index);
		break;
		case 3:
			kullaniciBilgileri(index);
		break;
		case 4:
			sifreDegistir(index);
		break;
		case 5:
			anaSayfa();
		break;
		case 6:
			return 0;
		break;
		default:
			cout<<"Gecersiz Islem Numarasi!!!"<<endl;
			kullaniciIslem(index);
		break;
	}
}


void Ekran::hesapOlusturmaSayfasi()
{
    static int i=1;
    int a,TcKontroller;
    string AdSoyad;
    string TcNo,HesapSifre;
    int tcNoUzunluk,hesapSifreUzunluk;
    tcNo:
    cout<<endl;
    cout<<"Kullanici Ismi giriniz:"<<endl;
	cin>>AdSoyad;

    cout<<"Tc kimlik numaranizi giriniz:"<<endl;
	cin>>TcNo;
	TcKontroller=IndexBulma(TcNo);
	if(TcKontroller==0)
	{
		string strtc(TcNo);
    	tcNoUzunluk=strtc.size();
    	if(tcNoUzunluk!=11)
    	{
			cerr<<"HATA:tc kimlik numaranizi tekrardan giriniz"<<endl;
			goto tcNo;
		}
    	
    	system("cls");
    	hesapSifre:
    	cout<<"4 haneli sifrenizi giriniz"<<endl;
    	cin>>HesapSifre;
    	string strsifre(HesapSifre);
    	
		hesapSifreUzunluk=strsifre.size();
    	if(hesapSifreUzunluk!=4)
    	{
        	cerr<<"HATA:4 haneli bir sifre giriniz"<<endl;
        	goto hesapSifre;
    	}
    	i=at();
    	musteriler[i].hesapDuzenle(i,AdSoyad,HesapSifre,TcNo,0);
    	a=i;
    	++i;
		st(i);
    	cout<<"hesabiniz olusturuldu";
    	
    	KullaniciBilgileri();
  		
    	kullaniciIslem(a);
	}
	else 
	{
		system("cls");
		cout<<"Ayni TC Ile 2 Defa Kayit Olmazssiniz!!"<<endl;
		anaSayfa();
	}	
    
}


void Ekran::kullaniciGirisi()
{
    system("cls");
    anaSayfa:
	int index;
    string tc,tcNo, _tcNo, hesapSifre, _sifre;
    int _tcNoUzunluk, _hesapSifreUzunluk ;

    cout<<"tc kimlik numaranizi giriniz:";
    cin>>_tcNo;
	index=IndexBulma(_tcNo);
   
    string strtc(_tcNo);
    _tcNoUzunluk=strtc.size();
     tc=musteriler[index].getTcNo();
    if(tc!=_tcNo)
    {
        cerr<<"HATA:yanlis tc girdiniz!"<<endl;
        goto anaSayfa;
    }
    else if (_tcNoUzunluk!=11)
    {
        cerr<<"HATA: gecersiz tc kimlik numarasi"<<endl;
        anaSayfa();
    }
    else 
    {
        cout<<"girilen tc dogrulandi"<<endl;
       
    }
    sifre:
    cout<<"sifrenizi giriniz"<<endl;
    cin>>_sifre;
    string strsifre(_sifre);
    _hesapSifreUzunluk=strsifre.size();
    if(musteriler[index].getHesapSifre()!=_sifre)
    {
        cerr<<"HATA:gecersiz sifre"<<endl;
        goto sifre;
    }
    else if(_hesapSifreUzunluk!=4)
    {
        cerr<<"HATA: gecersiz sifre denemesi";
        goto sifre;
    }
    else
    {
        cout<<"Sifre Dogru"<<endl;
    }
    kullaniciIslem(index);
    
}

void Ekran::paraYatir(int index)
{

	float tutar;
	system("cls");
	cout<<"Lutfen Eklencek Tutari Giriniz:";
	cin>>tutar;
	musteriler[index]+=tutar;
	cout<<"Guncel Bakiye:"<<musteriler[index].getKullaniciBakiye()<<endl;
	KullaniciBilgileri();
	kullaniciIslem(index);
	
}
void Ekran::paraCek(int index)
{
	system("cls");
	float tutar;
	float hesap;
	hesap=musteriler[index].getKullaniciBakiye();
	system("cls");
	cout<<"Lutfen Cekilecek Tutari Giriniz:";
	cin>>tutar;
	if(hesap<tutar)
	{
		cout<<"Aktif Bakiyeniz:"<<musteriler[index].getKullaniciBakiye()<<endl;
		cout<<"Lutfen Gecerli Tutarla Yeniden Deneyiniz"<<endl;
		kullaniciIslem(index);
	}
	else
	{
		musteriler[index]-=tutar;
	
		cout<<"Guncel Bakiye:"<<musteriler[index].getKullaniciBakiye()<<endl;
		KullaniciBilgileri();
		kullaniciIslem(index);
	}

}
void Ekran::kullaniciBilgileri(int index)
{
	system("cls");
	cout<<musteriler[index];
	kullaniciIslem(index);
}

void Ekran::sifreDegistir(int index)
{
	system("cls");
	string yenisifre;
	cout<<"Yeni Sifre Giriniz:";
	cin>>yenisifre;
	musteriler[index].sifreDegistir(yenisifre);
	SifreBilgisiYaz(musteriler[index]);
	KullaniciBilgileri();
	kullaniciIslem(index);
}

int Ekran::IndexBulma(string TCNO)
{
	string tc;
	int i=0;
	int index=0;
	while(i<20)
	{
		tc=musteriler[i].getTcNo();
    	if(TCNO==tc)
    	{
    		index=i;
    		break;
		}
		else 
		{
			i++;	
		}
		
	}
	return index;
}

void Ekran::KullaniciBilgileri()
{

	int i;
	remove("Kullanici.txt");
	ofstream Kullanici;
	Kullanici.open("Kullanici.txt",ios::app);
	for(i=1;i<20;i++)
	{
		if(musteriler[i].getTcNo()!="")
		{
			Kullanici<<endl<<musteriler[i].getId()<<setw(20)<<musteriler[i].getAdSoyad()<<setw(20)<<musteriler[i].getTcNo()<<setw(20)<<musteriler[i].getHesapSifre()<<setw(20)<<musteriler[i].getKullaniciBakiye();
		}
	}
}

void Ekran::VerileriCek()
{
	float bakiye;
	int id=1;
	string isim,sifre,Tc;
	ifstream VerileriCek("Kullanici.txt");
	while(!(VerileriCek.eof()))
	{
		
		VerileriCek>>id>>isim>>Tc>>sifre>>bakiye;
		musteriler[id].hesapDuzenle(id,isim,sifre,Tc,bakiye);
	}
	VerileriCek.close();
}
void Ekran::Giris()
{
	ofstream st;
	st.open("st.txt",ios::app);
	st.close();
	ofstream Kullanici;
	Kullanici.open("Kullanici.txt",ios::app);
	Kullanici.close();
	VerileriCek();
}
void Ekran::st(int a)
{
	remove("st.txt");
	ofstream st;
	st.open("st.txt",ios::app);
	st<<a;
}
int Ekran::at()
{
	int a;
	ifstream st("st.txt");
	st>>a;
	
	
	return a;
}
