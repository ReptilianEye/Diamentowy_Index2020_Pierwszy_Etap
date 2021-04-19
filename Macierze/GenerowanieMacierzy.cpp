#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int wymiaryMacierzy = 1000;
    int liczbaOperacji = 10;
    int **Macierz = new int *[wymiaryMacierzy];
    for (int i = 0; i < wymiaryMacierzy; i++)
        Macierz[i] = new int[wymiaryMacierzy];
    int liczba = 1;
    for (int i = 0; i < wymiaryMacierzy; i++)
    {
        for (int j = 0; j < wymiaryMacierzy; j++)
            Macierz[i][j] = liczba++;
    }
    cout << wymiaryMacierzy << " " << liczbaOperacji << endl;
    for (int i = 0; i < wymiaryMacierzy; i++)
    {
        for (int j = 0; j < wymiaryMacierzy; j++)
            cout << Macierz[i][j] << " ";
        cout << endl;
    }

    return 0;
}