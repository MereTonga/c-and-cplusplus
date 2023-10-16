#include "Rehber.h"

void Rehber::RehberEkle()
{
	string ad,soyad,telNo;
	system("cls");
	cout << endl << " Isim Soyisim Giriniz : ";
	cin >> ad >> soyad;
	cout << " Telefon Numarasini Giriniz : ";
	cin >> telNo;

	isimListe.push_back(ad + " " + soyad);
	telNoListe.push_back(telNo);
	system("cls");
}

void Rehber::RehberSil()
{
	string ad, soyad;
	system("cls");
	
	if (isimListe.empty() == true && telNoListe.empty() == true)
	{
		cout << endl << " Rehberinizde Silecek Kimse Yok." << endl << endl;
	}
	else
	{
		cout << endl << " Isim Soyisim Giriniz : ";
		cin >> ad >> soyad;
	}

	list<string>::iterator itAd;
	list<string>::iterator itNo;

	for (itAd = isimListe.begin(), itNo = telNoListe.begin(); itAd != isimListe.end() && itNo != telNoListe.end(); itAd++, itNo++)
	{
		if ((ad + " " + soyad) == *itAd)
		{
			isimListe.erase(itAd);
			telNoListe.erase(itNo);
			system("cls");
			break;
		}
	}
}

void Rehber::RehberGor()
{
	list<string>::iterator itAd;
	list<string>::iterator itNo;

	system("cls");

	if (isimListe.empty() == true && telNoListe.empty() == true)
		cout << endl << " Rehberiz Bos." << endl << endl;

	for (itAd = isimListe.begin(), itNo = telNoListe.begin(); itAd != isimListe.end() && itNo != telNoListe.end(); itAd++, itNo++)
		cout << endl << " Isim : " << *itAd << endl << " Tel No : " << *itNo << endl << endl;
		
}