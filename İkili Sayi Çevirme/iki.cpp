#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a,b;
    
    cout << "Ikili sayiyi giriniz : ";
    cin >> a;

    for (int i = 0; 0 < a; a /= 10,i++)
        if (a%10 == 1)
            b += pow(2,i);
    
    cout << b << endl;
}
