#include <iostream>
using namespace std;

int main()
{
	// dizide bulunan ayni elemanlari 0'a esitler
	int dizi[10] = {1,1,1,3,3,5,5,5,6,7};
	
	for(int i = 0;i < 10;i++)
		for(int j = 0;j < 10;j++)
			if(dizi[i] == dizi[j] && i != j && dizi[i] != 0 && dizi[j] != 0)
				dizi[j] = 0;
	
	for(int i = 0;i < 10;i++)
		if(dizi[i] != 0)
			cout << dizi[i] << "   ";
}
