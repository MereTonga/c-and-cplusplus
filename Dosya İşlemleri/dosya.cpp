#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  // Dosya olu�turma
  
  ofstream createFile("Metin.txt");
  
  if(createFile.is_open()) // dosya var m� ve a��labilir mi
  {
  	createFile << "Selam" << endl << "Mert Y�ld�z";
    createFile.close();
  }
  
  // Dosya okuma
  
  ifstream readFile("Metin.txt");
  
  string inFile = "";
  
  if(readFile.is_open()) // dosya var m� ve a��labilir mi
  {
   	while(getline(readFile,inFile)) // dosyadaki sat�rlar� okur
   	{
   		cout << inFile << endl; // Dosya'n�n i�ini inFile de�i�kenine atama 	  		
	}
	
	readFile.close();
  }	
  
  // Dosyay� karakter karakter okuma
  
  ifstream readFile2("Metin.txt");
  
  char inFile2;
  
  if(readFile2.is_open())
  {
  	while(readFile2.get(inFile2))
  	{
  		cout << inFile2 << endl;
	}
  	readFile2.close();
  }
  
  // Dosyay� silme
  
  int x;
  
  cin >> x;
  
  if(x == 1)
  	{
  		cout << "Dosya Silindi.";
		remove("Metin.txt");  		
	}
  
  return 0;
}





