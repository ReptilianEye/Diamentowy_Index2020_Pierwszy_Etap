#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fcntl.h>

using namespace std;

int main()
{
    _setmode(_fileno(stdout), _O_TEXT);
    srand((unsigned)time(NULL));
    int wielkoscTablicy = 1000000;
    int *tablicaLiczb = new int [wielkoscTablicy];
    int k = rand() % 1000000;
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        tablicaLiczb[i] = (rand()*rand()) % 1000000000;
    }
    cout << wielkoscTablicy << " " << k << endl;
    for (int i = 0; i < wielkoscTablicy; i++)
    {
        cout << tablicaLiczb[i] << " ";
    }
    return 0;
}
