#include <iostream>
#include <fstream>
using namespace std;

struct Car
{
	char color[10];
	char model[10];
	float price;
};


int main()
{
	ofstream carsFile("Cars Features.txt");
	
	Car x[3];
	
	for(int i = 0;i < 3;i++)
	{
		cout << i+1 <<". Arabanizin rengini giriniz : " << endl;
		cin >> x[i].color;
		cout << i+1 <<". Arabanizin modelini giriniz : " << endl;
		cin >> x[i].model;
		cout << i+1 <<". Arabanizin fiyatini giriniz : " << endl;
		cin >> x[i].price;
	}
	
	for(int i = 0;i < 3;i++)
	{
		carsFile << i+1 << ". Arabanizin rengi = " << x[i].color << endl;
		carsFile << i+1 << ". Arabanizin modeli = " << x[i].model << endl;
		carsFile << i+1 << ". Arabanizin fiyati = " << x[i].price << endl << endl;
	}

	carsFile.close();
}
