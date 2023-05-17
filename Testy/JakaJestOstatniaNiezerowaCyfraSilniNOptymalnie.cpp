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
int ZwracaOstatniaCyfreSilniBezZer(uilong liczba)
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
    return (int)wynik % 10;
}
int ZwracaOstatniaCyfreSilniBezZerOptymalnie(long liczba)
{
    int wynik = 1;
    for (long i = 1; i <= liczba; i++)
    {
        long j = i;
        while (j % 10 == 0)
            j = j / 10;
        j = j % 1000;
        wynik = wynik * j;
        while (wynik % 10 == 0)
            wynik = wynik / 10;
        wynik = wynik % 1000;
        
    }
    return (int)wynik % 10;
}

int main()
{
    for (long i = 1; i <= 1000; i++)
    {
        int wynik1 = ZwracaOstatniaCyfreSilniBezZer(i);
        int wynik2 = ZwracaOstatniaCyfreSilniBezZerOptymalnie(i);
        if ( wynik1 != wynik2 )
            cout << "Nie zgadza sie " << i << " " << wynik1 << " " << wynik2 <<endl;
        else
            cout << "Zgadza sie " << i << endl;
    }
    cin.get();
    return 0;
}
