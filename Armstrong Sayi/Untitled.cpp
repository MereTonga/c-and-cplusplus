#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   // Armstrong Sayý
   
   int x,oldX,sum = 0;
   cout << "Sayiyi Giriniz : ";
   cin >> x;
   oldX = x;
   
   for(;x > 0;x/=10)
   		sum += pow(x%10,3);
   
   if(sum == oldX)
   	 cout << oldX << " Sayisi Armstrong Sayidir.";
   else
   	cout << oldX << " Sayisi Armstrong Sayi Degildir.";
   	
   	return 0;
}
