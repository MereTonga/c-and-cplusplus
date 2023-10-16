#include <iostream>
#include <fstream> // dosya iþlemleri
#include <conio.h> // getch() fonksiyonunu barýndýrýr
#include <windows.h> // Point ve GetCursorPos için
#include <unistd.h> // sleep() için

using namespace std;

int main() 
{
	ofstream dataInput("Data Input.txt");
	
    char c;
    
    while(c != 'x' && c != 'X')
    {
    	c = getch(); // Kullanýcýnýn tuþa basmasýný bekler
    	dataInput << "Basilan tus : " << c  << endl << "ASCII KODU : " << int(c) << endl; // Basýlan tuþlarý dosyaya yazar
    	POINT p; // POINT struct'ý, x ve y koordinatlarýný içerir
    	GetCursorPos(&p); // Mouse pozisyonunu alýr
    	dataInput << "Mouse Posizyonu : (" << p.x << "," << p.y << ")" << endl;
    	//sleep(1); // 1 saniye 1 çalýþmasýný saðlar
	}
    
    dataInput.close();
    
    SetCursorPos(0,0); // Mouse Pozisyonunu 0,0'a çeker
    
    return 0;
}
