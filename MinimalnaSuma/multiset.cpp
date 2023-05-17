#include <iostream> 
#include <set> 
#include <iterator> 
  
using namespace std; 
  
int main() 
{ 
    // empty multiset container 
    multiset <int, greater <int>> mset;         
  
    // insert elements in random order 
    mset.insert(40); 
    mset.insert(30); 
    mset.insert(60); 
    mset.insert(20); 
    mset.insert(50); 
    mset.insert(50); // 50 will be added again to the multiset unlike set 
    mset.insert(10); 


   cout << "first element is : " << *(mset.begin()) << endl;
   cout << "last element is : " << *(mset.rbegin()) << endl;

   cout << "The size multiset gquiz1 is : " << mset.size() << endl;
        for (auto itr = mset.begin(); itr != mset.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 

    mset.erase(--mset.end());
    mset.insert(31);
    cout << "first elemet is : " << *(mset.begin()) << endl;
   cout << "last element is : " << *(mset.rbegin()) << endl;
   cout << "The size multiset gquiz1 is : " << mset.size() << endl;
        for (auto itr = mset.begin(); itr != mset.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 


    cout << endl;
}
