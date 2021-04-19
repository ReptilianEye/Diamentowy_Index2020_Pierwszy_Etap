#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

int ListaPoteg[10];

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

bool CzyLiczbaJestJednokwadratowa(int liczba)
{
    if (liczba == 1)
        return true;
    while (liczba != 1 || liczba != 4)
    {
        int sumaKwadratow = 0;
        while (liczba != 0)
        {
            sumaKwadratow = sumaKwadratow + ListaPoteg[liczba % 10];
            liczba = liczba / 10;
        }
        if (sumaKwadratow == 1)
            return true;
        if (sumaKwadratow == 4)
            return false;
        else
            liczba = sumaKwadratow;
    }
    return false;
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
int main()
{
    //********** wczytywanie wejscia
    int dolnyZakres;
    int gornyZakres;
    int k;
    cin >> dolnyZakres >> gornyZakres >> k;
    if (k > (gornyZakres - dolnyZakres))
    {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i <= 9; i++)
        ListaPoteg[i] = i * i;
    int licznikLiczbSpelniajacychWarunki = 0;
    //Zaczac od nieparzystej i co dwa
    if (dolnyZakres % 2 == 0)
        dolnyZakres++;
    for (long i = dolnyZakres; i <= gornyZakres; i = i + 2)
    {
        if (Fermat(i, 1))
            if (CzyLiczbaJestJednokwadratowa(i))
                if (CzyTaLiczbaJestLiczbaPierwszaOptymalnie(i))
                {
                    licznikLiczbSpelniajacychWarunki++;
                    if (licznikLiczbSpelniajacychWarunki == k)
                    {
                        cout << i << endl;
                        break;
                    }
                }
    }
    if (licznikLiczbSpelniajacychWarunki < k)
        cout << "-1";

    return 0;
}