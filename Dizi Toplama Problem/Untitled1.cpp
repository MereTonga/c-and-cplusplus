#include <iostream>
using namespace std;

int main()
{
	// dizi belirlenir ve sayi verilir verilen sayiyi dizideki sayilarla elde edilebilir mi
	int x, y;
	
	cout << "Kac Sayi Giricen : " << endl;
	cin >> x;
	
	int nums[x];
	
	cout << "Sayilari Giriniz" << endl; 
	
	for(int i = 0;i < x;i++)
	{
		cout << i+1 << ". Sayiyi Giriniz : ";
		cin >> nums[i];
	}
	
	cout << "Istediğin Sayiyi Gir" << endl;
	cin >> y;
	
	
	
	for(int i = 0;i < x;i++)
	{
		for(int j = 0;j < x;j++)
		{
			if(nums[i] + nums[j] == y && i != j)
			{
				cout << nums[i] << " + " << nums[j] << " = " << y;
				goto buldu;
			}
		}
	}
	
	buldu:
		return 0;
}
