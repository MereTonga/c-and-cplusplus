#include <iostream>
using namespace std;

int main()
{
  // Fibonacci Sayýsý Algoritmasý
	
  start:
  
  int oldZ = 1,newZ = 1,z;
  int a;
  cout << "Sayi giriniz : " << endl;
  cin >> a;

  if(a <= 0)
  {
  	cout << "Lutfen gecerli bir deger giriniz." << endl;
  	goto start;
  }
  else if(a == 1)
  {
  	cout << "0\n";
  }
  else if(a == 2)
  {
  	cout << "0\n1\n";
  }
  else if(a > 2)
  {
  	cout << "0\n1\n1\n";
  }
    

  for(int i = 1;i < a-2;i++)
    {
      z = oldZ + newZ;
      cout << z << endl;
      oldZ = newZ;
      newZ = z;
    }
    
    return 0;
}
