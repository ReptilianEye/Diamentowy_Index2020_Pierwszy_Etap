#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <regex>

using namespace std;

string ZwracaZdekompresowanyPodciag(string skompresowanyCiag)
{
    string rozkompresowanyCiag = "";
    string powtarzanyPodstring = "";
    int iloscPowtorki = skompresowanyCiag[1] -'0';
    powtarzanyPodstring = skompresowanyCiag.substr(2, skompresowanyCiag.length() - 3);
    for (int j = 0; j < iloscPowtorki; j++)
    {
        rozkompresowanyCiag = rozkompresowanyCiag + powtarzanyPodstring;
    }
    return rozkompresowanyCiag;
}
string ZwracaZdekompresowanyCiag(string ciag)
{
    regex rx(R"(\[\d[a-z]+\])");
    while (true)
    {
        if (!regex_search(ciag, rx))
            return ciag;
        else
        {
            smatch znaleziony;
            regex_search(ciag,znaleziony,rx);
            auto skompresowanyCiag = znaleziony[0].str();
            auto rozkompresowanyCiag = ZwracaZdekompresowanyPodciag(skompresowanyCiag);
            ciag = regex_replace(ciag, rx, rozkompresowanyCiag,regex_constants::format_first_only);
        }
    }
}
int main()
{
    string ciag;
    cin >> ciag;
    //ciag = "a[2c[2zx]c[2pr]]";
    auto rozkompresowanyCiag = ZwracaZdekompresowanyCiag(ciag);
    cout << rozkompresowanyCiag;
    cout << endl;
        
    return 0;
}