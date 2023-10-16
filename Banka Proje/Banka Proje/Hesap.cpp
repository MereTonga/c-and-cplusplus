#include "Hesap.h"

Hesap::Hesap(string _name, int _id, float _balance)
{
	name = _name;
	id = _id;
	balance = _balance;
}

void Hesap::HesabaParaYatir(float amount)
{
	balance += amount;
	cout << "Hesabiniza " << amount << "TL para girisi yapilmistir." << endl;
	cout << "Guncel Bakiye : " << balance << "TL" << endl << endl;
}

void Hesap::HesaptanParaCek(float amount)
{
	if (balance-amount >= 0)
	{
		balance -= amount;
		cout << "Hesabinizdan " << amount << "TL para cekilmistir." << endl;
		cout << "Guncel Bakiye : " << balance << "TL" << endl << endl;
	}
	else
	{
		cout << "Hesabinizda " << amount << "TL bulunmamaktadir." << endl;
		cout << "Bakiye : " << balance << "TL" << endl << endl;
	}
}

void Hesap::HesapDetayi()
{
	cout <<"Hesap Sahibi : " << name << endl;
	cout << "ID : " << id << endl;
	cout << "Bakiye : " << balance << endl << endl;
}