#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// girilen rakamlari birlestirir ve 1 arttirir 
	int n,x = 0; cout << "Kac tane rakam gireceksin : ";
	cin >> n;
	
	int nums[n];
	for(int i = 0;i < n;i++)
		cin >> nums[i];
	
	for(int i = 0;i < n;i++)
		x += nums[i] * (pow(10,n-i-1));
	
	cout << ++x;
}
