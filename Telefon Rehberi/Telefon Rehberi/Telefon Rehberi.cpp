#include "Rehber.h"

int Baslangic()
{
	cout << "* * * * * * * * * * * *" << endl;
	cout << "*                     *" << endl;
	cout << "*   Telefon  Rehber   *" << endl;
	cout << "*                     *" << endl;
	cout << "* * * * * * * * * * * *" << endl;
	cout << "*  Rehbere Ekle (1)   *" << endl;
	cout << "*                     *" << endl;
	cout << "*  Rehberden Sil (2)  *" << endl;
	cout << "*                     *" << endl;
	cout << "*  Rehberi Gor (3)    *" << endl;
	cout << "*                     *" << endl;
	cout << "*  Cikis (4)          *" << endl;
	cout << "* * * * * * * * * * * *" << endl;
	int x;
	cin >> x;
	return x;
}

int main()
{
	Rehber rehber;

	while (true)
	{
		switch (Baslangic())
		{
			case 1:
				rehber.RehberEkle();
				break;
			case 2:
				rehber.RehberSil();
				break;
			case 3:
				rehber.RehberGor();
				break;
			case 4:
				return -1;

			default:
				cout << endl <<" Lutfen Tekrar Deneyiniz." << endl;
				break;
		}
	}
	return 0;
}
