#include <iostream>
#include <string>
using namespace std;

int FirstRule(int tc[11])
{
	int sum = 0;
	
	for(int i = 0;i < 10;i++)
		sum += tc[i];
		
	if(sum % 10 == tc[10])
		return 1;
	else
		return 0;
}

int SecondRule(int tc[11])
{
	int sumO = 0,sumE = 0;
	
	for(int i = 0;i < 9;i+=2)
		sumO += tc[i];
		
	for(int i = 1;i < 9;i+=2)
		sumE += tc[i];
		
	if( ((sumO * 7)+(sumE*9)) % 10 == tc[9] )
		return 1;
	else
		return 0;
}

int ThirdRule(int tc[11])
{
	int sum = 0;
	
	for(int i = 0;i < 9;i+=2)
		sum += tc[i];
		
	if( (sum*8) % 10 == tc[10] )
		return 1;
	else
		return 0;
}

int main()
{
	string strTC;
	int intTC[11];
	again:
	cout << "TC Kimlik No Giriniz : ";
	
	cin >> strTC;
	
	for(int i = 0;i < 11;i++)
		intTC[i] = strTC[i] - 48;
	
	if( (FirstRule(intTC) + SecondRule(intTC) + ThirdRule(intTC)) == 3 )
		cout << "Girdiginiz TC Kimlik No Dogrudur.";
	else
	{
		cout << "Girdiginiz TC Kimlik No Yanlistir." << endl << "Tekrar Deneyiniz." << endl << endl;
		goto again;
	}
	
	return 0;
}
