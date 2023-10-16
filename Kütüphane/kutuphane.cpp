#include <iostream>
#include <windows.h> // renk
#include <fstream> // dosya 
#include <conio.h> // getch()
#include <string>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string yoneticiSifre = "155admin551";

ifstream ogrenciUyeOku("Ogrenci Uyeler.txt");
const int ogrenciSayisi = 5;
string ogrenciAdlari[ogrenciSayisi];
string ogrenciNumaralari[ogrenciSayisi];

ifstream kitapListesiOku("Kitap Listesi.txt");
int kitapSayisi = 0;
struct kitap
{
	string kitapAdi;
	string kitapYazari;
}kitaplar[20];

string ogrenciKitaplari[20];
string ogrenciKitaplariYazar[20];
int ogrenciKitapSayisi = 0;
struct ogrenci
{
	string ogrenciAdi;
	string ogrenciNo;
}og;

ifstream talepListesiOku("Talep Listesi.txt");
string talepKitaplar[20];
string talepYazarlar[20];
string talepOgrenciler[20];
string talepOgrenciNolar[20];
int talepSayisi = 0;

ifstream iadeListesiOku("Iade Listesi.txt");
string iadeKitaplar[20];
string iadeYazarlar[20];
string iadeOgrenciler[20];
string iadeOgrenciNolar[20];
int iadeSayisi = 0;



void RenkDegis(int c);
void Baslangic();

void OgrenciListesiOku();
void OgrenciListesi();
void OgrenciGiris();
int OgrenciKontrol(string a,string b);
void Ogrenci();

void YoneticiGiris();
void Yonetici();

void KitapSayisiBul();
void KitapListesiOku();
void KitapListesi();
void KitapSistemi();
void KitapEkle();
void KitapSil();

void Kitaplarim();
void KitaplarimOku();
void TalepEt();
void TalepListesiOku();
void TalepListesi();

void IadeListesiOku();
void IadeEt();
void IadeListesi();



int main()
{
	Baslangic();
	
	RenkDegis(12);
	cout << "\n------Kutuphane Uygulamasi------" << endl ;
	RenkDegis(14);
	cout << "\n  Yonetici Girisi (1)" << endl;
	cout << "\n  Ogrenci Girisi (2)" << endl;
	RenkDegis(12);
	cout << "\n--------------------------------" << endl;
	
	char g = getch();
	if(g == '1')
		YoneticiGiris();
	else if(g == '2') 
		OgrenciGiris();
		
	return 0;
}

void RenkDegis(int c)
{
	SetConsoleTextAttribute(hConsole, c);
}

void Baslangic()
{
	OgrenciListesiOku();

	KitapSayisiBul();

	KitapListesiOku();

	TalepListesiOku();

	IadeListesiOku();
}

void KitapSayisiBul()
{
	string bosOkuma = "";

	if (kitapListesiOku.is_open())
	{
		int i = 0;
		while (getline(kitapListesiOku,bosOkuma))
		{
			if(bosOkuma != "")
			{
				i++;
			}
		}
		kitapSayisi = i/2;
		
		kitapListesiOku.close();
	}
}

void KitapListesiOku()
{
	kitapListesiOku.open("Kitap Listesi.txt");

	string bosSatir = "";

	if(kitapListesiOku.is_open())
		for (int i = 0; i < kitapSayisi; i++)
		{
			getline(kitapListesiOku,kitaplar[i].kitapAdi);
			getline(kitapListesiOku,kitaplar[i].kitapYazari);
			getline(kitapListesiOku,bosSatir);
		}
}

void KitapListesi()
{
	KitapListesiOku();

	for(int i = 0; i < kitapSayisi;i++)
	{
		if(kitaplar[i].kitapAdi != "" && kitaplar[i].kitapYazari != "")
		{
			RenkDegis(9);
			cout << "\n  Kitap Adi = ";
			RenkDegis(15);
			cout << kitaplar[i].kitapAdi << endl;
			RenkDegis(9);
			cout << "  Kitabin Yazari = ";
			RenkDegis(15);
			cout << kitaplar[i].kitapYazari << endl;
		}
	}
}

