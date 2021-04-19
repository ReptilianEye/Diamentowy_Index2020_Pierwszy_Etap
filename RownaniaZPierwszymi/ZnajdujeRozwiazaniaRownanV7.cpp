#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int LicznikRozwiazanSpelniajacychWarunek = 0;

//template for generic type 
template<typename K, typename V> 
  
//Hashnode class 
class HashNode 
{ 
    public: 
    V value; 
    K key; 
      
    //Constructor of hashnode  
    HashNode(K key, V value) 
    { 
        this->value = value; 
        this->key = key; 
    } 
}; 
  
//template for generic type 
template<typename K, typename V> 
  
//Our own Hashmap class 
class HashMap 
{ 
    //hash element array 
    HashNode<K,V> **arr; 
    int capacity; 
    //current size 
    int size; 
    //dummy node 
    HashNode<K,V> *dummy; 
  
    public: 
    HashMap() 
    { 
        //Initial capacity of hash array 
        capacity = 2500*10; 
        size=0; 
        arr = new HashNode<K,V>*[capacity]; 
          
        //Initialise all elements of array as NULL 
        for(int i=0 ; i < capacity ; i++) 
            arr[i] = NULL; 
          
        //dummy node with value and key -1 
        dummy = new HashNode<K,V>(-1, -1); 
    } 
    // This implements hash function to find index 
    // for a key 
    int hashCode(K key) 
    { 
        return key % capacity; 
    } 
      
    //Function to add key value pair 
    void insertNode(K key, V value) 
    { 
        HashNode<K,V> *temp = new HashNode<K,V>(key, value); 
          
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
          
        //find next free space  
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
               && arr[hashIndex]->key != -1) 
        { 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //if new node to be inserted increase the current size 
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
            size++; 
        arr[hashIndex] = temp; 
    } 
      
    //Function to delete a key value pair 
    V deleteNode(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
          
        //finding the node with given key 
        while(arr[hashIndex] != NULL) 
        { 
            //if node found 
            if(arr[hashIndex]->key == key) 
            { 
                HashNode<K,V> *temp = arr[hashIndex]; 
                  
                //Insert dummy node here for further use 
                arr[hashIndex] = dummy; 
                  
                // Reduce size 
                size--; 
                return temp->value; 
            } 
            hashIndex++; 
            hashIndex %= capacity; 
  
        } 
          
        //If not found return null 
        return NULL; 
    } 
      
    //Function to search the value for a given key 
    V get(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
        int counter=0; 
        //finding the node with given key    
        while(arr[hashIndex] != NULL) 
        {    int counter =0; 
             if(counter++>capacity)  //to avoid infinite loop 
                return NULL;         
            //if node found return its value 
            if(arr[hashIndex]->key == key) 
                return arr[hashIndex]->value; 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //If not found return null 
        return NULL; 
    } 
      
    //Return current size  
    int sizeofMap() 
    { 
        return size; 
    } 
      
    //Return true if size is 0 
    bool isEmpty() 
    { 
        return size == 0; 
    } 
      
    //Function to display the stored key value pairs 
    void display() 
    { 
        for(int i=0 ; i<capacity ; i++) 
        { 
            if(arr[i] != NULL && arr[i]->key != -1) 
                cout << "key = " << arr[i]->key  
                     <<"  value = "<< arr[i]->value << endl; 
        } 
    } 
}; 
 









class Hash
{
    int BUCKET; // No. of buckets

    // Pointer to an array containing buckets
    list<ll> *table;

public:
    Hash(int V); // Constructor

    // inserts a key into hash table
    void insertItem(ll x);

    // deletes a key from hash table
    void deleteItem(ll key);

    // hash function to map values to key
    int hashFunction(ll x)
    {
        return (x % BUCKET);
    }

