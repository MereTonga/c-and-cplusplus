#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int RastgeleSec()
{
	int rastSayi;
    rastSayi = rand() % 3;
    return rastSayi;
}

int main()
{
    srand(time(0));
    int secim;
    
    while(true)
    {
    	cout << endl << " Cikis (4)" << endl;
    	cout << " Tas (1),Kagit (2),Makas (3) Seciniz : ";
    	cin >> secim;
    	cout << endl;
    	
    	if(secim == 4)
    		return -1;
    	else if(secim > 4 || secim < 1)
    		cout << " Hatali Secim Yaptiniz Tekrar Deneyiniz." << endl;
    	
    	
    	switch(RastgeleSec())
    	{
    		case 0:
    			if(secim == 1)
    				cout << " Bilgisayarin Secimi = Tas\n Kullanici Secimi = Tas\n Sonuc = Berabere !" << endl;  
				else if(secim == 2)
					cout << " Bilgisayarin Secimi = Tas\n Kullanici Secimi = Kagit\n Sonuc = Kullanici Kazandi !" << endl;
				else if(secim == 3)
					cout << " Bilgisayarin Secimi = Tas\n Kullanici Secimi = Makas\n Sonuc = Bilgisayar Kazandi !" << endl;
				break;
				
			case 1:
    			if(secim == 1)
    				cout << " Bilgisayarin Secimi = Kagit\n Kullanici Secimi = Tas\n Sonuc = Bilgisayar Kazandi !" << endl;  
				else if(secim == 2)
					cout << " Bilgisayarin Secimi = Kagit\n Kullanici Secimi = Kagit\n Sonuc = Berabere !" << endl;
				else if(secim == 3)
					cout << " Bilgisayarin Secimi = Kagit\n Kullanici Secimi = Makas\n Sonuc = Kullanici Kazandi !" << endl;
				break;
				
			case 2:
    			if(secim == 1)
    				cout << " Bilgisayarin Secimi = Makas\n Kullanici Secimi = Tas\n Sonuc = Kullanici Kazandi !" << endl;  
				else if(secim == 2)
					cout << " Bilgisayarin Secimi = Makas\n Kullanici Secimi = Kagit\n Sonuc = Bilgisayar Kazandi !" << endl;
				else if(secim == 3)
					cout << " Bilgisayarin Secimi = Makas\n Kullanici Secimi = Makas\n Sonuc = Berabere !" << endl;
				break;
		}
	}
	
    return 0;
}
