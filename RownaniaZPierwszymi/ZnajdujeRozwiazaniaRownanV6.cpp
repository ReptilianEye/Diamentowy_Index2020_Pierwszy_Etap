#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int LicznikRozwiazanSpelniajacychWarunek = 0;

class Hash
{
    int BUCKET; // No. of buckets

    // Pointer to an array containing buckets
    list<ll> *table;

public:
    Hash(int V); // Constructor

    // inserts a key into hash table
    void insertItem(ll x);

    // deletes a key from hash table
    void deleteItem(ll key);

    // hash function to map values to key
    int hashFunction(ll x)
    {
        return (x % BUCKET);
    }

    void displayHash();
    bool contains(ll key);
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<ll>[BUCKET];
}

void Hash::insertItem(ll key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(ll key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (inex)th list
    list<ll>::iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

bool Hash::contains(ll key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (inex)th list
    list<ll>::iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++)
    {
        if (*i == key)
            return true;
    }
    return false;
}

Hash HashQ(2500 * 10);

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
    ll A = TablicaQ[0];
    ll maksymalnaWartosc = TablicaQ[gornyZakres];
    int Bi = 0;
    while (Bi < gornyZakres && A + (TablicaQ[Bi] * 3) <= maksymalnaWartosc)
    {
        ll B = TablicaQ[Bi];
        int Ci = Bi;
        while (Ci < gornyZakres && A + B + (TablicaQ[Ci] * 2 <= maksymalnaWartosc))
        {
            ll C = TablicaQ[Ci];
            int Di = Ci;
            while (Di < gornyZakres && A + B + C + TablicaQ[Di] <= maksymalnaWartosc)
            {

                ll D = TablicaQ[Di];
                ll suma = A + B + C + D;
                if (HashQ.contains(suma))
                {
                    LicznikRozwiazanSpelniajacychWarunek++;
                }
                Di++;
            }
            Ci++;
        }
        Bi++;
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
    if (D == 0)
    {
        cout << 0;
        return 0;
    }
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
        HashQ.insertItem(TablicaQ[i]);
    }
    SprawdzKombinacje(TablicaQ, gornyZakres);
    cout << LicznikRozwiazanSpelniajacychWarunek << endl;
    return 0;
}