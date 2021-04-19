#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int LicznikRozwiazanSpelniajacychWarunek = 0;

void CombinationRepetitionUtil(int chosen[], int TablicaQ[], int index, int r, int start, int gornyZakres)
{
    if (index == r)
    {
        int suma = 0;
        string kombiancja = "";
        for (int i = 0; i < r; i++)
        {
            suma = suma + TablicaQ[chosen[i]];
            kombiancja = kombiancja + " " + to_string(TablicaQ[chosen[i]]);
        }
        for (int i = gornyZakres; i >= 0; i--)
        {
            if (suma > TablicaQ[i])
                break;
            if(suma == TablicaQ[i])
            {
                //cout << suma << endl;
                LicznikRozwiazanSpelniajacychWarunek++;
                cout << kombiancja << " daja winik: "<<TablicaQ[i];
                 cout << endl;
                break;
            }
        }
        return;
    }
    for (int i = start; i <= gornyZakres; i++)
    {
        chosen[index] = i;
        CombinationRepetitionUtil(chosen, TablicaQ, index + 1, r, i, gornyZakres);
    }
    return;
}

void CombinationRepetition(int TablicaQ[], int gornyZakres, int r)
{
    int *chosen = new int[r + 1];

    CombinationRepetitionUtil(chosen, TablicaQ, 0, r, 0, gornyZakres - 1);
}

int main()
{
    //********** wczytywanie wejscia
    int gornyZakres;
    int D;
    cin >> gornyZakres >> D;
    //bool *TablicaLiczb = new bool[gornyZakres];
    //************ Znajdywanie Liczb Pierwszych
    int gornyZakresDlaGenerowaniaPierwszych = 100000;    //dobrac lepsza granice aby bylo 5 tysiecy liczb pierwszych (70,000)
    bool ListaBooliNaPierwszosc[gornyZakresDlaGenerowaniaPierwszych];
    for (int i = 0; i < gornyZakres; i++)
        ListaBooliNaPierwszosc[i] = false;
    long ostatniaDoSprawdzenia = (long)sqrt(gornyZakresDlaGenerowaniaPierwszych);
    for (long wskaznik = 2; wskaznik <= ostatniaDoSprawdzenia; wskaznik++)
    {
        if (!ListaBooliNaPierwszosc[wskaznik])
        {
            long wielokrotonosc = wskaznik * wskaznik;
            while (wielokrotonosc <= gornyZakresDlaGenerowaniaPierwszych)
            {
                ListaBooliNaPierwszosc[wielokrotonosc] = true;
                wielokrotonosc = wielokrotonosc + wskaznik;
            }
        }
    }
    // ********** Wczytywanie tablicy liczb pierwszych
    int TablicaLiczbPierwszych[gornyZakres + D];
    int pozycjaLiczbyPierwszej = 0;
    for (int i = 2; i <= gornyZakresDlaGenerowaniaPierwszych; i++)
    {
        if (pozycjaLiczbyPierwszej == (gornyZakres + D))
            break;
        if (!ListaBooliNaPierwszosc[i])
        {
            TablicaLiczbPierwszych[pozycjaLiczbyPierwszej] = i;
            pozycjaLiczbyPierwszej++;
        }
    }
    // ******** Wczytywanie tablicy Q
    int TablicaQ[gornyZakres];
    for (int i = 0; i < gornyZakres; i++)
    {
        TablicaQ[i] = TablicaLiczbPierwszych[i] * TablicaLiczbPierwszych[i + D];
         cout << TablicaQ[i] <<endl;
    }
    CombinationRepetition(TablicaQ, gornyZakres, 4);
    cout << LicznikRozwiazanSpelniajacychWarunek;
    return 0;
}