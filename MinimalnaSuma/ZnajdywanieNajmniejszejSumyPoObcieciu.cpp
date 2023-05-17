#include <iostream>
#include <string>
#include <iterator>
#include <set>
#include <cstdlib>

using namespace std;

long sumaWszystkich = 0;
void ZliczaSumeLiczbPoObcieciu(multiset<int> ListaLiczb, int wielkoscTablicy, int liczbaOperacji)
{
    multiset<int, greater<int>> mset;

    for (int i = 0; i < liczbaOperacji; i++)
    {
        if (*(ListaLiczb.rbegin()) % 2 == 1)
            sumaWszystkich--;
        int OIleOdejmujemy = float(*(ListaLiczb.rbegin()) / 2);
        ListaLiczb.erase(--ListaLiczb.end());
        ListaLiczb.insert(OIleOdejmujemy);
        sumaWszystkich = sumaWszystkich - OIleOdejmujemy;
        if (sumaWszystkich == 0)
            break;
    }
}

int main()
{
    //********** wczytywanie wejscia
    int wielkoscTablicy;
    int liczbaOperacji;
    cin >> wielkoscTablicy >> liczbaOperacji;
    multiset<int> ListaLiczb;
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        int WkladanaLiczba;
        cin >> WkladanaLiczba;
        if (i < liczbaOperacji)
            ListaLiczb.insert(WkladanaLiczba);
        else if (WkladanaLiczba > *(ListaLiczb.begin()))
        {
            ListaLiczb.erase(*(ListaLiczb.begin()));
            ListaLiczb.insert(WkladanaLiczba);
        }
        sumaWszystkich = sumaWszystkich + WkladanaLiczba;
    }
    ZliczaSumeLiczbPoObcieciu(ListaLiczb, wielkoscTablicy, liczbaOperacji);
    cout << sumaWszystkich << endl;
    return 0;
}