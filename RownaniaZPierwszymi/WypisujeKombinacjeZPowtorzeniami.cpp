#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

void CombinationRepetitionUtil(int chosen[], int arr[], int index, int r, int start, int end)
{
    // Since index has become r, current combination is
    // ready to be printed, print
    if (index == r)
    {
        int suma = 0;
        for (int i = 0; i < r; i++)
        {
            cout << arr[chosen[i]] << " ";
        }
        cout << endl;
        return;
    }
    // One by one choose all elements (without considering
    // the fact whether element is already chosen or not)
    // and recur
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        CombinationRepetitionUtil(chosen, arr, index + 1, r, i, end);
    }
    return;
}

// in arr[] of size n with repitions. This function mainly
// uses CombinationRepetitionUtil()
void CombinationRepetition(int arr[], int n, int r)
{
    int *chosen = new int[r + 1];

    CombinationRepetitionUtil(chosen, arr, 0, r, 0, n - 1);
}

int main() // Testy
{
    int dlugoscListy = 4;
    int arr[dlugoscListy];
    for (int i = 0; i < dlugoscListy; i++)
        arr[i] = i;
    int r = 3;
    CombinationRepetition(arr, dlugoscListy, r);
    return 0;
}
