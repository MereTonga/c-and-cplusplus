#include <iostream>
using namespace std;

int main()
{
	// 1.Dereceden 2 Bilinmeyenli Denklem
	
	float a,b,c,k,l,m,x,y;
	cout << "1.denklem ax + by = c icin degerlerinizi giriniz." << endl << "a,b ve c degeri : ";
	cin >> a >> b >> c;
	cout << "2.denklem kx + ly = m icin degerlerinizi giriniz." << endl << "k,l ve m degeri : ";
	cin >> k >> l >> m;
	
	x = ((l*c) - (b*m)) / ((l*a) - (b*k));
	y = ((k*c) - (a*m)) / ((k*b) - (a*l));
	cout << "Girilen degerler sonucu;" << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y;
	return 0;
}