void KitapSistemi()
{
	system("cls");
	
	RenkDegis(12);
	cout << "\n------Kitap Sistemi------" << endl;

	KitapListesi();
	
	RenkDegis(12);
	cout << "\n--------------------------" << endl;
	RenkDegis(14);
	cout << "\n  Kitap Ekle (1)" << endl;
	cout << "\n  Kitap Sil (2)" << endl;
	cout << "\n  Geri Don (3)" << endl;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;
	
	char g = getch();
	if(g == '1')
		KitapEkle();
	else if(g == '2')
		KitapSil();
	else if(g == '3')
		Yonetici();
}

void KitapEkle()
{
	system("cls");
	
	string isim,yazar;
	
	RenkDegis(14);
	cout << "\n Kitabin Ismini Giriniz : ";
	RenkDegis(11);
	getline(cin,isim);
	RenkDegis(14);
	cout << " Kitabin Yazarini Giriniz : ";
	RenkDegis(11);
	getline(cin,yazar);

	kitapSayisi++;
	kitaplar[kitapSayisi-1].kitapAdi = isim;
	kitaplar[kitapSayisi-1].kitapYazari = yazar;

	ofstream kitapListesiYaz("Kitap Listesi.txt");

	for (int i = 0; i < kitapSayisi; i++)
	{
		if(kitaplar[i].kitapAdi != "" && kitaplar[i].kitapYazari != "")
		{
			kitapListesiYaz << kitaplar[i].kitapAdi << endl;
			kitapListesiYaz << kitaplar[i].kitapYazari << endl << endl;
		}
	}

	KitapSistemi();
}

void KitapSil()
{
	system("cls");

	RenkDegis(12);
	cout << "\n------Kitap Silme Sistemi------" << endl;

	for (int i = 0; i < kitapSayisi; i++)
	{
		if(kitaplar[i].kitapAdi != "" && kitaplar[i].kitapYazari != "")
		{
			RenkDegis(9);
			cout << "\n  " << kitaplar[i].kitapAdi << " - " << kitaplar[i].kitapYazari;
			RenkDegis(14);
			cout << " (" << i+1 << ") "<< endl; 
		}
	}

	RenkDegis(12);
	cout << "\n--------------------------------" << endl;
	RenkDegis(14);
	cout << "\n  Geri Don (0)" << endl;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;

	char g = getch();

	if((g-'0') != 0 && (g-'0') <= kitapSayisi)
	{
		ofstream kitapListesiYaz("Kitap Listesi.txt");

		for (int i = 0; i < kitapSayisi; i++)
		{
			if ((i != (g-'0')-1) && (kitaplar[i].kitapAdi != "") && (kitaplar[i].kitapYazari != ""))
			{
				kitapListesiYaz << kitaplar[i].kitapAdi << endl;
				kitapListesiYaz << kitaplar[i].kitapYazari << endl << endl;
			}
			else
			{
				kitaplar[i].kitapAdi = "";
				kitaplar[i].kitapYazari = "";
			}
		}
	}

	KitapSistemi();
}

void YoneticiGiris()
{
	system("cls");

	string g;
	
	RenkDegis(14);
	cout << "\n Yonetici Sifresini Giriniz : ";
	RenkDegis(11);
	getline(cin,g);
	
	while(true)
	{
		if(g == yoneticiSifre)
			break;
		else
		{
			RenkDegis(14);
			cout << " Yanlis Sifre Lutfen Tekrar Deneyiniz : ";
			RenkDegis(11);
			getline(cin,g);
		}
	}
	
	Yonetici();
}

void Yonetici()
{
	system("cls");
	
	RenkDegis(12);
	cout << "\n------Yonetici Sistemi------" << endl;
	RenkDegis(14);
	cout << "\n  Kitap Sistemi (1)" << endl;
	cout << "\n  Ogrenci Listesi (2)" << endl;
	cout << "\n  Talep Listesi (3)" << endl;
	cout << "\n  Iade Listesi (4)" << endl;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;
	
	char g = getch();
	if(g == '1')
		KitapSistemi();
	else if(g == '2')
		OgrenciListesi();
	else if(g == '3')
		TalepListesi();
	else if(g == '4')
		IadeListesi();
}

int OgrenciKontrol(string a,string b)
{
	for(int i = 0;i < ogrenciSayisi;i++)
	{
		if(a == ogrenciAdlari[i] && b == ogrenciNumaralari[i])
		{
			og.ogrenciAdi = a;
			og.ogrenciNo = b;
			return 1;
			break;
		}
	}
}

