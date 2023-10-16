#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ikili sayi sisteminde toplama

int DecimalToBinary(string a)
{
	int x = 0;
	for(int i = a.length()-1,j = 0;i >= 0;i--,j++)
		if(a[i] == '1')
			x += pow(2,j);		
	return x;
}

string Reverse(string a)
{
	string x = "";
	for(int i = a.length()-1;i >= 0;i--)
		x += a[i];
	return x;
}

string BinaryToDecimal(int a)
{
	string x;
	for(int i = a;i >= 1;i/=2)
		x.append(to_string(i%2));
	return Reverse(x);
}

int main()
{
	string x,y;
	cout << "Sayilari Giriniz : ";
	cin >> x >> y;
	cout << x << " + " << y << " = " << BinaryToDecimal(DecimalToBinary(x)+DecimalToBinary(y));
}