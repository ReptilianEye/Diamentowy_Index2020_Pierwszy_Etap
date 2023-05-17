#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int ZliczaIloscLiczbKtoreMajaPary(int tablicaLiczb[], int wielkoscTablicy, int k)
{
    int liczbaElementowZPara = 0;
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        int dolnyZakres = tablicaLiczb[i] - k;
        int gornyZakres = tablicaLiczb[i] + k;
        {
            int j = i - 1;
            while (j >= 0 && (tablicaLiczb[i] == tablicaLiczb[j]))
            {
                j--;
            }
            if (tablicaLiczb[j] <= gornyZakres && tablicaLiczb[j] >= dolnyZakres)
            {
                liczbaElementowZPara++;
                continue;
            }
            j = i + 1;
            while (j < wielkoscTablicy && tablicaLiczb[i] == tablicaLiczb[j])
            {
                j++;
            }
            if (tablicaLiczb[j] <= gornyZakres && tablicaLiczb[j] >= dolnyZakres)
            {
                liczbaElementowZPara++;
                continue;
            }
        }
    }
    return liczbaElementowZPara;
}
int main()
{
    //********** wczytywanie wejscia
    int wielkoscTablicy;
    int k;
    cin >> wielkoscTablicy >> k;
    if (wielkoscTablicy == 1)
    {
        cout << 0;
        return 0;
    }
    int *tablicaLiczb = new int[wielkoscTablicy];
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        cin >> tablicaLiczb[i];
    }
    sort(tablicaLiczb, tablicaLiczb + wielkoscTablicy);
    int iloscLiczbKtoreMajaPare = ZliczaIloscLiczbKtoreMajaPary(tablicaLiczb, wielkoscTablicy, k);
    cout << iloscLiczbKtoreMajaPare;
    return 0;
}