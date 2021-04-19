#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void WypisujeInstrukcjeMacierzy(int **Macierz, int wielkoscMacierzy, int liczbaOperacji)
{
    string operacja;
    int rotacja = 0;
    int oIleObrocona = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < liczbaOperacji; i++)
    {
        cin >> operacja;
        if (operacja == "A") // rotacja
        {
            cin >> rotacja;
            oIleObrocona = oIleObrocona + (rotacja / 90);
            continue;
        }
        if (operacja == "Q") // query
        {
            cin >> x >> y;
            if (oIleObrocona % 4 == 0)
                cout << Macierz[x][y] << endl;
            if (oIleObrocona % 4 == 1)
                cout << Macierz[wielkoscMacierzy - 1 - y][x] << endl;
            if (oIleObrocona % 4 == 2)
                cout << Macierz[wielkoscMacierzy - 1 - x][wielkoscMacierzy - 1 - y] << endl;
            if (oIleObrocona % 4 == 3)
                cout << Macierz[y][wielkoscMacierzy - 1 - x] << endl;
            continue;
        }
        if (operacja == "U") //Update
        {
            int wartoscNaZmiane;
            cin >> x >> y >> wartoscNaZmiane;
            Macierz[x][y] = wartoscNaZmiane;
            continue;
        }
    }
}
int main()
{
    //********** wczytywanie wejscia
    int wymiaryMacierzy;
    int liczbaOperacji;
    cin >> wymiaryMacierzy >> liczbaOperacji;
    int **Macierz = new int *[wymiaryMacierzy];
    for (int i = 0; i < wymiaryMacierzy; i++)
        Macierz[i] = new int[wymiaryMacierzy];
    for (int i = 0; i < wymiaryMacierzy; i++)
    {
        for (int j = 0; j < wymiaryMacierzy; j++)
            cin >> Macierz[i][j];
    }
    WypisujeInstrukcjeMacierzy(Macierz, wymiaryMacierzy, liczbaOperacji);
    return 0;
}