#include <iostream>
using namespace std;

// kucukten buyuge siralanmis bir dizide verilen sayinin hangi indexte yer alacagini soyler

int Control(int a,int b[5])
{
	for(int i = 0;i < 5;i++)
	{
		if(a == b[i])
		{
			cout << b[i] << " Degeri " << i << ". Indextedir." << endl;
			goto run;
		}
	}
	return 0;
	
	run:	
		return 1;
}


int main()
{
	int x,nums[5] = {1,2,6,9,11};
	cout << "Sayiyi Giriniz : ";
	cin >> x;
	
	if(!(Control(x,nums)))
	{
		for(int i = 0;i < 5;i++)
		{
			if(x < nums[i])
			{
				cout << x << " Degeri " << i << ". Indextedir." << endl;
				break;
			}
			else if(x > nums[i] && i == 4)
			{
				cout << x << " Degeri " << i+1 << ". Indextedir." << endl;
			}
		}
	}
}
