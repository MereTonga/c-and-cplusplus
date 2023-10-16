#include <iostream>
using namespace std;

void Control(char x);

int main()
{
	char a;
	cin >> a;
	
	Control(a);
}

void Control(char x)
{
	if(x >= 'A' && x <= 'Z' )
		x += 32;
	else if(x >= 'a' && x <= 'z')
		x -= 32;
		
	cout << x;
}
