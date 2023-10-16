#include <iostream>
#include <fstream> // dosya i�lemleri
#include <conio.h> // getch() fonksiyonunu bar�nd�r�r
#include <windows.h> // Point ve GetCursorPos i�in
#include <unistd.h> // sleep() i�in

using namespace std;

int main() 
{
	ofstream dataInput("Data Input.txt");
	
    char c;
    
    while(c != 'x' && c != 'X')
    {
    	c = getch(); // Kullan�c�n�n tu�a basmas�n� bekler
    	dataInput << "Basilan tus : " << c  << endl << "ASCII KODU : " << int(c) << endl; // Bas�lan tu�lar� dosyaya yazar
    	POINT p; // POINT struct'�, x ve y koordinatlar�n� i�erir
    	GetCursorPos(&p); // Mouse pozisyonunu al�r
    	dataInput << "Mouse Posizyonu : (" << p.x << "," << p.y << ")" << endl;
    	//sleep(1); // 1 saniye 1 �al��mas�n� sa�lar
	}
    
    dataInput.close();
    
    SetCursorPos(0,0); // Mouse Pozisyonunu 0,0'a �eker
    
    return 0;
}
