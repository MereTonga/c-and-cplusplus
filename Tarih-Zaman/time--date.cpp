#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	// A yolu
	
	time_t date = time(NULL);
	cout << ctime(&date);
	
	// B yolu
	
	time_t date2 = time(NULL);
	struct tm *dateInfo = localtime(&date2);
	char mDate[50];
	
	cout << asctime(dateInfo);
	
	strftime(mDate,sizeof(mDate),"%d-%m-%Y %H:%M:%S",dateInfo);
	
	cout << mDate;
	
	return 0;
}
