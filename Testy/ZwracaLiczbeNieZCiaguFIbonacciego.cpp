#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef unsigned long int uilong2;
uilong2 WczytajWejscie()
{
    uilong2 liczba;
    cin >> liczba;
    return liczba;
}
bool SprawdzaCzyLiczbeDaSieStworzycZCiaguFibonacciego(uilong2 szukanaLiczba, uilong2 listaLiczbFibonacciego[], int wielkoscTablicy)
{
    uilong2 sumaLiczbFibonacciego = 0;
    int j = 0;
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        if (sumaLiczbFibonacciego == szukanaLiczba)
            return true;
        if (sumaLiczbFibonacciego < szukanaLiczba)
            sumaLiczbFibonacciego = sumaLiczbFibonacciego + listaLiczbFibonacciego[i];
        else
        {
            sumaLiczbFibonacciego = sumaLiczbFibonacciego - listaLiczbFibonacciego[j];
            j++;
        }
    }
    return false;
}

int main()
{
    uilong2 szukanaLiczba = WczytajWejscie();
    int wielkoscTablicy = 50;
    uilong2 listaLiczbFibonacciego[wielkoscTablicy];
    listaLiczbFibonacciego[0] = 1;
    listaLiczbFibonacciego[1] = 1;
    for (int i = 2; i < wielkoscTablicy; i++)
    {
        listaLiczbFibonacciego[i] = listaLiczbFibonacciego[i - 1] + listaLiczbFibonacciego[i - 2];
    }
    for (uilong2 sprawdzanaLiczbaWiekszaOdPoczatkowej = szukanaLiczba + 1; sprawdzanaLiczbaWiekszaOdPoczatkowej < listaLiczbFibonacciego[wielkoscTablicy - 1]; sprawdzanaLiczbaWiekszaOdPoczatkowej++)
    {
        bool CzyLiczbeDaSieStworzyc = SprawdzaCzyLiczbeDaSieStworzycZCiaguFibonacciego(sprawdzanaLiczbaWiekszaOdPoczatkowej, listaLiczbFibonacciego, wielkoscTablicy);
        if (!CzyLiczbeDaSieStworzyc)
        {
            cout << sprawdzanaLiczbaWiekszaOdPoczatkowej;
            break;
        }
    }
    return 0;
}
