#include <iostream>
using namespace std;

int main()
{
  // M�kemmel Say�
  
  int x,toplam = 0;
  cout << "Sayiyi giriniz : ";
  cin >> x;

  for(int i = 1;i <= x;i++)
      if(x % i == 0)
        toplam += i;

  if(toplam == x + x)
    cout << x << " Sayisi Mukemmel Sayidir.";
  else
    cout << x << " Sayisi Mukemmel Sayi Degildir.";
    
    return 0;
}