void OgrenciGiris()
{
	system("cls");

	string isim,no;
	
	RenkDegis(14);
	cout << "\n Isminizi ve Soyisminizi Yaziniz : ";
	RenkDegis(11);
	getline(cin,isim);
	RenkDegis(14);
	cout << " Ogrenci Numaranizi Giriniz : ";
	RenkDegis(11);
	getline(cin,no);
	
	while(true)
	{
		if(OgrenciKontrol(isim,no))
			break;
		else
		{
			system("cls");
			RenkDegis(14);
			cout << "\n Bilgiler Hatali Lutfen Tekrardan Yaziniz ! " << endl;
			cout << "\n Isminizi ve Soyisminizi Yaziniz : ";
			RenkDegis(11);
			getline(cin,isim);
			RenkDegis(14);
			cout << " Ogrenci Numaranizi Giriniz : ";
			RenkDegis(11);
			getline(cin,no);
			OgrenciKontrol(isim,no);
		}
	}
	
	Ogrenci();
}

void Ogrenci()
{
	system("cls");

	RenkDegis(12);
	cout << "\n------Ogrenci Sistemi------" << endl;
	RenkDegis(14);
	cout << "\n  Kitaplarim (1)" << endl;
	cout << "\n  Kitap Talep Et (2)" << endl;
	cout << "\n  Kitap Iade Et (3)" << endl;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;
	
	char g = getch();
	if(g == '1')
		Kitaplarim();
	else if(g == '2')
		TalepEt();
	else if(g == '3')
		IadeEt();
}

void OgrenciListesi()
{
	system("cls");
	
	RenkDegis(12);
	cout << "\n------Ogrenci Listesi------" << endl;
	RenkDegis(14);
	for(int i = 0; i < ogrenciSayisi;i++)
	{
		RenkDegis(9);
		cout << "\n  Ogrenci Adi = ";
		RenkDegis(15);
		cout << ogrenciAdlari[i] << endl;
		RenkDegis(9);
		cout << "  Ogrenci Numarasi = ";
		RenkDegis(15);
		cout << ogrenciNumaralari[i] << endl;
	}
	RenkDegis(12);
	cout << "\n----------------------------" << endl;
	RenkDegis(14);
	cout << "\n  Geri Don (1)" << endl ;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;

	char g = getch();
	if(g == '1')
		Yonetici();
}

void OgrenciListesiOku()
{
	string bosSatir = "";
	if(ogrenciUyeOku.is_open())
	{
		for(int i = 0;i < ogrenciSayisi;i++)
		{
			getline(ogrenciUyeOku,ogrenciAdlari[i]);
			getline(ogrenciUyeOku,ogrenciNumaralari[i]);
			getline(ogrenciUyeOku,bosSatir);
		}
		ogrenciUyeOku.close();
	}
}

void KitaplarimOku()
{
	string bosSatir = "";
	string g = og.ogrenciAdi+".txt";
	const char* dosyaAdi = g.c_str();
	ifstream kitaplarimOku(dosyaAdi);
	if(kitaplarimOku.is_open())
	{
		ogrenciKitapSayisi = 0;
		ogrenciKitaplari->clear();
		ogrenciKitaplariYazar->clear();

		for (int i = 0;!(kitaplarimOku.eof());i++)
		{
			getline(kitaplarimOku,ogrenciKitaplari[i]);
			getline(kitaplarimOku,ogrenciKitaplariYazar[i]);
			getline(kitaplarimOku,bosSatir);
			if(ogrenciKitaplari[i] != "" && ogrenciKitaplariYazar[i] != "")
				ogrenciKitapSayisi++;
		}

		kitaplarimOku.close();
	}
	else
		ofstream kitaplarimYaz(dosyaAdi);
}

void Kitaplarim()
{
	system("cls");
	KitaplarimOku();

	RenkDegis(12);
	cout << "\n------Kitaplariniz------"<< endl;

	if(ogrenciKitapSayisi > 0)
	{
		for (int i = 0;i < ogrenciKitapSayisi;i++)
		{
			if(ogrenciKitaplari[i] != "" && ogrenciKitaplariYazar[i] != "")
			{
				RenkDegis(9);
				cout << "\n  "<< ogrenciKitaplari[i] << " - " << ogrenciKitaplariYazar[i] << endl;
			}
		}
	}
	else
		cout << "\n  Kitabiniz Bulunmamaktadir." << endl;

	RenkDegis(12);
	cout << "\n-------------------------" << endl;
	RenkDegis(14);
	cout << "\n  Geri Don (1)" << endl ;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;

	char a = getch();
	if(a == '1')
		Ogrenci();
}

