#include <iostream>
#include <string>
using namespace std;

int main()
{
	string x = "ececece";
	int a = 0;
	
	for(int i = 0;i < x.length();i++)
		if(x[i] == ' ')
			x[i] = '/n';
			
	for(int i = 0;i < x.length()/2;i++)
		if(x[i] == x[x.length()-i-1])
			a++;
	
	if(a == x.length()/2)
		cout << "dogru";
}
