#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	// 2.Dereceden 1 Bilinmeyenli Denklem
	
	float a,b,c,det,x1,x2;
	cout << " ax'2 + bx + c = 0 denkleminin degerlerini giriniz." << endl << " a,b ve c degeri : ";
	cin >> a >> b >> c;
	cout << endl;
	
	det = (b*b)-(4*a*c);
	if(det >= 0)
	{
		x1 = ((-b)-(sqrt(det)))/(a+a);
		x2 = ((-b)+(sqrt(det)))/(a+a);
		cout << a << "x'2 + " << b << "x + " << c << " = 0 denkleminin kokleri;" << endl;
		cout << " x1 = " << x1 << endl;
		cout << " x2 = " << x2 << endl;
	}
	else
		cout << a << "x'2 + " << b << "x + " << c << " = 0 denkleminin reel koku yoktur.(determinant < 0)";
}
