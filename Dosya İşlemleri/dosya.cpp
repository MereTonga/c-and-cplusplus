#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  // Dosya oluþturma
  
  ofstream createFile("Metin.txt");
  
  if(createFile.is_open()) // dosya var mý ve açýlabilir mi
  {
  	createFile << "Selam" << endl << "Mert Yýldýz";
    createFile.close();
  }
  
  // Dosya okuma
  
  ifstream readFile("Metin.txt");
  
  string inFile = "";
  
  if(readFile.is_open()) // dosya var mý ve açýlabilir mi
  {
   	while(getline(readFile,inFile)) // dosyadaki satýrlarý okur
   	{
   		cout << inFile << endl; // Dosya'nýn içini inFile deðiþkenine atama 	  		
	}
	
	readFile.close();
  }	
  
  // Dosyayý karakter karakter okuma
  
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
  
  // Dosyayý silme
  
  int x;
  
  cin >> x;
  
  if(x == 1)
  	{
  		cout << "Dosya Silindi.";
		remove("Metin.txt");  		
	}
  
  return 0;
}





