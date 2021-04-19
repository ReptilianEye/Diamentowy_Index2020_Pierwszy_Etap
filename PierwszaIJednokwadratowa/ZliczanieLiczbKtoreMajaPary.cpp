#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>        //nie wiem czy jest dopuszczalne


using namespace std;

int ZliczaSumeLiczbPoObcieciu(int tablicaLiczb[], int wielkoscTablicy, int k)
{
    int liczbaElementowZPara = 0;
    for(int i = 0; i < wielkoscTablicy; i++)
    {
        int dolnyZakres = tablicaLiczb[i]-k;
        int gornyZakres = tablicaLiczb[i]+k;
        for(int j = 0; j < wielkoscTablicy; j++)
        {
            if(tablicaLiczb[j] <= gornyZakres && tablicaLiczb[j] >= dolnyZakres && tablicaLiczb[j] != tablicaLiczb[i])
            {
                liczbaElementowZPara++;
                break;
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
    int *tablicaLiczb = new int [wielkoscTablicy];
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        cin >> tablicaLiczb[i];
    }
    int iloscLiczbKtoreMajaPare = ZliczaSumeLiczbPoObcieciu(tablicaLiczb, wielkoscTablicy, k);
    cout << iloscLiczbKtoreMajaPare;
    return 0;
}