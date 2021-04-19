#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;

typedef unsigned long long int uilong;

//Dana jest liczba całkowita n. Proszę napisać program, który wylicza ostatnią niezerową cyfrę liczby n!.

//Wejscie
//W pierwszym i jedynym wierszu standardowego wejścia znajduje się jedna liczba całkowita n (0 ≤ n < 10^10).

//Wyjscie
//W pierwszym i jedynym wierszu standardowego wyjścia program powinien wypisać jedną cyfrę będącą rozwiązaniem.
uilong WczytajWejscie()
{
    uilong liczba;
    cin >> liczba;
    return liczba;
}
uilong ZwracaOstatnieCyfrySilniBezZer(uilong liczba)
{
    uilong wynik = 1;
    for (uilong i = 1; i <= liczba; i++)
    {
        uilong j = i;
        while (j % 10 == 0)
            j = j / 10;
        wynik = wynik * j;
        while (wynik % 10 == 0)
            wynik = wynik / 10;
        if (wynik > 100000000)
            wynik = wynik % 100000000;
    }
    return wynik;
}
int ZwracaOstaniaNiezerowaCyfreSilni(uilong liczba)
{
    return (int)liczba % 10;
}
void WypiszWyjscie(uilong wynik)
{
    cout << wynik;
}
void WykonajZadanie()
{
    uilong liczba = WczytajWejscie();
    uilong silnia = ZwracaOstatnieCyfrySilniBezZer(liczba);
    int wynik = ZwracaOstaniaNiezerowaCyfreSilni(silnia);
    WypiszWyjscie(wynik);
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    WykonajZadanie();
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
//    cout << endl;
//    cout << duration;
//    cin >> duration;
    return 0;
}
