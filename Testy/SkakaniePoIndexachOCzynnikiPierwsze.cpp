#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;

int minimalnaIloscSkokow = -1;

void JakaJestNajmniejszaIloscSkokowAbyPrzejscPoTablicy(int wielkoscTablicy,
                                                       int pozycjaPionka, int liczbaSkokow, int** TablicaCzynnikowLiczb)
{
    if (pozycjaPionka == wielkoscTablicy - 1)
    {
        if (minimalnaIloscSkokow > liczbaSkokow || minimalnaIloscSkokow == -1)
            minimalnaIloscSkokow = liczbaSkokow;
        return;
    }
    for (int i = 0; i < 100; i++)
    {
        if (TablicaCzynnikowLiczb[pozycjaPionka][i] == 1)
            break;
        if (pozycjaPionka + TablicaCzynnikowLiczb[pozycjaPionka][i] <= wielkoscTablicy - 1)
        {
            return JakaJestNajmniejszaIloscSkokowAbyPrzejscPoTablicy(wielkoscTablicy,
                                                                     pozycjaPionka + TablicaCzynnikowLiczb[pozycjaPionka][i],
                                                                     liczbaSkokow + 1, TablicaCzynnikowLiczb);
        }
    }
    return;
}

int main()
{
    // *********** Wczytanie wejscia

    int wielkoscTablicy;
    cin >> wielkoscTablicy;
    int *TablicaLiczb = new int[wielkoscTablicy];
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        cin >> TablicaLiczb[i];
    }
    // *********** przygotowanie danych
    int **TablicaCzynnikowLiczb = new int *[wielkoscTablicy];
    for (int i = 0; i < wielkoscTablicy; i++)
        TablicaCzynnikowLiczb[i] = new int[100];
    int czynnik = 2;
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        int rozkladanaLiczba = TablicaLiczb[i];
        int j = 0;
        while (czynnik <= rozkladanaLiczba)
        {

            if (rozkladanaLiczba % czynnik == 0)
            {
                TablicaCzynnikowLiczb[i][j] = czynnik;
                rozkladanaLiczba = rozkladanaLiczba / czynnik;
                j++;
                czynnik = 2;
            }
            else
                czynnik++;
        }
        for (int k = j; k < 100; k++)
            TablicaCzynnikowLiczb[i][k] = 1;
    }
    // ******** wywolanie obliczen
    JakaJestNajmniejszaIloscSkokowAbyPrzejscPoTablicy(wielkoscTablicy, 0, 0, TablicaCzynnikowLiczb);
    cout << minimalnaIloscSkokow;

    return 0;
}
