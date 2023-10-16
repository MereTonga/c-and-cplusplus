#include <iostream>
using namespace std;

int main() {
    int matris1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matris2[3][3] = { {10, 11, 12}, {13, 14, 15}, {16, 17, 18} };
    int sonuc[3][3] = {0};

    //Matris çarpýmý iþlemi
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++) 
            for(int k=0; k<3; k++) 
                sonuc[i][j] += matris1[i][k] * matris2[k][j];

    //Sonuç matrisini yazdýrma
    cout << "Matris Carpimi:" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            cout << sonuc[i][j] << " ";
        cout << endl;
    }

    return 0;
}
