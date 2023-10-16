#include <iostream>
using namespace std;

int main()
{
	int m,n;
	cout << "Matrisinizin satir ve sutun sayisini giriniz (Ornek = 2 3) : ";
	cin >> m >> n;
	
	int x[m][n];
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cout << "[" << i+1 << "]" << "[" << j+1 << "]" << ". degeri giriniz : ";
			cin >> x[i][j];
		}
	}
	
	system("cls");
	
	cout << "Matrisiniz : " << endl;
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl << "Matrisinizin transpozu : " << endl;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cout << x[j][i] << " ";
		}
		cout << endl;
	}
}
