#include <iostream>

int main()
{
	// En büyük bulma
	
	int x[5];
	int a;
	
	std::cout << "Bes sayi giriniz : \n";
	
	for (int i = 0; i < 5; i++)
		std::cin >> x[i];
		
	a = x[0];
	
	for (int i = 0; i < 5; i++)
		if (!(a >= x[i]))
			a = x[i];
			
	std::cout << "En buyuk sayi : " << a;
	
}
