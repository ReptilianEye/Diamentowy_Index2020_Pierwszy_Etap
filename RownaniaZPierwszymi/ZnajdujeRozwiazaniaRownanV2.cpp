#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;
string ostatniaKombinacjaDajacaWynik = ""; //usunac
string kompilacja = "";                    //usunac
bool CzyNajwiekszaKombinacja = false;
int LicznikRozwiazanSpelniajacychWarunek = 0;
int parzysta = 0;
bool CzyPierwszyPominiety = false;
int bezowocna = 0;

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
void CombinationRepetitionUtil(int chosen[], int TablicaQ[], int index, int r, int start, int gornyZakres, bool CzyPierwszyRaz)
{
    if (index == r)
    {
        kompilacja = "";
        int suma = parzysta;
        for (int i = 0; i < r; i++)
        {
            suma = suma + TablicaQ[chosen[i]];
            kompilacja = kompilacja + " " + to_string(TablicaQ[chosen[i]]); //usunac
        }
        if (suma > TablicaQ[gornyZakres])
        {
            CzyNajwiekszaKombinacja = true;
            return;
        }
        if (suma % 2 == 0)
            return;
        int l = 0;
        int p = gornyZakres;
        int sr;
        while (l <= p)
        {
            sr = (l + p) / 2;
            if (TablicaQ[sr] == suma)
            {
                LicznikRozwiazanSpelniajacychWarunek++;
                ostatniaKombinacjaDajacaWynik = kompilacja; //usunac
                cout << bezowocna << endl;
                bezowocna = 0;
                break;
            }
            if (TablicaQ[sr] > suma)
                p = sr - 1;
            else
                l = sr + 1;
        }
        bezowocna++;
        return;
    }
    for (int i = start; i <= gornyZakres; i++)
    {
        if (CzyNajwiekszaKombinacja)
            break;
        chosen[index] = i;
        if (index == 0 && TablicaQ[chosen[index]] * 3 > TablicaQ[gornyZakres] - parzysta)
        {
            return;
        }
        CombinationRepetitionUtil(chosen, TablicaQ, index + 1, r, i, gornyZakres, false);
    }
    return;
}
void CombinationRepetition(int TablicaQ[], int gornyZakres, int r)
{
    int *chosen = new int[r + 1];

    CombinationRepetitionUtil(chosen, TablicaQ, 0, r, 0, gornyZakres - 1, true);
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
    gornyZakres--;
    int TablicaQ[gornyZakres];
    for (int i = 1; i <= gornyZakres; i++)
    {
        TablicaQ[i - 1] = TablicaLiczbPierwszych[i] * TablicaLiczbPierwszych[i + D];
    }
    parzysta = TablicaLiczbPierwszych[0] * TablicaLiczbPierwszych[0 + D];
    //Sprawdzam dla 3 parzystych
    for (int i = 1; i <= gornyZakres; i++)
    {
        int suma3Parzystych = parzysta * 3 + TablicaQ[i];
        for (int j = 3; j < gornyZakres; j++)
        {
            if (suma3Parzystych == TablicaQ[j])
            {
                LicznikRozwiazanSpelniajacychWarunek++;
                break;
            }
        }
    }
    CombinationRepetition(TablicaQ, gornyZakres, 3);
    cout << LicznikRozwiazanSpelniajacychWarunek << endl;
    cout << ostatniaKombinacjaDajacaWynik << " ostatania kombiancja dajaca wynik" << endl; //usunac
    cout << kompilacja << " ostatnia sprwadzana kompilacja" << endl;
    cout << bezowocna;
    return 0;
}