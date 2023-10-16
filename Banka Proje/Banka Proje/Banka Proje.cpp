#include <iostream>
#include "Hesap.h"
using namespace std;

int main()
{
    Hesap hsp1("Ali Gungor", 7685, 250.75);
    hsp1.HesabaParaYatir(200);
    hsp1.HesaptanParaCek(100);
    hsp1.HesapDetayi();

    Hesap hsp2("Berna Ozan", 7686, 0);
    hsp2.HesaptanParaCek(100);
    hsp2.HesapDetayi();


    return 0;
}
