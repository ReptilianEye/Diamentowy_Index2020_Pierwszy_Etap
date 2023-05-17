#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int ZliczaSumeLiczbPoObcieciu(int tablicaLiczb[], int wielkoscTablicy, int liczbaOperacji)
{
    for (int i = 0; i < liczbaOperacji; i++)
    {
        int pozycjaNajwiekszejWartosci = 0;
        for (int j = 1; j < wielkoscTablicy; j++)
        {
            if (tablicaLiczb[j] > tablicaLiczb[pozycjaNajwiekszejWartosci])
                pozycjaNajwiekszejWartosci = j;
        }
        tablicaLiczb[pozycjaNajwiekszejWartosci] = float(tablicaLiczb[pozycjaNajwiekszejWartosci] / 2);
    }
    int sumaElementowTablicy = 0;
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        sumaElementowTablicy = sumaElementowTablicy + tablicaLiczb[i];
    }
    return sumaElementowTablicy;
}
int main()
{
    //********** wczytywanie wejscia
    int wielkoscTablicy;
    int liczbaOperacji;
    cin >> wielkoscTablicy >> liczbaOperacji;
    //int tablicaLiczb[wielkoscTablicy];
    int *tablicaLiczb = new int[wielkoscTablicy];
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        cin >> tablicaLiczb[i];
    }
    int sumaElementowTablicy = ZliczaSumeLiczbPoObcieciu(tablicaLiczb, wielkoscTablicy, liczbaOperacji);
    cout << sumaElementowTablicy;
    return 0;
}