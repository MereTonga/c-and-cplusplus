#include <iostream>
using namespace std;

int main()
{
	// Kullanicinin girdigi sayiya kadar olan asal sayilar
	
	int x;
	cin >> x;
	
	for(int i = 1;i <= x;i++)
	{
		int a = 0;
		
		for(int j = 1;j < i;j++)
		{
			if(i % j == 0)
				a++;
			if(a > 1)
				break;
		}
			
				
		if(a == 1 || i == 2)
			cout << i << endl;
	}
}
