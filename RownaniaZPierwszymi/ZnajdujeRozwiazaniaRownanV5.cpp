#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <chrono>

using namespace std;
int LicznikRozwiazanSpelniajacychWarunek = 0;
int parzysta = 0;

#define ll long long
ll modulo(ll base, ll e, ll mod)
{
    ll a = 1;
    ll b = base;
    while (e > 0)
    {
        if (e % 2 == 1)
            a = (a * b) % mod;
        b = (b * b) % mod;
        e = e / 2;
    }
    return a % mod;
}
bool Fermat(ll m, int iterations)
{
    if (m == 1)
    {
        return false;
    }
    for (int i = 0; i < iterations; i++)
    {
        ll x = rand() % (m - 1) + 1;
        if (modulo(x, m - 1, m) != 1)
        {
            return false;
        }
    }
    return true;
}
bool CzyTaLiczbaJestLiczbaPierwszaOptymalnie(long liczba)
{

    if (liczba < 2)
        return false;
    if (liczba == 2 || liczba == 3)
        return true;
    if (liczba % 3 == 0)
        return false;
    long wielokrotnosc = 6;
    long pierwiastek = sqrt(liczba);
    while (wielokrotnosc - 1 <= pierwiastek)
    {
        if (liczba % (wielokrotnosc + 1) == 0 || liczba % (wielokrotnosc - 1) == 0)
            return false;
        wielokrotnosc = wielokrotnosc + 6;
    }
    return true;
}
bool ZnajdzWZakresieBinarnie(int l, int p, int Tablica[], int poszukiwana)
{
    int sr;
    while (l <= p)
    {
        sr = (l + p) / 2;
        if (Tablica[sr] == poszukiwana)
        {
            return true;
        }
        if (Tablica[sr] > poszukiwana)
            p = sr - 1;
        else
            l = sr + 1;
    }
    return false;
}
void SprawdzKombinacje(int TablicaQ[], int gornyZakres)
{
    
    int A = TablicaQ[0];
    for (int i = 0; i < gornyZakres; i++)
    {
        int maksymalnaWartosc = TablicaQ[i];
        int Bi = 1;
        while (Bi < gornyZakres && A + (TablicaQ[Bi] * 3) <= maksymalnaWartosc)
        {
            int B = TablicaQ[Bi];
            int Ci = Bi;
            while (Ci < gornyZakres && A + B + (TablicaQ[Ci] * 2 <= maksymalnaWartosc))
            {
                int C = TablicaQ[Ci];
                int Di = Ci;
                while (Di < gornyZakres && A + B + C + TablicaQ[Di] <= maksymalnaWartosc)
                {

                    int D = TablicaQ[Di];
                    //cout << "Sprawdzam: " << A << " "
                    //     << " " << B << " " << C << " " << D << endl;

                    if (A + B + C + D == maksymalnaWartosc)
                    {
                        LicznikRozwiazanSpelniajacychWarunek++;
                        // cout << "Znaleziono: " << A << " "
                        //    << " " << B << " " << C << " " << D << endl;
                    }
                    Di++;
                }
                Ci++;
            }
            Bi++;
        }
    }
}
int main()
{
    //********** wczytywanie wejscia
    int gornyZakres;
    int D;
    cin >> gornyZakres >> D;
    //************ Znajdywanie Liczb Pierwszych
    // ********** Wczytywanie tablicy liczb pierwszych
    int liczbaPotrzebnychLiczbPierwszych = gornyZakres + D;
    int TablicaLiczbPierwszych[liczbaPotrzebnychLiczbPierwszych];
    int iloscZnalezionychLiczbPierwszych = 1;
    TablicaLiczbPierwszych[0] = 2;
    int i = 3;
    while (iloscZnalezionychLiczbPierwszych < liczbaPotrzebnychLiczbPierwszych)
    {
        if (Fermat(i, 1))
        {
            if (CzyTaLiczbaJestLiczbaPierwszaOptymalnie(i))
            {
                TablicaLiczbPierwszych[iloscZnalezionychLiczbPierwszych] = i;
                iloscZnalezionychLiczbPierwszych++;
            }
        }
        i = i + 2;
    }
    // ******** Wczytywanie tablicy Q
    int TablicaQ[gornyZakres];
    gornyZakres--;
    for (int i = 0; i <= gornyZakres; i++)
    {
        TablicaQ[i] = TablicaLiczbPierwszych[i] * TablicaLiczbPierwszych[i + D];
    }
    //Sprawdzam dla 3 parzystych
    //  for (int i = 1; i <= gornyZakres; i++)
    //  {
    //      int suma3Parzystych = parzysta * 3 + TablicaQ[i];
    //     for (int j = 3; j < gornyZakres; j++)
    //     {
    //        if (suma3Parzystych == TablicaQ[j])
    //        {
    //           LicznikRozwiazanSpelniajacychWarunek++;
    //          break;
    //     }
    // }
    // }
    auto t1 = std::chrono::high_resolution_clock::now();
    SprawdzKombinacje(TablicaQ, gornyZakres);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << LicznikRozwiazanSpelniajacychWarunek << endl;
    std::cout << duration;

    return 0;
}