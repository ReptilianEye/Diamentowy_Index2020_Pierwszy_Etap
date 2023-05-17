#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

bool CzyLiczbaJestJednokwadratowa(int liczba)
{
    if (liczba == 1)
        return true;
    while (liczba != 1 || liczba != 4)
    {
        int sumaKwadratow = 0;
        while (liczba != 0)
        {
            sumaKwadratow = sumaKwadratow + pow(liczba % 10, 2);
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
int main()
{
    //********** wczytywanie wejscia
    int dolnyZakres;
    int gornyZakres;
    int k;
    cin >> dolnyZakres >> gornyZakres >> k;
    bool *TablicaWielokrotnosciLiczb = new bool[gornyZakres + 1];


    //bool TablicaWielokrotnosciLiczb[gornyZakres+1];
    for (int i = 2; i < gornyZakres; i++)
        TablicaWielokrotnosciLiczb[i] = false;
    TablicaWielokrotnosciLiczb[0] = true;
    TablicaWielokrotnosciLiczb[1] = true;
    long ostatniaDoSprawdzenia = (long)sqrt(gornyZakres); //ostatnia liczbe ktora sprawdzi bedzie pierwiastek z ostatniej liczby w ciagu
    for (long wskaznik = 2; wskaznik <= ostatniaDoSprawdzenia; wskaznik++)
    {
        if (!TablicaWielokrotnosciLiczb[wskaznik]) // czyli liczba pierwsza
        {
            long wielokrotonosc = wskaznik * wskaznik;
            while (wielokrotonosc <= gornyZakres)
            {
                TablicaWielokrotnosciLiczb[wielokrotonosc] = true; //funkcja nadaje wartosc true kazdej wielokrotnosci - czyli liczbie zlozonej (nie-pierwszej)
                wielokrotonosc = wielokrotonosc + wskaznik;        //funkcja zamiast mnozenia liczby dodaje do siebie wartosc pierwszej
            }
        }
    }
    int licznikLiczbSpelniajacychWarunki = 0;
    for (int i = dolnyZakres; i <= gornyZakres; i++)
    {
        if (!TablicaWielokrotnosciLiczb[i] && i != 1)
            if (CzyLiczbaJestJednokwadratowa(i))
            {
                licznikLiczbSpelniajacychWarunki++;
                if (licznikLiczbSpelniajacychWarunki == k)
                {
                    cout << i;
                    break;
                }
            }
    }
    if (licznikLiczbSpelniajacychWarunki < k)
        cout << "-1";

    return 0;
}