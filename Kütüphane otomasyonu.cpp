#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

 int sayac;
 int kitapKontrol;

 class Kitap

 {
    public:

    int kitapkodu;
    string kitapadi;
    string kitapyazariadi;
    string kitapyazarisoyadi;

    void KitapbilgileriGir();
    void KitapbilgileriGoster();


 };
   
    void Kitap::KitapbilgileriGir()

   {
    
    cout<<"Kitap kodunu giriniz: ";
    cin>>kitapkodu;

    cout<<"Kitap adini giriniz: ";
    cin>>kitapadi;

    cout<<"Kitap yazarinin adini giriniz: ";
    cin>>kitapyazariadi;

    cout<<"Kitap yazarinin soyadini giriniz: ";
    cin>>kitapyazarisoyadi;
   

   };

   void Kitap::KitapbilgileriGoster()

   {

    cout<<"Kitap kodu: "<<kitapkodu<<endl;
    cout<<"Kitap adi: "<<kitapadi<<endl;
    cout<<"Kitap yazarinin adi: "<<kitapyazariadi<<endl;
    cout<<"Kitap yazarinin soyadi: "<<kitapyazarisoyadi<<endl;

   };

   class KitapKontrol

   {
    
    public: 
    int kitapkod;

    string kitapad;
    string kitapyazarad;
    string kitapyazarsoyad;

   };

   class Kutuphane 
   {
     
     public:

     void Kitapekle();
     void KitapBul( int no );
     void KitapSil( int no );

   };

   void Kutuphane::Kitapekle()

   {
    
    fstream kitapkayit;
    Kitap kitap;
    KitapKontrol kitapkont;
    kitapkayit.open("kitaplar.txt",ios::app);
    kitap.KitapbilgileriGir();

     while(kitapkayit>>kitapkont.kitapkod>>kitapkont.kitapad>>kitapkont.kitapyazarad>>kitapkont.kitapyazarsoyad)

     {

       if(kitap.kitapkodu==kitapkont.kitapkod)
       {

        kitapkontrol++;
        cout<<"Bu kitap zaten kayitli"<<endl;

       }

     }

     kitapkayit.close();
     kitapkayit.open("kitaplar.txt",ios::app);

     if(kitapkontrol==0)
     {

        kitapkayit<<std::left<<setw(10)<<kitap.kitapkodu<<setw(20)<<kitap.kitapadi<<setw(15)<<kitap.kitapyazariadi<<setw(10)<<kitap.kitapyazarisoyadi<<endl;
        
        // Genisligi belirlemek icin setw() fonksiyonu kullanildi.

        cout<<"Kitap basariyla eklendi"<<endl;

     }

        kitapkayit.close(); 

   }

   void Kutuphane::KitapBul( int no )

   {
    
    fstream kitapkayit;
    Kitap kitap;
    kitapkayit.open("kitaplar.txt",ios::in);

    while(kitapkayit>>kitap.kitapkodu>>kitap.kitapadi>>kitap.kitapyazariadi>>kitap.kitapyazarisoyadi)

    {

      if(kitap==no.kitapkodu)
      {

        kitap.KitapbilgileriGoster();
        sayac++;

      }

    }


    kitapkayit.close();

   }

   void KitaplariListele()

   {

    fstream kitapkayit;
    Kitap kitap;
    kitapkayit.open("kitaplar.txt",ios::in);

    cout<<"Kitap kodu"<<"Kitap adi"<<"Kitap yazarinin adi"<<"Kitap yazarinin soyadi"<<endl;

    while(kitapkayit>>kitap.kitapkodu>>kitap.kitapadi>>kitap.kitapyazariadi>>kitap.kitapyazarisoyadi)

    {

      kitap.KitapbilgileriGoster();

    }

    kitapkayit.close();

   }

   void Kutuphane::KitapSil ( int no )

   {

    fstream kitapsil;
    fstream yenidosya;

    Kitap kitap;

    kitapsil.open("kitaplar.txt",ios::in);
    yenidosya.open("yenidosya.txt",ios::out);

    while(kitapsil>>kitap.kitapkodu>>kitap.kitapadi>>kitap.kitapyazariadi>>kitap.kitapyazarisoyadi)

    {

        if (no!=kitap.kitapkodu)

		{
			
		yenidosya<<std::left<<setw(10)<<kitap.kitapkodu
		<<setw(20)<<kitap.kitapadi<<
		setw(15)<<kitap.kitapyazariadi<<
		setw(10)<<kitap.kitapyazarisoyadi<<endl;

		}

		else

		{

			sayac++;
		}

	}

	kitapsil.close();
     
     remove("kitaplar.txt");
        yenidosya.close();
        rename("yenidosya.txt","kitaplar.txt");

  
    }

    void AnaMenu()

    {
      
      Kutuphane islemler;

      int secim;
      int no;
      int deletekitap;

      cout<<std::left<<setw(15)<<"TRAKYA UNIVERSITESI"<<endl;
      cout<<"1-) KİTAP EKLE "<<endl;
	  cout<<"2-) KITAP ARA "<<endl;
	  cout<<"3-) KITAP SİL "<<endl;
	  cout<<"9-) CIKIS "<<endl;
	  cout<<"SEÇİMİNİZ.....:";
	  cin>>secim;

	  switch (secim)

      {

        case 1:
        kitapkontrol=0;
        islemler.Kitapekle();

        break;

        case 2:
        sayac=0;

        system("cls");
        cout<<std::left<<setw(15)<<"TRAKYA UNIVERSITESI"<<endl;

        KitaplariListele();

        cout<<"Bulmak istediginiz kitabin kodunu giriniz: ";
        cin>>no;
        islemler.KitapBul(int no);
        
        if(sayac == 0)

        {

            cout<<"Aradiginiz kitap bulunamadi"<<endl;
            int islem;
            islem=0;

            cout<<endl<<"0-Ana Menü"<<endl<<"9-Çıkış"<<endl;
            cin>>islem;

            if(islem==0)

            {
                
                system("cls");
                AnaMenu();

            }

            else if(islem==9)

            {

                exit(0);

            }

            else
		{

			cout<<"Yanlış Seçim Yaptınız";
		}

		   system("cls");
		   AnaMenu();
		   break;	

        }

         case 3:
         sayac=0;

        system("cls");
		cout<<std::left<<setw(15)<<"TRAKYA UNUVERSITESI"<<endl;
		KitaplariListele();
		cout<<"Silmek İstediğiniz Kitap Kodunu Giriniz....:"; cin>>deletekitap; islemler.KitapSil(deletekitap);

		if (sayac==0)
		{
			cout<<"Kitap Bulunamadı";
			int islem=0;
			cout<<endl<<"0-Ana Menü"<<endl<<"9-Çıkış"<<endl;
		cin>>islem;
		if (islem==0)

		{

			system("cls");
			AnaMenu();

		}

		else if (islem==9)

		{

			exit(0);
		}

		else

		{

			cout<<"Yanlış Seçim Yaptınız";
		}

			system("cls");
		    AnaMenu();
		    break;

        }	
      
        

        case 9:exit(0); break;
	    default:cout<<"Yanlış Seçim Yaptınız"; system("cls"); AnaMenu();
		break;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	
	AnaMenu();
	int islem=0;
	do
	{
		cout<<"0-Ana Menü"<<endl<<"9-Çıkış"<<endl;
		cin>>islem;
		if (islem==0)

		{

			system("cls");
			AnaMenu();
		}

		else if (islem==9)

		{

			exit(0);
		}

		else
		{

			cout<<"Yanlış Seçim Yaptınız";
		}

	} 
  
    while (islem==0);
	
	
	return 0;

}




      



    