void TalepEt()
{
	system("cls");
	talepListesiOku.open("Talep Listesi.txt");

	RenkDegis(12);
	cout << "\n------Talep Sistemi------"<< endl;

	for (int i = 0; i < kitapSayisi; i++)
	{
		if(kitaplar[i].kitapAdi != "" && kitaplar[i].kitapYazari != "")
		{
			RenkDegis(9);
			cout << "\n  " << kitaplar[i].kitapAdi << " - " << kitaplar[i].kitapYazari;
			RenkDegis(14);
			cout << " (" << i+1 << ") "<< endl; 
		}
	}

	RenkDegis(12);
	cout << "\n--------------------------------" << endl;
	RenkDegis(14);
	cout << "\n  Geri Don (0)" << endl;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;

	char g = getch();

	if((g-'0') != 0 && (g-'0') <= kitapSayisi)
	{
		TalepListesiOku();
		ofstream talepListesiYaz("Talep Listesi.txt");

		for	(int i = 0; i < talepSayisi;i++)
		{
			if(talepKitaplar[i] != "" && talepYazarlar[i] != "" && talepOgrenciler[i] != "" && talepOgrenciNolar[i] != "")
			{
				talepListesiYaz << talepKitaplar[i] << endl;
				talepListesiYaz << talepYazarlar[i] << endl;
				talepListesiYaz << talepOgrenciler[i] << endl; 
				talepListesiYaz << talepOgrenciNolar[i] << endl << endl;
			}
		}

		talepSayisi++;

		for (int i = 0; i < kitapSayisi; i++)
		{
			if (i == (g-'0')-1 && (kitaplar[i].kitapAdi != "") && (kitaplar[i].kitapYazari != ""))
			{
				talepListesiYaz << kitaplar[i].kitapAdi << endl;
				talepListesiYaz << kitaplar[i].kitapYazari << endl;
				talepListesiYaz << og.ogrenciAdi << endl; 
				talepListesiYaz << og.ogrenciNo << endl << endl;
			}
		}
	}

	talepListesiOku.close();

	Ogrenci();
}

void TalepListesiOku()
{
	string bosSatir = "";
	if(talepListesiOku.is_open())
	{
		talepSayisi = 0;
		for (int i = 0;!(talepListesiOku.eof()); i++)
		{
			getline(talepListesiOku,talepKitaplar[i]);
			getline(talepListesiOku,talepYazarlar[i]);
			getline(talepListesiOku,talepOgrenciler[i]);
			getline(talepListesiOku,talepOgrenciNolar[i]);
			getline(talepListesiOku,bosSatir);
			if(talepKitaplar[i] != "" && talepYazarlar[i] != "" && talepOgrenciler[i] != "" && talepOgrenciNolar[i] != "")
				talepSayisi++;
		}
		talepListesiOku.close();
	}
}

