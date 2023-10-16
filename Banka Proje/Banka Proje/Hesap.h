#pragma once
#include <iostream>
using namespace std;

class Hesap
{
private:
	string name;
	int id;
	float balance;
public:
	Hesap(string _name, int _id, float _balance);
	void HesabaParaYatir(float amount);
	void HesaptanParaCek(float amount);
	void HesapDetayi();
};