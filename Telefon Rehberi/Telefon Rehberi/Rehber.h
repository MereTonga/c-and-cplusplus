#pragma once
#include <iostream>
#include <list>
using namespace std;

class Rehber
{
private:
	list<string> isimListe;
	list<string> telNoListe;

public:
	void RehberEkle();
	void RehberSil();
	void RehberGor();
};