void TalepListesi()
{
	TalepListesiOku();
	talepListesiOku.open("Talep Listesi.txt");

	system("cls");
	
	RenkDegis(12);
	cout << "\n------Talep Listesi------"<< endl;
	
	if(talepSayisi > 0)
	{
		for(int i = 0;i < talepSayisi;i++)
		{
			if(talepKitaplar[i] != "" && talepYazarlar[i] != "" && talepOgrenciler[i] != "" && talepOgrenciNolar[i] != "")
				{
					RenkDegis(9);
					cout << "\n  Ogrenci : ";
					RenkDegis(15);
					cout << talepOgrenciler[i] << " - " << talepOgrenciNolar[i];
					RenkDegis(9);
					cout << "\n  Talep : ";
					RenkDegis(15);
					cout << talepKitaplar[i] << " - " << talepYazarlar[i];
					RenkDegis(14);
					cout << " (" << i+1 << ") "<< endl; 
				}
		}
	}
	else
	{
		RenkDegis(14);
		cout << "\n  Talep Bulunmamaktadir." << endl;
	}

	RenkDegis(12);
	cout << "\n--------------------------" << endl;
	RenkDegis(14);
	cout << "\n  Geri Don (0)" << endl;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;

	char g = getch();

	if ((g-'0') != 0 && (g-'0') <= talepSayisi)
	{
		ofstream talepListesiYaz("Talep Listesi.txt");

		for (int i = 0; i < talepSayisi; i++)
		{
			if ((i != (g-'0')-1) && talepKitaplar[i] != "" && talepYazarlar[i] != "" && talepOgrenciler[i] != "" && talepOgrenciNolar[i] != "")
			{
				talepListesiYaz << talepKitaplar[i] << endl;
				talepListesiYaz << talepYazarlar[i] << endl;
				talepListesiYaz << talepOgrenciler[i] << endl; 
				talepListesiYaz << talepOgrenciNolar[i] << endl << endl;
			}
			else
			{
				og.ogrenciAdi = talepOgrenciler[i];
				og.ogrenciNo = talepOgrenciNolar[i];

				string bosSatir = "";
				string x = og.ogrenciAdi+".txt";
				const char* dosyaAdi = x.c_str();

				ifstream kitapOku(dosyaAdi);

				if(kitapOku.is_open())
				{
					ogrenciKitapSayisi = 0;
					ogrenciKitaplari->clear();
					ogrenciKitaplariYazar->clear();

					for(int j = 0;!(kitapOku.eof());j++)
					{
						getline(kitapOku,ogrenciKitaplari[j]);
						getline(kitapOku,ogrenciKitaplariYazar[j]);
						getline(kitapOku,bosSatir);
						if(ogrenciKitaplari[j] != "" && ogrenciKitaplariYazar[j] != "")
							ogrenciKitapSayisi++;
					}

					ofstream kitapYaz(dosyaAdi);

					for(int k = 0;k < ogrenciKitapSayisi;k++)
					{
						kitapYaz << ogrenciKitaplari[k] << endl;
						kitapYaz << ogrenciKitaplariYazar[k] << endl << endl;
					}

					kitapYaz << talepKitaplar[i] << endl;
					kitapYaz << talepYazarlar[i] << endl << endl;
				}
				else
				{
					ofstream kitapYaz(dosyaAdi);

					kitapYaz << talepKitaplar[i] << endl;
					kitapYaz << talepYazarlar[i] << endl << endl;
				}
			}
		}
	}

	Yonetici();
}

void IadeListesiOku()
{
	string bosSatir = "";
	if(iadeListesiOku.is_open())
	{
		iadeSayisi = 0;
		for (int i = 0;!(iadeListesiOku.eof()); i++)
		{
			getline(iadeListesiOku,iadeKitaplar[i]);
			getline(iadeListesiOku,iadeYazarlar[i]);
			getline(iadeListesiOku,iadeOgrenciler[i]);
			getline(iadeListesiOku,iadeOgrenciNolar[i]);
			getline(iadeListesiOku,bosSatir);
			if(iadeKitaplar[i] != "" && iadeYazarlar[i] != "" && iadeOgrenciler[i] != "" && iadeOgrenciNolar[i] != "")
				iadeSayisi++;
		}
		iadeListesiOku.close();
	}
}

void IadeEt()
{
	system("cls");

	iadeListesiOku.open("Iade Listesi.txt");
	IadeListesiOku();

	KitaplarimOku();

	RenkDegis(12);
	cout << "\n------Iade Sistemi------" << endl;

	if(ogrenciKitapSayisi > 0)
	{
		for (int i = 0;i < ogrenciKitapSayisi;i++)
		{
			if(ogrenciKitaplari[i] != "" && ogrenciKitaplariYazar[i] != "")
			{
				RenkDegis(9);
				cout << "\n  "<< ogrenciKitaplari[i] << " - " << ogrenciKitaplariYazar[i];
				RenkDegis(14);
				cout << " (" << i+1 << ") "<< endl;
			}
		}
	}
	else
	{
		RenkDegis(14);
		cout << "\n  Kitabiniz Bulunmamaktadir." << endl;
	}

	RenkDegis(12);
	cout << "\n--------------------------------" << endl;
	RenkDegis(14);
	cout << "\n  Geri Don (0)" << endl;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;

	char a = getch();

	if((a-'0') != 0 && (a-'0') <= ogrenciKitapSayisi)
	{
		iadeListesiOku.open("Iade Listesi.txt");
		IadeListesiOku();
		ofstream iadeListesiYaz("Iade Listesi.txt");

		for(int i = 0; i < iadeSayisi;i++)
		{
			if(iadeKitaplar[i] != "" && iadeYazarlar[i] != "" && iadeOgrenciler[i] != "" && iadeOgrenciNolar[i] != "")
			{
				iadeListesiYaz << iadeKitaplar[i] << endl;
				iadeListesiYaz << iadeYazarlar[i] << endl;
				iadeListesiYaz << iadeOgrenciler[i] << endl; 
				iadeListesiYaz << iadeOgrenciNolar[i] << endl << endl;
			}
		}

		for (int  i = 0; i < ogrenciKitapSayisi; i++)
		{
			if (i == (a-'0')-1 && (ogrenciKitaplari[i] != "") && (ogrenciKitaplariYazar[i] != ""))
			{
				iadeListesiYaz << ogrenciKitaplari[i] << endl;
				iadeListesiYaz << ogrenciKitaplariYazar[i] << endl;
				iadeListesiYaz << og.ogrenciAdi << endl; 
				iadeListesiYaz << og.ogrenciNo << endl << endl;
			}
		}

		iadeSayisi++;
	}

	iadeListesiOku.close();

	Ogrenci();
}

