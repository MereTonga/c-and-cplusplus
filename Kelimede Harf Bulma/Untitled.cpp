#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char kelime[25];
	cout << "Kelimenizi giriniz : ";
	cin >> kelime;
	
	int x[26];
	fill(begin(x),end(x),0);  // x'in bütün degerlerini 0'a esitler

	for(int i = 0;kelime[i] != NULL;i++)
	{
		int yer;

		if(kelime[i] >= 'a')
			yer = kelime[i] - 'a';
		else
			yer = kelime[i] - 'A';
		
		x[yer]++;
 	}

	for(int i = 0;i < 26;i++)
		if(x[i] != 0)
			cout << char(i+65) << " harfinden " << x[i] << " tane vardir." << endl;
			
	return 0;
}
