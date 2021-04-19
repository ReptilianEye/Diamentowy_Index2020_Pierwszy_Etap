#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void KolorujeLabirynt(char **Labirynt, int X, int Y, char znak)
{
    Labirynt[X][Y] = znak;
    if (Labirynt[X + 1][Y] == '.')
    {
        KolorujeLabirynt(Labirynt, X + 1, Y, znak);
    }
    if (Labirynt[X][Y + 1] == '.')
    {
        KolorujeLabirynt(Labirynt, X, Y + 1, znak);
    }
    if (Labirynt[X - 1][Y] == '.')
    {
        KolorujeLabirynt(Labirynt, X - 1, Y, znak);
    }
    if (Labirynt[X][Y - 1] == '.')
    {
        KolorujeLabirynt(Labirynt, X, Y - 1, znak);
    }
    return;
}
int main()
{
    //********** wczytywanie wejscia
    int liczbaWierszy;
    int liczbaKolumn;
    cin >> liczbaWierszy >> liczbaKolumn;
    liczbaWierszy++;
    liczbaKolumn++;
    char **Labirynt = new char *[liczbaKolumn + 3];
    for (int i = 0; i < liczbaKolumn + 3; i++)
        Labirynt[i] = new char[liczbaWierszy + 3];

    for (int i = 0; i <= liczbaWierszy; i++)
        Labirynt[i][0] = '#';
    for (int i = 0; i <= liczbaKolumn; i++)
        Labirynt[0][i] = '#';

    for (int i = 0; i <= liczbaWierszy; i++)
        Labirynt[i][liczbaKolumn] = '#';
    for (int i = 0; i <= liczbaKolumn; i++)
        Labirynt[liczbaWierszy][i] = '#';

    for (int i = 1; i < liczbaWierszy; i++)
    {
        for (int j = 1; j < liczbaKolumn; j++)
            cin >> Labirynt[i][j];
    }

    Labirynt[0][1] = 'P';
    Labirynt[1][0] = 'P';
    Labirynt[liczbaWierszy][liczbaKolumn - 1] = 'K';
    Labirynt[liczbaWierszy - 1][liczbaKolumn] = 'K';
    //Koloruje od poczatku
    if (Labirynt[1][1] == '.') //oblozenie jesli w naroznikach bylaby slaba sciana
        KolorujeLabirynt(Labirynt, 1, 1, 'P');
    //Koloruje od konca
    if (Labirynt[liczbaWierszy - 1][liczbaKolumn - 1] == '.')
        KolorujeLabirynt(Labirynt, liczbaWierszy - 1, liczbaKolumn - 1, 'K');

    int LicznikSlabychScian = 0;
    for (int i = 1; i < liczbaWierszy; i++)
    {
        for (int j = 1; j < liczbaKolumn; j++)
        {
            if (Labirynt[i][j] == '#')
            {
                if ((Labirynt[i + 1][j] == 'P' || Labirynt[i - 1][j] == 'P' || Labirynt[i][j + 1] == 'P' || Labirynt[i][j - 1] == 'P') && (Labirynt[i + 1][j] == 'K' || Labirynt[i - 1][j] == 'K' || Labirynt[i][j + 1] == 'K' || Labirynt[i][j - 1] == 'K'))
                {
                    LicznikSlabychScian++;
                    Labirynt[i][j] = '*';
                }
            }
        }
    }
    cout << LicznikSlabychScian;
    return 0;
}