void IadeListesi()
{
	IadeListesiOku();
	iadeListesiOku.open("Iade Listesi.txt");

	system("cls");
	
	RenkDegis(12);
	cout << "\n------Iade Listesi------"<< endl;


	if(iadeSayisi > 0)
	{
		for(int i = 0;i < iadeSayisi;i++)
		{
			if(iadeKitaplar[i] != "" && iadeYazarlar[i] != "" && iadeOgrenciler[i] != "" && iadeOgrenciNolar[i] != "")
				{
					RenkDegis(9);
					cout << "\n  Ogrenci : ";
					RenkDegis(15);
					cout << iadeOgrenciler[i] << " - " << iadeOgrenciNolar[i];
					RenkDegis(9);
					cout << "\n  Iade : ";
					RenkDegis(15);
					cout << iadeKitaplar[i] << " - " << iadeYazarlar[i];
					RenkDegis(14);
					cout << " (" << i+1 << ") "<< endl; 
				}
		}
	}
	else
	{
		RenkDegis(14);
		cout << "\n  Iade Bulunmamaktadir." << endl;
	}
	

	RenkDegis(12);
	cout << "\n--------------------------" << endl;
	RenkDegis(14);
	cout << "\n  Geri Don (0)" << endl;
	RenkDegis(12);
	cout << "\n----------------------------" << endl;

	char g = getch();

	if((g-'0') != 0 && (g-'0') <= iadeSayisi)
	{
		ofstream iadeListesiYaz("Iade Listesi.txt");

		for(int i = 0;i < iadeSayisi;i++)
		{
			if ((i != (g-'0')-1) && iadeKitaplar[i] != "" && iadeYazarlar[i] != "" && iadeOgrenciler[i] != "" && iadeOgrenciNolar[i] != "")
			{
				iadeListesiYaz << iadeKitaplar[i] << endl;
				iadeListesiYaz << iadeYazarlar[i] << endl;
				iadeListesiYaz << iadeOgrenciler[i] << endl; 
				iadeListesiYaz << iadeOgrenciNolar[i] << endl << endl;
			}
			else
			{
				og.ogrenciAdi = iadeOgrenciler[i];
				og.ogrenciNo = iadeOgrenciNolar[i];

				string bosSatir = "";
				string x = og.ogrenciAdi+".txt";
				const char* dosyaAdi = x.c_str();

				ifstream kitapOku(dosyaAdi);

				if(kitapOku.is_open())
				{
					ogrenciKitapSayisi = 0;
					ogrenciKitaplari->clear();
					ogrenciKitaplariYazar->clear();

					for(int j = 0;!(kitapOku.eof());j++)
					{
						getline(kitapOku,ogrenciKitaplari[j]);
						getline(kitapOku,ogrenciKitaplariYazar[j]);
						getline(kitapOku,bosSatir);
						if(ogrenciKitaplari[j] != "" && ogrenciKitaplariYazar[j] != "")
							ogrenciKitapSayisi++;
					}

					ofstream kitapYaz(dosyaAdi);

					for(int k = 0;k < ogrenciKitapSayisi;k++)
					{
						if(iadeKitaplar[i] != ogrenciKitaplari[k] && iadeYazarlar[i] != ogrenciKitaplariYazar[k])
						{
							kitapYaz << ogrenciKitaplari[k] << endl;
							kitapYaz << ogrenciKitaplariYazar[k] << endl << endl;	
						}
					}
				}
			}
		}
	}

	Yonetici();
}