    void displayHash();
    bool contains(ll key);
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<ll>[BUCKET];
}

void Hash::insertItem(ll key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(ll key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (inex)th list
    list<ll>::iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

bool Hash::contains(ll key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (inex)th list
    list<ll>::iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++)
    {
        if (*i == key)
            return true;
    }
    return false;
}

Hash HashQ(2500 * 10);
HashMap<ll, ll> HashQ2;


ll modulo(ll base, ll e, ll mod)
{
    ll a = 1;
    ll b = base;
    while (e > 0)
    {
        if (e % 2 == 1)
            a = (a * b) % mod;
        b = (b * b) % mod;
        e = e / 2;
    }
    return a % mod;
}
bool Fermat(ll m, int iterations)
{
    if (m == 1)
    {
        return false;
    }
    for (int i = 0; i < iterations; i++)
    {
        ll x = rand() % (m - 1) + 1;
        if (modulo(x, m - 1, m) != 1)
        {
            return false;
        }
    }
    return true;
}
bool CzyTaLiczbaJestLiczbaPierwszaOptymalnie(long liczba)
{

    if (liczba < 2)
        return false;
    if (liczba == 2 || liczba == 3)
        return true;
    if (liczba % 3 == 0)
        return false;
    long wielokrotnosc = 6;
    long pierwiastek = sqrt(liczba);
    while (wielokrotnosc - 1 <= pierwiastek)
    {
        if (liczba % (wielokrotnosc + 1) == 0 || liczba % (wielokrotnosc - 1) == 0)
            return false;
        wielokrotnosc = wielokrotnosc + 6;
    }
    return true;
}
bool ZnajdzWZakresieBinarnie(int l, int p, int Tablica[], int poszukiwana)
{
    int sr;
    while (l <= p)
    {
        sr = (l + p) / 2;
        if (Tablica[sr] == poszukiwana)
        {
            return true;
        }
        if (Tablica[sr] > poszukiwana)
            p = sr - 1;
        else
            l = sr + 1;
    }
    return false;
}
void SprawdzKombinacje(int TablicaQ[], int gornyZakres)
{
    ll A = TablicaQ[0];
    ll maksymalnaWartosc = TablicaQ[gornyZakres];
    int Bi = 0;
    while (Bi < gornyZakres && A + (TablicaQ[Bi] * 3) <= maksymalnaWartosc)
    {
        ll B = TablicaQ[Bi];
        int Ci = Bi;
        while (Ci < gornyZakres && A + B + (TablicaQ[Ci] * 2 <= maksymalnaWartosc))
        {
            ll C = TablicaQ[Ci];
            int Di = Ci;
            while (Di < gornyZakres && A + B + C + TablicaQ[Di] <= maksymalnaWartosc)
            {

                ll D = TablicaQ[Di];
                ll suma = A + B + C + D;
                if (HashQ2.get(suma)!=NULL)
                {
                    LicznikRozwiazanSpelniajacychWarunek++;
                }
                Di++;
            }
            Ci++;
        }
        Bi++;
    }
}
int main()
{
    //********** wczytywanie wejscia
    int gornyZakres;
    int D;
    cin >> gornyZakres >> D;
    //************ Znajdywanie Liczb Pierwszych
    // ********** Wczytywanie tablicy liczb pierwszych
    int liczbaPotrzebnychLiczbPierwszych = gornyZakres + D;
    if (D == 0)
    {
        cout << 0;
        return 0;
    }
    int TablicaLiczbPierwszych[liczbaPotrzebnychLiczbPierwszych];
    int iloscZnalezionychLiczbPierwszych = 1;
    TablicaLiczbPierwszych[0] = 2;
    int i = 3;
    while (iloscZnalezionychLiczbPierwszych < liczbaPotrzebnychLiczbPierwszych)
    {
        if (Fermat(i, 1))
        {
            if (CzyTaLiczbaJestLiczbaPierwszaOptymalnie(i))
            {
                TablicaLiczbPierwszych[iloscZnalezionychLiczbPierwszych] = i;
                iloscZnalezionychLiczbPierwszych++;
            }
        }
        i = i + 2;
    }
    // ******** Wczytywanie tablicy Q
    int TablicaQ[gornyZakres];
    gornyZakres--;
    for (int i = 0; i <= gornyZakres; i++)
    {
        TablicaQ[i] = TablicaLiczbPierwszych[i] * TablicaLiczbPierwszych[i + D];
        //HashQ.insertItem(TablicaQ[i]);
        HashQ2.insertNode(TablicaQ[i],TablicaQ[i]);
    }
    SprawdzKombinacje(TablicaQ, gornyZakres);
    cout << LicznikRozwiazanSpelniajacychWarunek << endl;
    return 0;
}